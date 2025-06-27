//
// Created by pruden on 27/06/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "globales.h"
#include "tablero.h"
#include "snake/serpiente.h"


int tablero[FILAS][COLUMNS] = {0};
int puntuacion = 0;



Coordenada serpiente[MAX_SERPIENTE];
int tama_serpiente = 3;

char direc = 'D';

int main() {
    srand(time(NULL));

    cargar_tablero();
    inicializar_serpiente();

    imprimir_tablero();





    return 0;
}
