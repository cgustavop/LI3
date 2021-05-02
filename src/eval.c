/**
 * @file eval.c
 * @brief Ficheiro relativo à função eval que analisa e aplica funções da linha consoante o contexto
 */
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "stack.h"
#include "maths.h" 
#include "logics.h"
#include "manpln.h"

// gcc -std=gnu11 -Wall -pedantic-errors -O eval.c -lm
/*
char *seps = "\"[]";
char *delims = " \t\n"; 
char **rest;

char *get_token(char *line, char **rest) { // devolve o token e coloca em rest o restante da string para separar

	char *token = (char *)malloc(sizeof(char)*strlen(line));   // fornece memória ao *token

	token = strtok(line, delims);	// guarda um token

    *rest = line + strlen(token) + 1;

	return token;
}
*/
/*
char *get_delimited(char *line, char *seps, char **rest) { //devolve a parte da linha que contém o string ou array

}

handle_arithmetic

handle_logic

handle_array

handle_string

STACK eval(char *line, STACK *init_stack){

	
}


char *sumarrays(char ){
	
}
*/
/*
int main(void){

	char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line) - 1] == '\n');

    printf("%s\n", get_token(line, rest));
    putchar('\n');
    for(; strcmp(*rest, "\0") == 0 ; *rest++){
    	printf("%s\n", *rest);
	}

    return 0;
}
*/
