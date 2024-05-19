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

//Sort est une fonction de tri qui fonctionne grâce à deux autres fonction : Quickshort, elle-même qui se sert de Partition.
//Sort trie différement en fonction de la situation.
// Il existe 4 situations possibles.
// Si sort_dir = 1 est saisie, tri décroissant. Si sort_dir = 0, tri croissant.
// Si valid_index = -1, on exécute le tri d'insertion et si valid_index =0, on éxecute le quickshort.
// Il y a donc quatre situation : croissant quickshort, croissant insertion, décroissant quickshort, décroissant insertion.
//Les quatre fonctionnent ;)
//Pour le réaliser, j'ai codé le pseudo-code du CM.
void sort(COLUMN* col, int sort_dir) {
    if (sort_dir == 0) {
        if (col->valid_index == 0) {
            printf("check");
            printf("algorithme quicksort croissant \n");
            // Algorithme Quicksort
            Quicksort_croissant(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            printf("algorithme insertion croissant \n");
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
            printf("algorithme quicksort decroissant \n");
            // Algorithme Quicksort
            Quicksort_decroissant(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            printf("algorithme insertion decroissant \n");
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

// Fonction de partition pour Quicksort croissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne une valeur i+1 utile dans le tri quicksort.
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
// Fonction de partition pour Quicksort décroissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne une valeur i+1 utile dans le tri quicksort.
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
// Fonction Quicksort croissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne rien.
void Quicksort_croissant(COLUMN *col, int gauche, int droite) {
    if (gauche < droite) {
        int pi = Partition_croissant(col, gauche, droite);
        Quicksort_croissant(col, gauche, pi - 1);
        Quicksort_croissant(col, pi + 1, droite);
    }
}

// Fonction Quicksort décroissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne rien.
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