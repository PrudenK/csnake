//
// Created by pruden on 27/06/25.
//

#include "tablero.h"

#include <stdio.h>

#include "globales.h"

void imprimir_tablero() {
    for (int i= 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d", tablero[i][j]);
        }
        printf("\n");
    }
}

void cargar_tablero() {
    for (int i= 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    tablero[i][j] = CAS_0;
                }else {
                    tablero[i][j] = CAS_1;
                }
            }else {
                if (j % 2 == 0) {
                    tablero[i][j] = CAS_1;
                }else {
                    tablero[i][j] = CAS_0;
                }
            }
        }
    }
}