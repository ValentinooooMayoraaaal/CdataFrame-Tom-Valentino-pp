//
// Created by tombo on 27/03/2024.
//

#include <stdbool.h>
#include <string.h>
#include "cdataframe.h"
#include "column.h"

int main(){

    CDataframe *dataframe = create_dataframe();

    remplir_dataframe(dataframe);


    return 0;
}