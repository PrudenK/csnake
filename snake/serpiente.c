//
// Created by pruden on 27/06/25.
//

#include "serpiente.h"

void inicializar_serpiente() {
    int medio_x = COLUMNS / 2;
    int medio_y = FILAS / 2;

    for (int i = 0; i < tama_serpiente; i++) {
        serpiente[i].x = medio_x - i;
        serpiente[i].y = medio_y;
        tablero[medio_y][medio_x - i] = (i == 0) ? SERPIENTE_CABEZA : SERPIENTE_CUERPO;
    }
}
