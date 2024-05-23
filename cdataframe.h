//
// Created by tombo on 16/05/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_CDATAFRAME_H
#define CDATAFRAME_TOM_VALENTINO_PP_CDATAFRAME_H

//
// Created by tombo on 16/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BLOCK_SIZE 256
#include "column.h"
// Structure pour représenter une colonne


// Crée un nouveau dataframe vide.
CDataframe *create_dataframe();

// Remplit le dataframe avec des valeurs.
void remplir_dataframe(CDataframe *dataframe);

// Remplit le dataframe avec des valeurs prédéfinies.
void remplir_dataframe_en_dur(CDataframe *dataframe);

// Affiche le contenu complet du dataframe.
void afficher_dataframe(CDataframe *dataframe);

// Affiche une partie des lignes du dataframe.
void afficher_dataframe_partiel_ligne(CDataframe *dataframe);

// Affiche une partie des colonnes du dataframe.
void afficher_dataframe_partiel_colonne(CDataframe *dataframe);

<<<<<<< HEAD
void ajouter_ligne_Cdataframe(CDataframe *dataframe, int *ligne);

=======
// Supprime une ligne spécifique du dataframe.
>>>>>>> 4f7034c319fc69595f5b0032729bbe4a1f15ba78
void supprimer_ligne(CDataframe *dataframe, int indice_ligne);

// Ajoute une nouvelle colonne au dataframe.
void ajouter_colonne(CDataframe *dataframe, int indice_colonne, char *titre);

// Supprime une colonne spécifique du dataframe.
void supprime_colonne_du_dataframe(CDataframe *dataframe, int indice_colonne);

// Renomme une colonne spécifique du dataframe.
void renommer_colonne(CDataframe *dataframe, int indice_colonne, char *nouveau_titre);

// Vérifie si une valeur existe dans le dataframe.
bool check_value_existing(CDataframe *dataframe, int valeur);

// Modifie la valeur d'une cellule spécifique dans le dataframe.
void modifier_valeur_cellule(CDataframe *dataframe, int indice_ligne, int indice_colonne, int nouvelle_valeur);

// Affiche le nombre de colonnes dans le dataframe et le retourne.

int print_number_column(CDataframe *dataframe);

// Affiche le nombre d'occurrences d'une valeur spécifique dans le dataframe.
void occurence_x_in_dataframe(CDataframe *dataframe);

// Affiche le nombre d'occurrences des valeurs supérieures à une valeur spécifique dans le dataframe.
void occurence_number_sup_to_x_in_dataframe(CDataframe *dataframe);

// Affiche le nombre d'occurrences des valeurs inférieures à une valeur spécifique dans le dataframe.
void occurence_number_inf_to_x_in_dataframe(CDataframe *dataframe);

// Recherche une valeur spécifique dans une colonne donnée du dataframe.
int search_value_in_column(COLUMN *col, void *val);


#endif //CDATAFRAME_TOM_VALENTINO_PP_CDATAFRAME_H
