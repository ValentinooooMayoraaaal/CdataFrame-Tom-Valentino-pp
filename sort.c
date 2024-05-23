//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cdataframe.h"
#include "column.h"
#include "sort.h"

//Ce fichier sort.c est composé de toutes les fonctions nécessaires au tri d'une colonne. Elle a été réalisée par Tom Boyer et
//Valentino Mayoral.


int choice_column(CDataframe * dataframe) {
    int choice_column;
    printf("Quelle colonne du dataframe souhaitez vous triez ?\n");
    scanf("La colonne a trier est la colonne %d", &choice_column);
    printf("Veuillez patientez.\n");
    choice_column -=1;
    return choice_column;
}

int choice_dir(){
    int sort_dir;
    printf("Si vous souhaitez trier votre colonne dans l'ordre croisant, tapez 0.\n");
    printf("Si vous souhaitez trier votre colonne dans l'ordre decroissant, tapez 1.\n");
    scanf("%d", &sort_dir);
    while(sort_dir !=0 && sort_dir != 1){
        printf("Vous devez saisir soit 0 ou 1.");
        scanf("%d", &sort_dir);
    }
    return sort_dir;
}

void sort(COLUMN* col, int sort_dir) {
    if (sort_dir == 0) {
        if (col->valid_index == 0) {
            printf("Application de l'algorithme de tri quicksort croissant \n");
            // Algorithme Quicksort
            Quicksort_croissant(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            printf("Application de l'algorithme de tri algorithme insertion croissant \n");
            for (int i = 1; i < col->taille_logique; i++) {
                int k = col->index[i];
                int j = i - 1;
                while (j >= 0 && col->donnees[j] > k) {
                    col->index[j + 1] = col->index[j];
                    j--;
                }
                col->index[j + 1] = k;
            }
        }
    } else if(sort_dir == 1){
        if (col->valid_index == 0) {
            printf("Application de l'algorithme de tri algorithme quicksort decroissant \n");
            // Algorithme Quicksort
            Quicksort_decroissant(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            printf("Application de l'algorithme de tri algorithme insertion decroissant \n");
            for (int i = 1; i < col->taille_logique; i++) {
                int k = col->index[i];
                int j = i - 1;
                while (j >= 0 && col->donnees[j] > k) {
                    col->index[j + 1] = col->index[j];
                    j--;
                }
                col->index[j + 1] = k;
            }
        }
    }
    col->valid_index=1;
}

int Partition_croissant(COLUMN *col, int gauche, int droite) {
    int pivot = col->donnees[col->index[droite]];
    int i = gauche - 1;

    for (int j = gauche; j <= droite - 1; j++) {
        if (col->donnees[col->index[j]] <= pivot) {
            i++;
            int temp = col->index[i];
            col->index[i] = col->index[j];
            col->index[j] = temp;
        }
    }
    int temp = col->index[i + 1];
    col->index[i + 1] = col->index[droite];
    col->index[droite] = temp;

    return i + 1;
}

int Partition_decroissant(COLUMN *col, int gauche, int droite) {
    int pivot = col->donnees[col->index[droite]];
    int i = gauche - 1;

    for (int j = gauche; j <= droite - 1; j++) {
        if (col->donnees[col->index[j]] >= pivot) {
            i++;
            int temp = col->index[i];
            col->index[i] = col->index[j];
            col->index[j] = temp;
        }
    }
    int temp = col->index[i + 1];
    col->index[i + 1] = col->index[droite];
    col->index[droite] = temp;

    return i + 1;
}

void Quicksort_croissant(COLUMN *col, int gauche, int droite) {
    if (gauche < droite) {
        int pi = Partition_croissant(col, gauche, droite);
        Quicksort_croissant(col, gauche, pi - 1);
        Quicksort_croissant(col, pi + 1, droite);
    }
}

void Quicksort_decroissant(COLUMN *col, int gauche, int droite) {
    if (gauche < droite) {
        int pi = Partition_decroissant(col, gauche, droite);
        Quicksort_decroissant(col, gauche, pi - 1);
        Quicksort_decroissant(col, pi + 1, droite);
    }
}
//fonction supplémentaire qui permet d'afficher la colonne d'index provenant d'une colonne donnée en paramètre. Elle ne
//retourne rien.
void print_index(COLUMN* col){
    for(int i=0; i < col->taille_logique; i++){
        printf("[%d] %d\n",i,col->index[i]);
    }
}

void print_col_by_index(COLUMN *col){
    int i;
    printf("Voici le resultat de votre tableau trie : \n");
    for(i=0;i<col->taille_logique;i++){
        printf("Valeur : %d\n", col->donnees[col->index[i]]);
    }
}

