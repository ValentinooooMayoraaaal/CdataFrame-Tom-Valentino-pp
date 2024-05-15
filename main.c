//
// Created by tombo on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <string.h>

int main(){

    CDataframe *dataframe = create_dataframe();

    remplir_dataframe(dataframe);

    afficher_dataframe_partiel_colonne(dataframe);


    return 0;
}