//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        titre[strcspn(titre, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne

        // Création d'une nouvelle colonne avec le titre saisi par l'utilisateur
        dataframe->colonnes[i] = create_column(titre);

        // Saisie des valeurs pour la colonne
        printf("Saisissez les valeurs pour la colonne %s (entrez -1 pour terminer) :\n", titre);
        while (1) {
            printf("Valeur : ");
            scanf("%d", &valeur);
            if (valeur == -1) {
                break; // Terminer la saisie lorsque l'utilisateur entre -1
            }
            insert_value(dataframe->colonnes[i], valeur);
        }
        getchar(); // Consommer le caractère de nouvelle ligne après la saisie de la dernière valeur
    }

    dataframe->nb_colonnes = nb_colonnes; // Mettre à jour le nombre de colonnes dans le CDataframe
}

void remplir_dataframe_en_dur(CDataframe *dataframe) {

    const char *titres[] = {"Colonne1", "Colonne2", "Colonne3"};

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

        printf("\n"); // Ligne vide entre les colonnes pour la lisibilité
    }
}