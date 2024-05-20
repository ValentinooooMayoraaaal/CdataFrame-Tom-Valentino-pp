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


COLUMN *create_column(char *title);

int insert_value(COLUMN *colonne, int valeur);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int x_occurence(COLUMN* col, int x);

int value_on_x_position(COLUMN* col, int x);

int number_sup_to_x(COLUMN* col, int x);

int number_inf_to_x(COLUMN* col, int x);

int number_equ_to_x(COLUMN* col, int x);

void supprimer_valeur(CDataframe *dataframe, int indice_colonne, int indice_valeur);

COLUMN *colonne_taille_max(CDataframe *dataframe);

void erase_index(COLUMN *col);

int check_index(COLUMN *col);

void print_col_by_index(COLUMN *col);

#endif //CDATAFRAME_TOM_VALENTINO_PP_COLUMN_H
