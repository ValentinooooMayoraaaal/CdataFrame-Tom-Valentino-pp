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

// Structure pour représenter une colonne
typedef struct {
    char *titre;
    int *donnees;
    size_t taille_physique;
    size_t taille_logique;
} COLUMN;

typedef struct {
    COLUMN **colonnes;
    int nb_colonnes;
} CDataframe;


CDataframe *create_dataframe();

void remplir_dataframe(CDataframe *dataframe);

void remplir_dataframe_en_dur(CDataframe *dataframe);

void afficher_dataframe(CDataframe *dataframe);

void afficher_dataframe_partiel_ligne(CDataframe *dataframe);

void afficher_dataframe_partiel_colonne(CDataframe *dataframe);

void supprimer_ligne(CDataframe *dataframe, int indice_ligne);

void ajouter_colonne(CDataframe *dataframe, int indice_colonne, char *titre);

void supprime_colonne_du_dataframe(CDataframe *dataframe, int indice_colonne);

void renommer_colonne(CDataframe *dataframe, int indice_colonne, char *nouveau_titre);

bool check_value_existing(CDataframe *dataframe, int valeur);

void modifier_valeur_cellule(CDataframe *dataframe, int indice_ligne, int indice_colonne, int nouvelle_valeur);
//4.1
int print_number_column(CDataframe *dataframe);

void occurence_x_in_dataframe(CDataframe *dataframe);

void occurence_number_sup_to_x_in_dataframe(CDataframe *dataframe);

void occurence_number_inf_to_x_in_dataframe(CDataframe *dataframe);


#endif //CDATAFRAME_TOM_VALENTINO_PP_CDATAFRAME_H
