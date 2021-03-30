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

// Type of top of the stack

void print_type(STACK *s) {
	if (has_type(top(s), STRING)) putchar('S');
	if (has_type(top(s), INTEGER)) putchar('I');
	if (has_type(top(s), DOUBLE)) putchar('D');
	if (has_type(top(s), NUMBER)) putchar('N');
	putchar('\n');
}

int main(void) {
	STACK *s = create_stack();

	/* old stuff
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
	*/

	push_STRING(s)
    print_stack(s); print_type(s);

    

    return 0;
}