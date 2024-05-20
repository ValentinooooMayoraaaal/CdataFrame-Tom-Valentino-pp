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

void sort(COLUMN* col, int sort_dir);

int Partition_croissant(COLUMN *col, int gauche, int droite);

int Partition_decroissant(COLUMN *col, int gauche, int droite);

void Quicksort_croissant(COLUMN *col, int gauche, int droite);

void Quicksort_decroissant(COLUMN *col, int gauche, int droite);

void print_index(COLUMN* col);

int choice_dir();

int choice_column();

void print_col_by_index(COLUMN *col);