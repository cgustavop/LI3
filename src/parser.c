/**
 * @file Funcão que diz respeito ao parser
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O parser.c -lm

/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 *
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @returns O tamanho da stack que foi criada
 */

int parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);

        if(strlen(sobra) == 0) {
            PUSH(val_i);

        // operações 
        } else switch (strcmp(token,delims) == 0) {

        // operações básicas
         
        	case (delims == "+") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X += Y);
     			break;

        	case (delims == "-") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X -= Y);
            	break;

        	case (delims == "*") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X *= Y);
            	break;

        	case (delims == "/") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X /= Y);
            	break;

        // incrementação e decrementação

        	case (delims == "(") :
            	long Y = POP();
            	PUSH(Y -= 1);
            	break;  

        	case (delims == ")") :
            	long Y = POP();
           		PUSH(Y += 1);
           		break;

        // módulo e exponenciação

       		case (delims == "%") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X %= Y);
            	break;

        	case (delims == "#") :
            	long Y = POP();
            	long X = POP();
            	PUSH(pow(X,Y));
            	break;

        // tabelas de verdades e bits oriented

        	case (delims == "&") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X &= Y);
            	break;

        	case (delims == "|") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X |= Y);
            	break;

       		case (delims == "^") :
            	long Y = POP();
            	long X = POP();
            	PUSH(X ^= Y);
            	break;

        	case (delims == "~") :
            	long Y = POP();
            	PUSH((~ Y));
            	break;

            default :
            	PUSH(val_i);

        }
    }

    PRINT_STACK();
    return STACK_SIZE();
}