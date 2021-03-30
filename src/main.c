/**
 * @file Ficheiro que contém a função principal do programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.c"

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O main.c -lm

/**
 * Analisa o tipo de um operando localizado no topo da stack.
 * 
 * @returns o void
 */
void print_type(STACK *s) {
	if (has_type(top(s), STRING)) putchar('S');
	if (has_type(top(s), INTEGER)) putchar('I');
	if (has_type(top(s), DOUBLE)) putchar('D');
	if (has_type(top(s), NUMBER)) putchar('N');
	putchar('\n');
}

/**
 * \brief Esta é a função principal do programa
 *
 * A stack tem um size de 100
 * O top está definido como EMPTY ou seja (-1)
 * @returns o valor 0
 */
int main(void) {
	STACK *s = create_stack();

	/* old stuff
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line [strlen(line) - 1] == '\n');

    parse(line);
	*/

    print_stack(s); print_type(s);

    printf("%c\n", pop_CHAR(s));
    printf("%g\n", pop_DOUBLE(s));
    printf("%ld\n", pop_LONG(s));

    return 0;
}