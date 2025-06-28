//
// Created by pruden on 27/06/25.
//

#include "serpiente.h"

#include <stdio.h>
#include <stdlib.h>

#include "tablero.h"
#include "teclado.h"

void inicializar_serpiente() {
    int medio_x = COLUMNS / 2;
    int medio_y = FILAS / 2;

    for (int i = 0; i < tama_serpiente; i++) {
        serpiente[i].x = medio_x - i;
        serpiente[i].y = medio_y;
        tablero[medio_y][medio_x - i] = (i == 0) ? SERPIENTE_CABEZA : SERPIENTE_CUERPO;
    }
}

void mover_serpiente() {
    Coordenada nueva_cabeza = serpiente[0];

    switch (direc) {
        case 'W': nueva_cabeza.y--; break;
        case 'S': nueva_cabeza.y++; break;
        case 'A': nueva_cabeza.x--; break;
        case 'D': nueva_cabeza.x++; break;
    }

    // Mover el cuerpo
    for (int i = tama_serpiente - 1; i > 0; i--) {
        serpiente[i] = serpiente[i - 1];
    }

    serpiente[0] = nueva_cabeza;

    cargar_tablero();

    for (int i = 0; i < tama_serpiente; i++) {
        int x = serpiente[i].x;
        int y = serpiente[i].y;

        if (x < 0 || x >= COLUMNS || y < 0 || y >= FILAS) {
            restaurar_terminal();
            printf("GAME OVER!\n");
            exit(1);
        }

        tablero[y][x] = (i == 0) ? SERPIENTE_CABEZA : SERPIENTE_CUERPO;
    }
}
