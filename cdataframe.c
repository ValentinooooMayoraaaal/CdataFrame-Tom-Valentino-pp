//
// Created by tombo on 16/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdataframe.h"
#include "column.h"

#include <stdbool.h>

//Ce fichier cdataframe.c est composé de toutes les fonctions qui touchent à l'utilisation du dataframe.
// Elle a été réalisée par Tom Boyer et Valentino Mayoral.


//Fonction sans paramètre qui sert à créer un dataframe. On lui donne de l'espace dans la mémoire et on le définie avec
// des composantes en dur. Elle retourne le dataframe en question.

CDataframe *create_dataframe() {
    CDataframe *dataframe = malloc(sizeof(CDataframe));

    dataframe->colonnes = NULL; // Initialisation du tableau de colonnes à NULL
    dataframe->nb_colonnes = 0;

    return dataframe;
}
//Une fonction qui sert à remplir un dataframe mis en paramètre. Le dataframe est un paramètre modifié qui à la fin de la
// fonction aura été modifié. Elle ne retourne rien.
void remplir_dataframe(CDataframe *dataframe) {
    char titre[100]; // Chaine de caractère pour le titre de la colonne
    int valeur;      // Variable pour les valeurs stocker dans chaque colonne

    printf("Combien de colonnes souhaitez-vous ajouter ? ");
    int nb_colonnes;
    scanf("%d", &nb_colonnes);
    getchar(); // Consommer le caractère de nouvelle ligne

    // Allocation dynamique du tableau de pointeurs vers des colonnes
    dataframe->colonnes = malloc(nb_colonnes * sizeof(COLUMN *));

    // Boucle pour ajouter chaque colonne
    for (int i = 0; i < nb_colonnes; i++) {
        printf("Titre de la colonne %d : ", i + 1);
        fgets(titre, sizeof(titre), stdin);
        titre[strcspn(titre, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
        int cpt = 0;
        // Création d'une nouvelle colonne avec le titre saisi par l'utilisateur
        dataframe->colonnes[i] = create_column(titre);

        // Saisie des valeurs pour la colonne.
        printf("Saisissez les valeurs pour la colonne %s (entrez -1 pour terminer) :\n", titre);
        while (1) {
            printf("Valeur : ");
            scanf("%d", &valeur);
            cpt++;
            if (valeur == -1) {
                break; // Terminer la saisie lorsque l'utilisateur entre -1
            }
            insert_value(dataframe->colonnes[i], valeur);

        }
        getchar();// Consommer le caractère de nouvelle ligne après la saisie de la dernière valeur
        dataframe->colonnes[i]->taille_logique = cpt-1;
    }

    dataframe->nb_colonnes = nb_colonnes; // Mettre à jour le nombre de colonnes dans le CDataframe
}
//Cette fonction permet de remplir un dataframe mis en paramètre, en dur. Elle ne retourne rien.
void remplir_dataframe_en_dur(CDataframe *dataframe) {

    char *titres[] = {"Colonne1", "Colonne2", "Colonne3"};

    const int donnees[][3] = {
            {10, 20, 30},
            {40, 50, 60},
            {70, 80, 90}
    };

    const int nb_colonnes = 3;
    const int nb_lignes = 3;

    dataframe->colonnes = malloc(nb_colonnes * sizeof(COLUMN *));

    for (int i = 0; i < nb_colonnes; i++) {
        dataframe->colonnes[i] = create_column(titres[i]);

        for (int j = 0; j < nb_lignes; j++) {
            insert_value(dataframe->colonnes[i], donnees[i][j]);
        }
    }

    dataframe->nb_colonnes = nb_colonnes; // Mats à jour le nombre de colonnes dans le CDataframe
}
//Cette fonction sert d'affichage des cellules d'un dataframe mis en paramètre à l'aide de printf. Elle ne retourn rien.
void afficher_dataframe(CDataframe *dataframe) {
    // Parcours de chaque colonne du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        printf("Colonne \"%s\":\n", dataframe->colonnes[i]->titre);
        printf("---------\n");

        // Affichage des valeurs de la colonne
        for (int j = 0; j < dataframe->colonnes[i]->taille_logique; j++) {
            printf("%d\n", dataframe->colonnes[i]->donnees[j]);
        }

        printf("\n"); // Ligne vide
    }
}
//Cette fonction sert à afficher la ligne d'un dataframe mis en paramètre. Elle ne retourne rien.
void afficher_dataframe_partiel_ligne(CDataframe *dataframe){
    int taille;
    printf("Pour chaque colonne, combien de ligne faut-il afficher ? : ");
    scanf("%d",&taille);
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        printf("Colonne \"%s\":\n", dataframe->colonnes[i]->titre);
        printf("---------\n");
        // Affichage des valeurs de la colonne
        for (int j = 0; j < taille; j++) {
            printf("%d\n", dataframe->colonnes[i]->donnees[j]);
        }
        printf("\n"); // Ligne vide entre les colonnes pour la lisibilité
    }
}
//Cette fonction sert à afficher une colonne d'un dataframe mis en paramètre. Elle ne retourne rien.
void afficher_dataframe_partiel_colonne(CDataframe *dataframe){
    int taille;
    printf("Combien de colonne faut-il afficher ? : ");
    scanf("%d",&taille);
    for (int i = 0; i < taille; i++) {
        printf("Colonne \"%s\":\n", dataframe->colonnes[i]->titre);
        printf("---------\n");
        // Affichage des valeurs de la colonne
        for (int j = 0; j < dataframe->colonnes[i]->taille_logique; j++) {
            printf("%d\n", dataframe->colonnes[i]->donnees[j]);
        }
        printf("\n"); // Ligne vide entre les colonnes pour la lisibilité
    }
}
//Cette fonction sert à ajouter une ligne au dataframe mis en paramètre, au numéro de ligne donné aussi en paramètre.
// Elle ne retourne rien.

