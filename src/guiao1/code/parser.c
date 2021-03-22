/**
 * @file Funcão que diz respeito ao parser
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include "stack.h"
#include "parser.h"


// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O parser.c.c -lm

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
        long val_i = strtol(token, &sobra, 10);
        if(strlen(sobra) == 0) {
            PUSH(val_i);

        // operações básicas
        } else if(strcmp(token, "+") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X + Y);
        } else if(strcmp(token, "-") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X - Y);
        } else if(strcmp(token, "*") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X * Y);
        } else if(strcmp(token, "/") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X / Y);

        // incrementação e decrementação
        } else if(strcmp(token, "(") == 0) {
            long Y = POP();
            PUSH(Y--);  
        } else if(strcmp(token, ")") == 0) {
            long Y = POP();
            PUSH(Y++);

        // módulo e exponenciação
        } else if(strcmp(token, "%") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X%Y);
        } else if(strcmp(token, "#") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(pow(X,Y));

        // tabelas de verdades e bits oriented
        } else if(strcmp(token, "&") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X && Y);
        } else if(strcmp(token, "|") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X || Y);
        } else if(strcmp(token, "^") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X ^ Y);
        } else if(strcmp(token, "~") == 0) {
            long Y = POP();
            PUSH(~ Y);
        }
    }

    PRINT_STACK();
    return STACK_SIZE();
}