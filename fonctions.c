//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Column *create_column(char *title) {
    Column *col = (col*) malloc(sizeof(Column));

    col->titre = title;
    col->donnees = NULL; // pointeur sur le tableau
    col->taille_physique = 256;
    col->taille_logique = 0;
    free(col);
    return col;
}
