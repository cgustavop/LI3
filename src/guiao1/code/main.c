/**
 * @file Ficheiro que contem função principal do programa
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.h"
#include "stack.c"

int top = 0;
int stack[100];

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O main.c -lm

/**
 * Esta é a função principal do programa
 *
 * @returns o valor 0
 */

int main() {

    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
    return 0;
}