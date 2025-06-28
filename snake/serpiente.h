//
// Created by pruden on 27/06/25.
//

#ifndef SERPIENTE_H
#define SERPIENTE_H
#include "globales.h"

typedef struct {
    int x;
    int y;
} Coordenada;

extern Coordenada serpiente[MAX_SERPIENTE];
extern int tama_serpiente;

void inicializar_serpiente();
void mover_serpiente();
extern char direc;
#endif //SERPIENTE_H
