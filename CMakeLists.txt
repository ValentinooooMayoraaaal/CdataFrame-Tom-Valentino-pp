cmake_minimum_required(VERSION 3.27)
project(CdataFrame_Tom_Valentino_pp C)

set(CMAKE_C_STANDARD 11)

add_executable(CdataFrame_Tom_Valentino_pp
                main.c
        cdataframe.h
        column.c
        cdataframe.c
        list.c
        sort.c
        list.h
        sort.h)
