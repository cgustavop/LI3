/**
 * @file parser.c
 * @brief Ficheiro relativo à função que analisa e aplica funções entre operadores e operandos
 */
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "maths.h" 
#include "logics.h"
#include "manpln.h"

/**
 * @brief Esta é a função que vai fazer o "parse" de uma linha
 * 
 * Analisa a linha inserida e faz a sua separação em operadores e operandos segundo espaços, tabs ou mudanças de linhas.
 * Interpreta cada token e executa a sua função no contexto da linguagem.
 *
 * @param s Struct onde será guardada a stack
 * @param delims String que indica os separadores dos tokens inseridos
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @param token Operadores contidos na linha
 * @param sobra1 Vai guardando elementos da stack que não sofreram nenhuma transformação
 * @param sobra2 Vai guardando elementos da stack que não sofreram nenhuma transformação
 * @param val_l Variável temporária onde são guardados operandos do tipo long
 * @param val_d Variável temporária onde são guardados operandos do tipo double
 * @returns void
 */
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


        // operações base

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

        // lógicas

        else if (strcmp(token, "&") == 0)	// função lógica de disjunção
        	E(s);

        else if (strcmp(token, "|") == 0)	// função lógica de conjunção
        	ou(s);

        else if (strcmp(token, "^") == 0)	// função lógica ou exclusivo
        	xor(s);

        else if (strcmp(token, "~") == 0)	// função lógica negação 
        	not(s);

        else if (strcmp(token, "=") == 0)   // função lógica igual
            igual(s);

        else if (strcmp(token, "!") == 0)   // função lógica (não)
            nono(s);

        else if (strcmp(token, "<") == 0)   // função lógica menor
            menor(s);

        else if (strcmp(token, ">") == 0)   // função lógica maior
            maior(s);

        else if (strcmp(token, "e&") == 0)   // função lógica e E
            eE(s);

        else if (strcmp(token, "e|") == 0)   // função lógica e OU
            eOU(s);
        
        else if (strcmp(token, "e<") == 0)   // função lógica e menor
            emenor(s);

        else if (strcmp(token, "e>") == 0)   // função lógica e maior
            emaior(s);

        else if (strcmp(token, "e") == 0)   // função lógica e
            eOU(s);

        // conversões

        else if (strcmp(token, "i") == 0)   // conversão para int
            intz(s);

        else if (strcmp(token, "f") == 0)   // conversão para double
            doublez(s);

        else if (strcmp(token, "c") == 0)   // conversão para char (ascii)
            charz(s);

        else if (strcmp(token, "s") == 0)   // conversão para string 
            stringz(s);
        
        // manipulação da stack

        else if (strcmp(token, "_") == 0)	// função duplica
        	duplica(s);

        else if (strcmp(token, "\\") == 0)   // função troca 
            troca(s);

        else if (strcmp(token, "@") == 0)   // função troca 3 
            rodar(s);

        else if (strcmp(token, "$") == 0)   // função troca topo por n-esimo
            copia(s);

        else if (strcmp(token, "?") == 0)   // função if then else
            question(s);
/*
        else if (strcmp(token, "A") == 0)
            HEX(s);

        else if (strcmp(token, "B") == 0)
            HEX(s);

        else if (strcmp(token, "C") == 0)
            HEX(s);

        else if (strcmp(token, "D") == 0)
            HEX(s);

        else if (strcmp(token, "E") == 0)
            HEX(s);

        else if (strcmp(token, "F") == 0)
            HEX(s);

        else if (strcmp(token, "N") == 0)
            HEX(s);

        else if (strcmp(token, "S") == 0)
            HEX(s);

        else if (strcmp(token, "X") == 0)
            HEX(s);

        else if (strcmp(token, "Y") == 0)
            HEX(s);

        else if (strcmp(token, "Z") == 0)
            HEX(s);
*/
        // pops e prints
        
        else if (strcmp(token, ";") == 0)	// função pop
            pop(s);
        
        else if (strcmp(token, "p") == 0)   // printa top
            printt(s);

        else if (strcmp(token, "l") == 0)  { // lê linha abaixo
            lerl(s);
        }

        else
           push_STRING(s, token); 
		}

	print_stack(s);
	free(s);
}
