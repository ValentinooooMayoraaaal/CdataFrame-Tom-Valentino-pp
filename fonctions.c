//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fonctions.h"

COLUMN *create_column(char *title) {
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));

    // Allocation de mémoire pour le titre et copie du titre
    col->titre = (char*)malloc(strlen(title) + 1);
    strcpy(col->titre, title);

    col->donnees = NULL;
    col->taille_physique = 0;
    col->taille_logique = 0;

    return col;
}

int insert_value(COLUMN *colonne, int valeur) {
    // Vérifier si une allocation est nécessaire dans le cas ou la colonne est vide ou pleine
    if(colonne->taille_physique == 0){
        colonne->donnees = malloc(sizeof(int));
    }
    else if(colonne->taille_physique !=0){
        colonne->donnees = realloc(colonne->donnees, colonne->taille_physique * sizeof(int));
    }
    colonne->donnees[colonne->taille_physique] = valeur;
    colonne->taille_physique += 1;
    return 1; //succes de l'insertion de la valeur dans la colonne
}

void delete_column(COLUMN **col){
    free(col);
}

void print_col(COLUMN* col){
    if(col->donnees!=NULL){
        for(int i=0; i < col->taille_logique; i++){
            printf("[%d] %d",i,col->donnees[i]);
            printf("\n");
        }
    }
}

int x_occurence(COLUMN* col, int x){
    int cpt = 0;
    for(int i = 0; i<col->taille_logique; i++){
        if(col->donnees[i]==x){
            cpt = cpt +1;
        }
    }
    printf("La valeur saisie est présente %d fois dans la colonne.", cpt);
    return cpt;
}

int value_on_x_position(COLUMN* col, int x){
    if(col->taille_physique > x && x>=0){
        printf("La valeur à la %dème position est %d.", x, col->donnees[x-1]);
        return col->donnees[x];
    }
    else{
        printf("La position %d n'existe pas dans la colonne.");
    }
}

int number_sup_to_x(COLUMN* col, int x){
    int cpt = 0;
    for(int i=0; i<col->taille_logique; i++){
        if(col->donnees[i]>x){
            cpt++;
        }
    }
    printf("Il y a %d valeurs supérieures à %d dans la colonne.", cpt,x);
    return cpt;
}

int number_inf_to_x(COLUMN* col, int x){
    int cpt = 0;
    for(int i=0; i<col->taille_logique; i++){
        if(col->donnees[i]<x){
            cpt++;
        }
    }
    printf("Il y a %d valeurs inférieures à %d dans la colonne.", cpt,x);
    return cpt;
}

int number_equ_to_x(COLUMN* col, int x){
    int cpt = 0;
    for(int i=0; i<col->taille_logique; i++){
        if(col->donnees[i]==x){
            cpt++;
        }
    }
    printf("Il y a %d valeurs égales à %d dans la colonne.", cpt,x);
    return cpt;
}
void supprimer_valeur(CDataframe *dataframe, int indice_colonne, int indice_valeur) {

    if (indice_colonne < 0 || indice_colonne >= dataframe->nb_colonnes) {
        printf("Indice de colonne invalide\n");
        return;
    }

    COLUMN *colonne = dataframe->colonnes[indice_colonne];


    if (indice_valeur < 0 || indice_valeur >= colonne->taille_logique) {
        printf("Indice de valeur invalide pour la colonne\n");
        return;
    }


    for (int i = indice_valeur; i < colonne->taille_logique - 1; i++) {
        colonne->donnees[i] = colonne->donnees[i + 1];
    }
    colonne->taille_logique--; // Décrémente la taille logique
}
CDataframe *create_dataframe() {
    CDataframe *dataframe = malloc(sizeof(CDataframe));

    dataframe->colonnes = NULL; // Initialisation du tableau de colonnes à NULL
    dataframe->nb_colonnes = 0;

    return dataframe;
}

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

        // Saisie des valeurs pour la colonne
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
void ajouter_ligne_Cdataframe(CDataframe *dataframe, int *ligne) {
    if (dataframe->nb_colonnes > 0 && ligne != NULL) {
        for (int i = 0; i < dataframe->nb_colonnes; i++) {
            insert_value(dataframe->colonnes[i], ligne[i]);
        }
    } else {
        printf("Erreur");
    }
}

COLUMN *colonne_taille_max(CDataframe *dataframe) {
    if (dataframe->nb_colonnes == 0) {
        printf("Le CDataframe est vide\n");
        return NULL;
    }

    COLUMN *colonne_max = dataframe->colonnes[0];

    for (int i = 1; i < dataframe->nb_colonnes; i++) {
        if (dataframe->colonnes[i]->taille_logique > colonne_max->taille_logique) {
            colonne_max = dataframe->colonnes[i];
        }
    }
    return colonne_max;
}

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

void afficher_noms_colonnes(CDataframe *dataframe) {
    printf("Noms des colonnes :\n");
    for (int i = 0; i < dataframe->nb_colonnes; i++) {
        printf("Colonne numéro %d: %s\n", i + 1, dataframe->colonnes[i]->titre);
    }
}
//4.1
int print_number_column(CDataframe *dataframe){
    int number_column;
    number_column = dataframe->nb_colonnes;
    printf("Notre dataframe contient %d colonnes", number_column);
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

