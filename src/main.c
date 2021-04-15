/**
 * @file Ficheiro que contem função principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.c"

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O main.c -lm

/**
 * Esta é a função principal do programa
 *
 * A stack tem um size de 100
 * 
 * @returns o valor 0
 */


int main(void){
    Stack mystack = create_stack(10240);
     
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
    
	print_stack(mystack);
    destroy_stack(mystack);

    return 0;
}