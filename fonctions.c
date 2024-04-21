//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

Column *create_column(char *title) {
    Column *col = (Column*)malloc(sizeof(Column));

    col->titre = title;
    col->donnees = NULL; // pointeur sur le tableau
    col->taille_physique = 256;
    col->taille_logique = 0;
    free(col);
    return col;
}

int insert_value(Column *colonne, int valeur) {
    // Vérifier si une allocation est nécessaire dans le cas ou la colonne est vide ou pleine
    if (colonne->taille_physique == 0 || colonne->taille_logique == colonne->taille_physique) {
        size_t nouvelle_taille = colonne->taille_physique + BLOCK_SIZE;
        int *nouveau_tableau = realloc(colonne->donnees, nouvelle_taille * sizeof(int));
        if (nouveau_tableau == NULL) {
            printf("Erreur lors de la réallocation de mémoire\n");
            return 0; // 0 pour indiquer une erreur
        }
        colonne->donnees = nouveau_tableau;
        colonne->taille_physique = nouvelle_taille;
    }

    // Insertion de la valeur
    colonne->donnees[colonne->taille_logique] = valeur;
    colonne->taille_logique++;

    return 1; //succes de l'insertion de la valeur dans la colonne
}
