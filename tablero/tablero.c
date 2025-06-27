//
// Created by pruden on 27/06/25.
//

#include "tablero.h"

#include <stdio.h>

#include "globales.h"

void imprimir_celda(int valor);

void imprimir_tablero() {
    printf("\033[H\033[J");
    printf("\n");
    printf("              🐍 SNAKE EN C 🐍\n\n");

    for (int i = 0; i < FILAS; i++) {
        printf("  ");
        for (int j = 0; j < COLUMNS; j++) {
            imprimir_celda(tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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

void imprimir_celda(int valor) {
    switch (valor) {
        case CAS_0:
            printf("\033[48;5;26m  \033[0m");  // Azul intermedio
            break;
        case CAS_1:
            printf("\033[48;5;32m  \033[0m");  // Azul mediano
            break;
        case SERPIENTE_CUERPO:
            printf("\033[48;5;34m  \033[0m");  // Verde pasto
            break;
        case SERPIENTE_CABEZA:
            printf("\033[48;5;46m  \033[0m");  // Verde lima
            break;
        case COMIDA:
            printf("\033[48;5;196m  \033[0m");  // Rojo vibrante
            break;
        default:
            printf("??");
            break;
    }
}

