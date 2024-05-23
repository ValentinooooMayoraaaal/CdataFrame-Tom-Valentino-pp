//
// Created by tombo on 27/03/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include <stdbool.h>
#include <string.h>
#include "sort.h"

int main(){

    CDataframe *dataframe = create_dataframe();

    remplir_dataframe(dataframe);

    afficher_dataframe(dataframe);

    afficher_dataframe_partiel_ligne(dataframe);

    occurence_number_sup_to_x_in_dataframe(CDataframe *dataframe);

    check_index(dataframe->colonnes[0]);

    return 0;
}