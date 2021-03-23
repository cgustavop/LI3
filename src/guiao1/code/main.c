/**
 * @file Ficheiro que contem função principal do programa
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.h"
<<<<<<< HEAD
#include "stack.h"
=======
#include "parser.c"
#include "stack.c"


int top;
int stack[100];
>>>>>>> a9d7829c9b8e5be3398eb0a69410e10a3ffe2f6c

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O main.c -lm

/**
 * Esta é a função principal do programa
 *
 * @returns o valor 0
 */

int main() {
    top = 0;
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parser(line);
    return 0;
}