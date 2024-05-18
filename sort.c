//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "column.h"
#include "cdataframe.h"

void sort(COLUMN* col, int sort_dir) {
    if(sort_dir == 0){
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
    }
    else if(sort_dir == 1){
        if (col->valid_index == 0) {
            printf("algorithme quicksort décroissant \n");
            // Algorithme Quicksort
            Quicksort_decroissant(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            printf("algorithme insertion décroissant \n");
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

// Fonction de partition pour Quicksort
int Partition_croissant(COLUMN *col, int gauche, int droite) {
    int pivot = col->donnees[droite];
    int i = gauche - 1;
    for (int j = gauche; j <= droite - 1; j++) {
        if (col->donnees[j] <= pivot) {
            i++;
            int c = col->donnees[i];
            col->donnees[i] = col->donnees[j];
            col->donnees[j] = c;
        }
    }
    int c = col->donnees[i + 1];
    col->donnees[i + 1] = col->donnees[droite];
    col->donnees[droite] = c;
    return i + 1;
}

int Partition_decroissant(COLUMN *col, int gauche, int droite) {
    int pivot = col->donnees[droite];
    int i = gauche - 1;
    for (int j = gauche; j <= droite - 1; j++) {
        if (col->donnees[j] >= pivot) {
            i++;
            int c = col->donnees[i];
            col->donnees[i] = col->donnees[j];
            col->donnees[j] = c;
        }
    }
    int c = col->donnees[i + 1];
    col->donnees[i + 1] = col->donnees[droite];
    col->donnees[droite] = c;
    return i + 1;
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
