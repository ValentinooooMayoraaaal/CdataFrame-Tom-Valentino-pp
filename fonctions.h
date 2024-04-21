//
// Created by tombo on 27/03/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#define CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H

#endif //CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>


// Structure pour représenter une colonne
typedef struct {
    char *titre;
    int *donnees;
    size_t taille_physique;
    size_t taille_logique;
} Column;

Column *create_column(char *title);
