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