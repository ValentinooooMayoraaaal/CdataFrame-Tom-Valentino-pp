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
    col->index = 0;
    col->valid_index = -1;
    col->index_size = 0;
    col->sort_dir = 0;

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
    if(colonne->valid_index = 1){
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

//Sort est une fonction de tri qui fonctionne grâce à deux autres fonction : Quickshort, elle-même qui se sert de Partition.
//Sort trie différement en fonction de la situation.
// Il existe 4 situations possibles.
// Si sort_dir = 1 est saisie, tri décroissant. Si sort_dir = 0, tri croissant.
// Si valid_index = -1, on exécute le tri d'insertion et si valid_index =0, on éxecute le quickshort.
// Il y a donc quatre situation : croissant quickshort, croissant insertion, décroissant quickshort, décroissant insertion.
//Les quatre fonctionnent ;)
//Pour le réaliser, j'ai codé le pseudo-code du CM.
// Chatgpt m'a été utile pour comprendre ce que signifiait "gauche" et "droite" indices de Quickshort et pouvoir comprendre que gauche = 0 etc.

void sort(COLUMN* col, int sort_dir) {
    if(sort_dir = 0){
        if (col->valid_index == 0) {
            printf("%d", col->valid_index);
            // Algorithme Quicksort
            Quicksort(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            for (int i = 1; i < col->taille_logique; i++) {
                int k = col->donnees[i];
                int j = i - 1;
                while (j >= 0 && col->donnees[j] > k) {
                    col->donnees[j + 1] = col->donnees[j];
                    j--;
                }
                col->donnees[j + 1] = k;
            }
        }
    }
    else if(sort_dir = 1){
        if (col->valid_index == 0) {
            printf("%d", col->valid_index);
            // Algorithme Quicksort
            Quicksort(col, 0, col->taille_logique - 1);
        } else if (col->valid_index == -1) {
            // Algorithme de tri par insertion
            for (int i = 1; i < col->taille_logique; i++) {
                int k = col->donnees[i];
                int j = i - 1;
                while (j >= 0 && col->donnees[j] < k) {
                    col->donnees[j + 1] = col->donnees[j];
                    j--;
                }
                col->donnees[j + 1] = k;
            }
        }
    }
    col->valid_index=1;
}

// Fonction de partition pour Quicksort
int Partition(COLUMN *col, int gauche, int droite) {
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
}


void Quicksort(COLUMN *col, int gauche, int droite) {
    if (gauche < droite) {
        int pi = Partition(col, gauche, droite);
        Quicksort(col, gauche, pi - 1);
        Quicksort(col, pi + 1, droite);
    }
}

