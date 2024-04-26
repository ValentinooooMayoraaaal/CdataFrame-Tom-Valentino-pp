//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <string.h>
int main() {
    Column *mycol = create_column("My column");
    int val = 5;
    if (insert_value(mycol, val))
        printf("Valeur ajoutee avec succes a ma colonne\n");
    else
        printf("Erreur lors de l'ajout de la valeur a ma colonne\n");
    return 0;
}


