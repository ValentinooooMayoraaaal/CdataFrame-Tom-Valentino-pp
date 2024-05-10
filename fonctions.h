//
// Created by tombo on 27/03/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#define CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H

#endif //CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 256

// Structure pour représenter une colonne
typedef struct {
    char *titre;
    int *donnees;
    size_t taille_physique;
    size_t taille_logique;
} COLUMN;

//Prototype fonction qui insert un evaleur dans une colonne
COLUMN *create_column(char *title);

//Prototype fonction pour free de l'espace pris par unu colonne
int insert_value(COLUMN *col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int x_occurence(COLUMN* col, int x);

int value_on_x_position(COLUMN* col, int x);

int number_sup_to_x(COLUMN* col, int x);

int number_inf_to_x(COLUMN* col, int x);

int number_equ_to_x(COLUMN* col, int x);

