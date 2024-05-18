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
#include "cdataframe.h"
#include "column.h"

int main(){

    CDataframe *dataframe = create_dataframe();

    remplir_dataframe(dataframe);

    sort(dataframe->colonnes[0], 0);

    afficher_dataframe(dataframe);

    return 0;
}