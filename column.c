//
// Created by tombo on 16/05/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"

COLUMN *create_column(char *title) {
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));

    // Allocation de mémoire pour le titre et copie du titre
    col->titre = (char*)malloc(strlen(title) + 1);
    strcpy(col->titre, title);

    col->donnees = NULL;
    col->taille_physique = 0;
    col->taille_logique = 0;
    col->index = NULL;
    col->valid_index = -1;
    col->index_size = 0;
    col->sort_dir = 0;

    return col;
}

int insert_value(COLUMN *colonne, int valeur) {
    // Vérifier si une allocation est nécessaire dans le cas ou la colonne est vide ou pleine
    if(colonne->taille_physique == 0){
        colonne->donnees = malloc(sizeof(int));
        colonne->index = malloc(sizeof(int));
    }
    else if(colonne->taille_physique !=0){
        colonne->donnees = realloc(colonne->donnees, colonne->taille_physique * sizeof(int));
        colonne->index = realloc(colonne->index, colonne->taille_physique * sizeof(int));
    }
    colonne->donnees[colonne->taille_physique] = valeur;
    colonne->index[colonne->taille_physique] = colonne->taille_physique;
    colonne->taille_physique += 1;
    if(colonne->valid_index == 1){
        colonne->valid_index = -1;
    }
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

