/**
 * @file Ficheiro que contem função principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#include "stack.h"


// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O *.c -lm
// void push(Stack stack, const enum stack_type type, ...)
// void pop(Stack stack, void *p)

/**
 * Esta é a função principal do programa
 *
 * A stack tem um size de 100
 * 
 * @returns o valor 0
 */


int main(){
    Stack stack = create_stack(10240);
     
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);

    print_stack(stack);
    destroy_stack(stack);

    return 0;
}