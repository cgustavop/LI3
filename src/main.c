/**
 * @file Ficheiro que contem função principal do programa
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "maths.h"
#include "logics.h"
#include "manipulations.h"
#include "converts.h"
#include "pps.h"

// gcc -std=gnu11 -Wall -pedantic-errors -O *.c -lm

/*
int main(){
    Stack stack = create_stack(10240);
     
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');

    parse(line);

    print_stack(stack);
    destroy_stack(stack);

    return 0;
}
*/
int main(void){

	char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');

    parse(line);

    return 0;
}