void ajouter_ligne_Cdataframe(CDataframe *dataframe, int *ligne) {
    if (dataframe->nb_colonnes > 0 && ligne != NULL) {
        for (int i = 0; i < dataframe->nb_colonnes; i++) {
            insert_value(dataframe->colonnes[i], ligne[i]);
        }
    } else {
        printf("Erreur");
    }
}


//Cette fonction permet de supprimer une ligne donnée en paramètre du dataframe mis aussi en paramètre. Elle ne retourne
//rien.
void supprimer_ligne(CDataframe *dataframe, int indice_ligne) {
    // Vérifier si l'indice de la ligne est valide
    // et si l'indice de la ligne est valide pour la colonne ayant la taille logique maximale
    if (indice_ligne < 0 || indice_ligne >= colonne_taille_max(dataframe)->taille_logique) {
        fprintf(stderr, "Indice de ligne invalide\n");
        return;
    }

    // Parcourir toutes les colonnes du CDataframe et supprimer la valeur à l'indice donné
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        supprimer_valeur(dataframe, i, indice_ligne);
    }

    // Parcourir toutes les colonnes du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        // Supprimer la valeur à l'indice donné dans la colonne i
        supprimer_valeur(dataframe, i, indice_ligne);
    }
}
//Cette fonction sert à ajouter une colonne au dataframe mis en paramètre, au numéro de colonne donné aussi en paramètre.
// Elle ne retourne rien.
void ajouter_colonne(CDataframe *dataframe, int indice_colonne, char *titre) {
    // Vérifier si l'indice de la colonne est valide
    if (indice_colonne < 0 || indice_colonne > dataframe->nb_colonnes) {
        printf("Indice de colonne invalide\n");
        return;
    }

    // Réallouer de la mémoire pour la nouvelle collonnes
    dataframe->colonnes = realloc(dataframe->colonnes, (dataframe->nb_colonnes + 1) * sizeof(COLUMN *));

    // Décaler les colonnes suivantes vers la droite
    for (int i = dataframe->nb_colonnes; i > indice_colonne; i--) {
        dataframe->colonnes[i] = dataframe->colonnes[i - 1];
    }

    // Créer une nouvelle colonne avec le titre donné
    dataframe->colonnes[indice_colonne] = create_column(titre);

    dataframe->nb_colonnes++; // Incrémenter le nombre de colonnes dans le CDataframe
}
//Cette fonction sert à supprimer une colonne au dataframe mis en paramètre, au numéro de colonne donné aussi en paramètre.
// Elle ne retourne rien.
void supprime_colonne_du_dataframe(CDataframe *dataframe, int indice_colonne) {
    // Vérifier si l'indice de la colonne est valide
    if (indice_colonne < 0 || indice_colonne >= dataframe->nb_colonnes) {
        printf("Indice de colonne invalide\n");
        return;
    }

    // Libére la mémoire de la colonne à supprimer
    delete_column(&(dataframe->colonnes[indice_colonne]));

    // Décale toutes les colonnes suivantes vers la gauche
    for (int i = indice_colonne; i < dataframe->nb_colonnes - 1; i++) {
        dataframe->colonnes[i] = dataframe->colonnes[i + 1];
    }

    // Ici, on réalloue une taille plus petite dans colonnes
    dataframe->colonnes = realloc(dataframe->colonnes, (dataframe->nb_colonnes - 1) * sizeof(COLUMN *));
    dataframe->nb_colonnes--; // Ceci décrémente le nombre de colonnes dans le CDataframe
}
//Cette fonction sert à renommer une colonne au dataframe mis en paramètre, au numéro de colonne donné aussi en paramètre.
// Elle ne retourne rien.
void renommer_colonne(CDataframe *dataframe, int indice_colonne, char *nouveau_titre) {
    // Vérifie si l'indice de la colonne est valide
    if (indice_colonne < 0 || indice_colonne >= dataframe->nb_colonnes) {
        printf("Indice de colonne invalide\n");
        return;
    }

    // Libére la mémoire de l'ancien titre de la colonne
    free(dataframe->colonnes[indice_colonne]->titre);

    // Alloue de la mémoire pour le nouveau titre et le copie
    dataframe->colonnes[indice_colonne]->titre = strdup(nouveau_titre); //stdrup() est une fonction qui crée une cpine de la chaine entré en argument

}

