//
// Created by tombo on 16/05/2024.
//

#ifndef CDATAFRAME_TOM_VALENTINO_PP_SORT_H
#define CDATAFRAME_TOM_VALENTINO_PP_SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "column.h"
#endif //CDATAFRAME_TOM_VALENTINO_PP_SORT_H


//Fonction qui avait pour but de choisir la colonne à trier mais malgré son fonctionnement et sa justesse syntaxique, elle
//fait planter le code lors de son éxecution. Cette erreur reste un mystère.
int choice_column(CDataframe * dataframe);

//FOnction sans paramètre qui a pour but de retourner la valeur de sort_dir qui permet de savoir si le tri doit être
//croissant ou décroissant.
int choice_dir();

//Sort est une fonction de tri qui fonctionne grâce à deux autres fonction : Quickshort, elle-même qui se sert de Partition.
//Sort trie différement en fonction de la situation.
// Il existe 4 situations possibles.
// Si sort_dir = 1 est saisie, tri décroissant. Si sort_dir = 0, tri croissant.
// Si valid_index = -1, on exécute le tri d'insertion et si valid_index =0, on éxecute le quickshort.
// Il y a donc quatre situation : croissant quickshort, croissant insertion, décroissant quickshort, décroissant insertion.
//Les quatre fonctionnent ;)
//Pour le réaliser, j'ai codé le pseudo-code du CM.
void sort(COLUMN* col, int sort_dir);

// Fonction de partition pour Quicksort croissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne une valeur i+1 utile dans le tri quicksort.
int Partition_croissant(COLUMN *col, int gauche, int droite);

// Fonction de partition pour Quicksort décroissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne une valeur i+1 utile dans le tri quicksort.
int Partition_decroissant(COLUMN *col, int gauche, int droite);

// Fonction Quicksort croissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne rien.
void Quicksort_croissant(COLUMN *col, int gauche, int droite);

// Fonction Quicksort décroissant qui prend en paramètre une colonne et deux bornes gauche et droite.
//Elle retourne rien.
void Quicksort_decroissant(COLUMN *col, int gauche, int droite);

//fonction supplémentaire qui permet d'afficher la colonne d'index provenant d'une colonne donnée en paramètre. Elle ne
//retourne rien.
void print_index(COLUMN* col);

void print_col_by_index(COLUMN *col);