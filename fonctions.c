//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Column *create_column(char *title) {
    Column *colonne = (colonne*) malloc(sizeof(Column));

    colonne->titre = title;
    colonne->donnees = NULL; // pointeur sur le tableau
    colonne->taille_physique = 256;
    colonne->taille_logique = 0;
    free(colonne);
    return colonne;
}
