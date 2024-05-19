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
#include "sort.h"

int main(){

    CDataframe *dataframe = create_dataframe();

    remplir_dataframe(dataframe);

    print_index(dataframe->colonnes[0]);
    sort(dataframe->colonnes[0],1);
    print_index(dataframe->colonnes[0]);
    afficher_dataframe(dataframe);

    return 0;
}