//Cette fonction permet de vérifier si une valeur donnée en paramètre est dans une des cellules du dataframe aussi en paramètre.
bool check_value_existing(CDataframe *dataframe, int valeur) {
    // Parcoure toutes les colonnes du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        COLUMN *colonne = dataframe->colonnes[i];
        // Parcoure toutes les valeurs de la colonne
        for (int j = 0; j < colonne->taille_logique; j++) {
            // Vérifie si la valeur existe dans la colonne
            if (colonne->donnees[j] == valeur) {
                return true; // Vraie si la valeur existe
            }
        }
    }
    return false; // Sinon renvoit faux
}

void modifier_valeur_cellule(CDataframe *dataframe, int indice_ligne, int indice_colonne, int nouvelle_valeur) {
    if (indice_ligne < 0) {
        printf("Indice de ligne invalide\n");
        return;
    }

    if (indice_colonne < 0 || indice_colonne >= dataframe->nb_colonnes) {
        printf("Indice de colonne invalide\n");
        return;
    }
    //On crée un pointeur sur une colonne et on le fait pointer sur la colonne à l'indice donné
    COLUMN *colonne = dataframe->colonnes[indice_colonne];
    if (indice_ligne < 0 || indice_ligne >= colonne->taille_logique) {
        printf("Indice de ligne invalide pour la colonne\n");
        return;
    }

    // Remplace la valeur
    colonne->donnees[indice_ligne] = nouvelle_valeur;
}
//Cette fonction sert à afficher les noms de chaque colonne d'un dataframe mis en paramètre. Elle ne retourne rien.
void afficher_noms_colonnes(CDataframe *dataframe) {
    printf("Noms des colonnes :\n");
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        printf("Colonne numéro %d: %s\n", i + 1, dataframe->colonnes[i]->titre);
    }
}

