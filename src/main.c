#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "maths.h"

// gcc -std=gnu11 -Wall -pedantic-errors -O *.c -lm

int main(void){

	char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');

    parse(line);

    return 0;
}