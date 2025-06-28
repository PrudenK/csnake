cmake_minimum_required(VERSION 3.16)
project(CSnake C)

set(CMAKE_C_STANDARD 11)

add_executable(CSnake
        main.c
        contantes/globales.h
        tablero/tablero.c
        tablero/tablero.h
        snake/serpiente.c
        snake/serpiente.h
        teclado/teclado.c
        teclado/teclado.h
        manzanas/generar_manzanas.c
        manzanas/generar_manzanas.h
)

include_directories(
        tablero
        contantes
        snake
        teclado
        manzanas
)