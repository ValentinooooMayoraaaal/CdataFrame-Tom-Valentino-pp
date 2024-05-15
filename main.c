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

    occurence_number_inf_to_x_in_dataframe(dataframe);

    occurence_number_sup_to_x_in_dataframe(dataframe);


    return 0;
}