//
// Created by pruden on 28/06/25.
//

#include "generar_manzanas.h"

#include <stdlib.h>

#include "globales.h"

void generar_manzana() {
    do {
        manzana_x = rand() % FILAS;
        manzana_y = rand() % COLUMNS;
    }while (tablero[manzana_x][manzana_y] == SERPIENTE_CABEZA || tablero[manzana_x][manzana_y] == SERPIENTE_CUERPO);

    tablero[manzana_x][manzana_y] = MANZANA;
}

