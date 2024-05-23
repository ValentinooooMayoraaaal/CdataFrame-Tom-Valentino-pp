//
// Created by tombo on 16/05/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_COLUMN_H
#define CDATAFRAME_TOM_VALENTINO_PP_COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BLOCK_SIZE 256

// Structure pour représenter une colonne
typedef struct {
    char *titre;
    int *donnees;
    size_t taille_physique;
    size_t taille_logique;
    unsigned long long *index;
    int valid_index;
    unsigned int index_size;
    int sort_dir;
} COLUMN;

typedef struct {
    COLUMN **colonnes;
    int nb_colonnes;

} CDataframe;


// Crée une nouvelle colonne avec un titre spécifique.
COLUMN *create_column(char *title);

// Insère une valeur dans la colonne donnée.
int insert_value(COLUMN *colonne, int valeur);

// Supprime une colonne et libère la mémoire.
void delete_column(COLUMN **col);

// Affiche le contenu complet de la colonne.
void print_col(COLUMN* col);

// Retourne le nombre d'occurrences d'une valeur spécifique dans la colonne.
int x_occurence(COLUMN* col, int x);

// Retourne la valeur à la position spécifique dans la colonne.
int value_on_x_position(COLUMN* col, int x);

// Retourne le nombre de valeurs supérieures à une valeur spécifique dans la colonne.
int number_sup_to_x(COLUMN* col, int x);

// Retourne le nombre de valeurs inférieures à une valeur spécifique dans la colonne.
int number_inf_to_x(COLUMN* col, int x);

// Retourne le nombre de valeurs égales à une valeur spécifique dans la colonne.
int number_equ_to_x(COLUMN* col, int x);

// Supprime une valeur spécifique d'une colonne dans le dataframe.
void supprimer_valeur(CDataframe *dataframe, int indice_colonne, int indice_valeur);

// Retourne une nouvelle colonne contenant les tailles maximales des éléments dans chaque colonne du dataframe.
COLUMN *colonne_taille_max(CDataframe *dataframe);

// Efface l'index de la colonne.
void erase_index(COLUMN *col);

// Vérifie l'index de la colonne.
int check_index(COLUMN *col);

// Affiche le contenu de la colonne en utilisant l'index.
void print_col_by_index(COLUMN *col);

#endif //CDATAFRAME_TOM_VALENTINO_PP_COLUMN_H
