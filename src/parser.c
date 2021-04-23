#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "maths.h"

void parse(char *line) {

    STACK *s = new_stack();

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;
      
        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);

        if(strlen(sobra1) == 0)
        	push_LONG(s, val_l);
       
        else if(strlen(sobra2) == 0)
        	push_DOUBLE(s, val_d);

        else if (strcmp(token, "+") == 0)	// função soma
        	soma(s);

        else if (strcmp(token, "-") == 0)	// função subtração
        	subtrai(s);

        else if (strcmp(token, "*") == 0)	// função multiplicação
        	multiplica(s);

        else if (strcmp(token, "/") == 0)	// função divide
        	divide(s);

        else if (strcmp(token, ")") == 0)	// função incrementa
        	incrementa(s);

        else if (strcmp(token, "(") == 0)	// função decrementa
        	decrementa(s);

        else if (strcmp(token, "%") == 0)	// função modulo
        	modulo(s);

        else if (strcmp(token, "#") == 0)	// função expoente
        	expoente(s);

        else if (strcmp(token, "&") == 0)	// função lógica de disjunção
        	E(s);

        else if (strcmp(token, "|") == 0)	// função lógica de conjunção
        	ou(s);

        else if (strcmp(token, "^") == 0)	// função ou exclusivo
        	xor(s);

        else if (strcmp(token, "~") == 0)	// função negação lógica
        	not(s);

        else if (strcmp(token, "_") == 0)	// função duplica
        	duplica(s);

        else if (strcmp(token, ";") == 0)	// função pop
        	apaga(s);

        else
            push_STRING(s, token); 
		}

	print_stack(s);
	free(s);
}
