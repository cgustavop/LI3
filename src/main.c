/**
 * @file Ficheiro que contem função principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O main.c -lm

/**
 * Esta é a função principal do programa
 *
 * A stack tem um size de 100
 * O top está definido como EMPTY ou seja (-1)
 * @returns o valor 0
 */


int main() {
    Stack stk = create_stack(5);
    
     
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
	
    /*
    // estava a fazer testes, ignorar isto

    //push(stk, STACK_CHAR, 'x');
    //push(stk, STACK_INT, 123);
    //push(stk, STACK_DOUBLE, 7.89);
    //push(stk, STACK_STRING, (void *) &stk);
	
    while ( !stack_empty(stk) ) {
        char c;
        int i;
        double d;
        void * p;

        switch ( top_type(stk) ) {
            case STACK_CHAR:
                stack_pop(stk, &c);
                printf("Popped char '%c' from stack.\n", c);
                break;

            case STACK_LONG:
                stack_pop(stk, &i);
                printf("Popped int %d from stack.\n", i);
                break;

            case STACK_INT:
                stack_pop(stk, &i);
                printf("Popped int %d from stack.\n", i);
                break;

            case STACK_DOUBLE:
                stack_pop(stk, &d);
                printf("Popped double %f from stack.\n", d);
                break;

            case STACK_STRING:
                stack_pop(stk, &p);
                printf("Popped pointer %p from stack.\n", p);
                break;

            default:
                fprintf(stderr, "Unknown type.\n");
                return EXIT_FAILURE;

        }
    }
	*/
	print_stack(stk);
    destroy_stack(stk);

    return 0;
}