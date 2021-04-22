/**
 * @file Ficheiro que contem função principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"

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

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O *.c -lm
// void push(Stack stack, const enum stack_type type, ...)
// void pop(Stack stack, void *p)

/**
 * Esta é a função principal do programa
 *
 * A stack tem um size de 10240
 * 
 * @returns o valor 0
 */


int main(void){

	Stack stack = create_stack(10240);

	//char line[10240];

    //assert(fgets(line, 10240, stdin) != NULL);
    //assert(line[strlen(line) - 1] == '\n');

    //parse(line);

    

    push(stack, STACK_CHAR, 'x');
    push(stack, STACK_INT, 123);
    push(stack, STACK_DOUBLE, 7.89);
    push(stack, STACK_STRING, (void *) &stack);

    while ( !stack_empty(stack) ) {
        char c;
        int i;
        double d;
        void * p;

        switch ( stack_peek(stack) ) {
            case STACK_CHAR:
            	pop(stack, &c);
            	printf("%c\n", c);
	
            break;

            case STACK_INT:
            	pop(stack, &i);
            	printf("%d\n", i);	
            break;

            case STACK_DOUBLE:
                pop(stack, &d);
                printf("%f\n", d);  
            break;

            case STACK_STRING:
                pop(stack, &p);
                printf("%p\n", p);  
            break;

            default:
                fprintf(stderr, "Unknown type.\n");
                return EXIT_FAILURE;
        }
    }
 	
 	print_stack(stack);
    destroy_stack(stack);

    return 0;
}