int print_number_column(CDataframe *dataframe){
    int number_column;
    number_column = dataframe->nb_colonnes;
    printf("Notre dataframe contient %d colonnes", number_column);
    return number_column;
}

int nombre_lignes(CDataframe *dataframe) {
    COLUMN *colonne_max = colonne_taille_max(dataframe); // Obtenir la colonne avec la taille logique maximale

    if (colonne_max == NULL) {
        printf("Le CDataframe est vide\n");
        return 0;
    }

    // Retourner la taille logique de la colonne avec la taille maximale
    return colonne_max->taille_logique;
}
//Cette fonction affiche le nombre d'occurence d'une valeur x dans un dataframe mis en paramètre. Elle ne retourne rien.
void occurence_x_in_dataframe(CDataframe *dataframe) {
    printf("Saisissez une valeur x pour avoir son nombre d'occurence dans le dataframes :");
    int x;
    scanf("%d", &x);
    int cpt = 0;
    // Parcours de chaque colonne du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        // Affichage des valeurs de la colonne
        for (int j = 0; j < dataframe->colonnes[i]->taille_logique; j++) {
            if(x==dataframe->colonnes[i]->donnees[j] ){
                cpt++;
            };
        }
        printf("\n"); // Ligne vide
    }
    printf("%d apparait %d fois dans le dataframe.", x,cpt);
}

void occurence_number_sup_to_x_in_dataframe(CDataframe *dataframe) {
    printf("Saisissez une valeur x pour avoir son nombre d'occurence dans le dataframes :");
    int x;
    scanf("%d", &x);
    int cpt = 0;
    // Parcours de chaque colonne du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        // Affichage des valeurs de la colonne
        for (int j = 0; j < dataframe->colonnes[i]->taille_logique; j++) {
            if(x<dataframe->colonnes[i]->donnees[j] ){
                cpt++;
            };
        }
        printf("\n"); // Ligne vide
    }
    printf("Il y a %d valeurs supérieur à %d dans le dataframe.", cpt,x);
}
//Cette fonction affiche le nombre d'occurence des valeurs inférieurs à x dans un dataframe mis en paramètre. Elle ne retourne rien.

void occurence_number_inf_to_x_in_dataframe(CDataframe *dataframe) {
    printf("Saisissez une valeur x pour avoir son nombre d'occurence dans le dataframes :");
    int x;
    scanf("%d", &x);
    int cpt = 0;
    // Parcours de chaque colonne du CDataframe
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        // Affichage des valeurs de la colonne
        for (int j = 0; j < dataframe->colonnes[i]->taille_logique; j++) {
            if(x>dataframe->colonnes[i]->donnees[j] ){
                cpt++;
            };
        }
        printf("\n"); // Ligne vide
    }
    printf("Il y a %d valeurs inférieur à %d dans le dataframe.", cpt,x);
}

int search_value_in_column(COLUMN *col, void *val) {
    if (col->valid_index != 1) {
        // La colonne n'est pas triée
        return -1;
    }

    int value = *(int *)val; // Convertir le pointeur de valeur en entier
    int gauche = 0;
    int droite = col->taille_logique - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        int index_milieu = col->index[milieu];
        int valeur_milieu = col->donnees[index_milieu];

        if (valeur_milieu == value) {
            return 1; // Valeur trouvée
        }

        if (col->sort_dir == 0) {
            // Tri croissant
            if (valeur_milieu < value) {
                gauche = milieu + 1;
            } else {
                droite = milieu - 1;
            }
        } else {
            // Tri décroissant
            if (valeur_milieu > value) {
                gauche = milieu + 1;
            } else {
                droite = milieu - 1;
            }
        }
    }

    return 0; // Valeur non trouvée
}