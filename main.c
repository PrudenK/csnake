//
// Created by pruden on 27/06/25.
//

#include <stdio.h>

#include "globales.h"
#include "tablero.h"


int tablero[FILAS][COLUMNS] = {0};

int main() {
    cargar_tablero();
    imprimir_tablero();

    printf("HOLAAAA");
    return 0;
}
