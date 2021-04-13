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
 * 
 * @returns o valor 0
 */


int main(void) {
    Stack mystack = create_stack(100);
     
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
	
    /*
    // estava a fazer testes, ignorar isto

    //push(mystack, STACK_CHAR, 'x');
    //push(mystack, STACK_INT, 123);
    //push(mystack, STACK_DOUBLE, 7.89);
    //push(mystack, STACK_STRING, (void *) &mystack);
	
    while ( !stack_empty(mystack) ) {
        char c;
        int i;
        double d;
        void * p;

        switch ( top_type(mystack) ) {
            case STACK_CHAR:
                pop(mystack, &c);
                printf("Popped char '%c' from stack.\n", c);
                break;

            case STACK_LONG:
                pop(mystack, &i);
                printf("Popped int %d from stack.\n", i);
                break;

            case STACK_INT:
                pop(mystack, &i);
                printf("Popped int %d from stack.\n", i);
                break;

            case STACK_DOUBLE:
                pop(mystack, &d);
                printf("Popped double %f from stack.\n", d);
                break;

            case STACK_STRING:
                pop(mystack, &p);
                printf("Popped pointer %p from stack.\n", p);
                break;

            default:
                fprintf(stderr, "Unknown type.\n");
                return EXIT_FAILURE;

        }
    }
	*/
	print_stack(mystack);
    destroy_stack(mystack);

    return 0;
}