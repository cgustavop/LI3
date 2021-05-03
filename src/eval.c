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

// gcc -std=gnu11 -Wall -pedantic-errors -O *.c -lm
char *restante (char *line){    // devolve o maior dos restos

    char *e, *n, *t, *resto;
    int ei, ni, ti;
                                
    e = strchr(line, ' ');        // aponta para line apartir do primeiro espaço
    n = strchr(line, '\n');     // aponta para line apartir do primeiro newline
    t = strchr(line, '\t');        // aponta para line apartir do primeiro tab

    // verifica se os apontadores não são nulos
    if (e) ei = strlen(e);
    else ei = 0;

    if (n) ni = strlen(n);
    else ni = 0;

    if (t) ti = strlen(t);
    else ti = 0;

    // calcula qual corresponde ao maior dos restos
    if (ei > ti && ei > ni) resto= e;
    else if (ti > ni) resto = t;
    else resto = n;

    return resto;
}

char *get_token(char *line, char **rest) {  // devolve o token e coloca em "rest" o que resta da string

    char *token, *resto;
    resto = restante(line);

    token = strndup(line, strlen(line)-strlen(resto));    // guarda o primeiro token da line numa string
    *rest = strdup(resto + 1);                               // guarda o resto da line numa string

    return token;
}

char *seps = " \t\n";
//char *seps = "\"[]";

char *get_delimited(char *line, char *seps, char **rest) { //devolve a parte da linha que contém o interior da string ou array

    char *array = malloc(sizeof(char)*strlen(line));
    memset( array, '\0', sizeof(char)*strlen(line));
    char *token;
    char *cpy = strdup(line);
    int aberturas = 1;
    //int i = 0;

    for (token = strtok(cpy, seps); aberturas != 0; token = strtok(NULL, seps)) {

            if (strcmp(token, "[") == 0) {
              
                aberturas++;
                strcat(strcat(array, token) , " ");
                
            } else if (strcmp(token, "]") == 0) {
              
                aberturas--;
                if (aberturas == 0) {}
                else strcat(strcat(array, token) , " ");
                
            } else if (strcmp(token, "\"") == 0) {
                aberturas--;

            } else strcat(strcat(array, token) , " ");
        
    }
    
    *rest = strdup(line + strlen(array) + 2);
    
    return array;
}
STACK *eval(char *line, STACK *init_stack);

void handle_array(char *line, STACK *init_stack) {	// recebe o que está dentro dos parêntesis do array e dá push disso "avaliado" como uma stack

	// eval da line com stack null = stack
	// push do array na nossa stack na forma de stack
	STACK *array = NULL;
	push_ARRAY( init_stack, eval(line, array) );

}

STACK *eval(char *line, STACK *init_stack){

	char **rest = malloc(sizeof(char *));

	for (char *token = get_token(line, rest); token != NULL ; line = strdup(*rest)) {

		char *sobra1, *sobra2;

    	long val_l = strtol(token, &sobra1, 10);	
    	double val_d = strtod(token, &sobra2);
      
        if(strlen(sobra1) == 0)                  // tamanho sobra1 == 0, então é um elemento do tipo LONG (dá push a esse elemento)
        	push_LONG(init_stack, val_l);
       
        else if(strlen(sobra2) == 0)             // tamanho sobra2 == 0, então é um elemento do tipo DOUBLE (dá push a esse elemento)
        	push_DOUBLE(init_stack, val_d);

        else if((isupper(token[0])) != 0)        // se for uma letra maiúscula coloca o seu valor na stack
            letra(init_stack, token[0]);

        else if(strchr(token, ':') != NULL)  {   // se forem detetados ":" pega na letra que está à frente dos pontos
            char *letra = strchr(token, ':');
            atributo(init_stack, &letra[1]);              // a letra é inserida como parametro para a função atributo
        }
        else { 

        	switch (token[0]) {

                case '[' :
        	        	// retira conteúdo do array para uma line
        	        handle_array( get_delimited(line, seps, rest) , init_stack);		// trata do conteúdo no interior do array e guarda-o na nossa stack
                    break;

                case '\"' :
        	        push_STRING(init_stack, get_delimited(line, seps, rest));			// retira o que está dentro de aspas e dá push como uma string
                    break;

                case '+' :                       // função soma
        	        soma(init_stack);
                    break;

                case '-' :                       // função subtração
                    subtrai(init_stack);
                    break;

                case '*' :                       // função multiplicação
                    multiplica(init_stack);
                    break;

                case '/' :                       // função divisão
                    divide(init_stack);
                    break;

                case ')' :                       // função incrementa
                    incrementa(init_stack);
                    break;

                case '(' :                       // função decrementa
                    decrementa(init_stack);
                    break;

                case '%' :                       // função módulo
                    modulo(init_stack);
                    break;

                case '#' :                       // função exponencialização
                    expoente(init_stack);
                    break;

                case '&' :                       // função e lógico
                    E(init_stack);
                    break;

                case '|' :                       // função ou lógico
                    ou(init_stack);
                    break;

                case '^' :                       // função xor
                    xor(init_stack);
                    break;

                case '~' :                       // função negação lógica
                    not(init_stack);
                    break;

                case '=' :                       // função igualdade
                    igual(init_stack);
                    break;

                case '!' :                       // função negação
                    nono(init_stack);
                    break;

                case '<' :                       // função menor que
                    menor(init_stack);
                    break;

                case '>' :                       // função maior que
                    maior(init_stack);
                    break;

                case 'e' :                       // funções exclusivas
                    if (strcmp(token, "e&") == 0)
                        eE(init_stack);
                    else if (strcmp(token, "e|") == 0)
                        eOU(init_stack);
                    else if (strcmp(token, "e<") == 0)
                        emenor(init_stack);
                    else if (strcmp(token, "e>") == 0)
                        emaior(init_stack);
                    else 
                        push_CHAR(init_stack, 'e');       // caso o "e" detetado seja um simples char
                    break;

                case 'i' :                       // função converte a int
                    intz(init_stack);
                    break;

                case 'f' :                       // função converte a double
                    doublez(init_stack);
                    break;

                case 'c' :                       // função converte a char
                    charz(init_stack);
                    break;

                case 's' :                       // função converte a string
                    stringz(init_stack);
                    break;

                case '_' :                       // função duplica
                    duplica(init_stack);
                    break;

                case '\\' :                      // troca os 2 elementos no topo da stack
                    troca(init_stack);
                    break;

                case ';' :                       // pop a um elemento no topo da stack
                    pop(init_stack);
                    break;

                case '@' :                       // troca 3 elementos no topo da stack
                    rodar(init_stack);
                    break;

                case '$' :                       // troca o elemento no topo da stack pelo n-ésimo elemento da mesma
                    copia(init_stack);
                    break;

                case '?' :                       // if then else com os 3 elementos no topo da stack
                    question(init_stack);
                    break;

                case 'l' :                       // lê uma linha
                    lerl(init_stack);
                    break;

                case 'p' :                       // imprime uma linha
                    printt(init_stack);
                    break;

                default:                       // se não se trata de um operador faz push à string
                    push_STRING(init_stack, token);
                    break;

            }                   // end of switch
    	}	free(rest);			// pointer "rest" é livre para guardar o resto do get_token da próxima iteração do ciclo for

 	}
	return init_stack;			// return the stack evaluated
}                               // end of eval function
