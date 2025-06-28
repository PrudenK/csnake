//
// Created by pruden on 28/06/25.
//

#include "teclado.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/time.h>

#include "globales.h"

void configurar_terminal_sin_buffer() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void restaurar_terminal() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void manejar_input() {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) > 0) {
        char c = getchar();

        if (c == '\033') {
            getchar();
            c = getchar();
        }

        switch (c) {
            case 'A': // arriba
                if (direc != 'S') direc = 'W';
                break;
            case 'B': // abajo
                if (direc != 'W') direc = 'S';
                break;
            case 'C': // derecha
                if (direc != 'A') direc = 'D';
                break;
            case 'D': // izquierda
                if (direc != 'D') direc = 'A';
                break;
            case 'q':
                restaurar_terminal();
                printf("¡Has salido de la partida!\n");
                exit(0);
        }
    }
}