//
// Created by tombo on 27/03/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#define CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H

#endif //CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TITRE 50
#define VALEUR_DEFAUT 0 // Valeur par défaut pour les données manquantes (dans cet exemple, on suppose des entiers)

// Structure pour une colonne de données
typedef struct {
    char titre[TAILLE_TITRE];
    int *donnees;
    int taille;
} Colonne;

// Structure pour le DataFrame
typedef struct {
    Colonne *colonnes;
    int nb_colonnes;
    int nb_lignes;
} CDataframe;
