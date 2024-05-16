//
// Created by tombo on 27/03/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
#define CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H

#endif //CDATAFRAME_TOM_VALENTINO_PP_FONCTIONS_H
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

void supprimer_valeur(CDataframe *dataframe, int indice_colonne, int indice_valeur);
//---------------------------------------------------------------------------------------------//


CDataframe *create_dataframe();

void remplir_dataframe(CDataframe *dataframe);

void remplir_dataframe_en_dur(CDataframe *dataframe);

void afficher_dataframe(CDataframe *dataframe);

void afficher_dataframe_partiel_ligne(CDataframe *dataframe);

void afficher_dataframe_partiel_colonne(CDataframe *dataframe);

void ajouter_ligne_Cdataframe(CDataframe *dataframe, int *ligne);

void supprimer_ligne(CDataframe *dataframe, int indice_ligne);

void ajouter_colonne(CDataframe *dataframe, int indice_colonne, char *titre);

void supprime_colonne_du_dataframe(CDataframe *dataframe, int indice_colonne);

void renommer_colonne(CDataframe *dataframe, int indice_colonne, char *nouveau_titre);

bool check_value_existing(CDataframe *dataframe, int valeur);

void modifier_valeur_cellule(CDataframe *dataframe, int indice_ligne, int indice_colonne, int nouvelle_valeur);

void afficher_noms_colonnes(CDataframe *dataframe);

int print_number_ligne(CDataframe *dataframe);

COLUMN *colonne_taille_max(CDataframe *dataframe);//Fonction pas demandé mais utile pour print_number_ligne() et supprimer_ligne()

void occurence_x_in_dataframe(CDataframe *dataframe);

void occurence_number_sup_to_x_in_dataframe(CDataframe *dataframe);

void occurence_number_inf_to_x_in_dataframe(CDataframe *dataframe);


