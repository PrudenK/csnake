//
// Created by pruden on 27/06/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "globales.h"
#include "tablero.h"
#include "teclado.h"
#include "manzanas/generar_manzanas.h"
#include "snake/serpiente.h"


int tablero[FILAS][COLUMNS] = {0};
int puntuacion = 0;

Coordenada serpiente[MAX_SERPIENTE];
int tama_serpiente = 3;

char direc = 'D';

int manzana_x = -1;
int manzana_y = -1;

int main() {
    srand(time(NULL));
    configurar_terminal_sin_buffer();


    inicializar_serpiente();
    generar_manzana();

    while (1) {
        manejar_input();
        mover_serpiente();
        imprimir_tablero();
        usleep(150000); // 150 ms
    }


    return 0;
}
