/**
 * @file Funcão que diz respeito ao parser
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.c"

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O parser.c -lm

/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 *
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @returns O tamanho da stack que foi criada
 */

int parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long Y; long X;
        long val_i = strtol(token, &sobra, 10);
        char ascii_c;

        switch (token[0]){ 

        // operações básicas
            case '+': 
                Y = POP();
                X = POP();
                PUSH(X += Y);
            break;

            case '-': 
                Y = POP();
                X = POP();
                PUSH(X -= Y);
            break;

            case '*': 
                Y = POP();
                X = POP();
                PUSH(X *= Y);
            break;

            case '/': 
                Y = POP();
                X = POP();
                PUSH(X /= Y);
            break;

        // incrementação e decrementação

            case '(': 
                Y = POP();
                PUSH(Y -= 1);
            break;

            case ')': 
                Y = POP();
                PUSH(Y += 1);
            break;

        // módulo e exponenciação
            case '%': 
                Y = POP();
                X = POP();
                PUSH(X %= Y);
            break;

            case '#': 
                Y = POP();
                X = POP();
                PUSH(pow(X,Y));
            break;

        // tabelas de verdades e bits oriented

            case '&': 
                Y = POP();
                X = POP();
                PUSH(X &= Y);
            break;

            case '|':
                Y = POP();
                X = POP();
                PUSH(X |= Y);
            break;

            case '^': 
                Y = POP();
                X = POP();
                PUSH(X ^= Y);
            break;
            
            case '~': 
                Y = POP();
                PUSH((~ Y));
            break;

        // ASCII
            
            case 'c':
                Y = POP();
                ascii_c = Y;
                PUSH(ascii_c);
            break;

        // caso default
            default :
                PUSH(val_i);

        }
    }

    PRINT_STACK();
    return STACK_SIZE();
}