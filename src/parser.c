/**
 * @file parser.c
 * @brief Ficheiro relativo à função que analisa e aplica funções entre operadores e operandos
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
      
        if(strlen(sobra1) == 0)                 // tamanho sobra1 == 0, então é um elemento do tipo LONG (dá push a esse elemento)
        	push_LONG(s, val_l);
       
        else if(strlen(sobra2) == 0)            // tamanho sobra2 == 0, então é um elemento do tipo DOUBLE (dá push a esse elemento)
        	push_DOUBLE(s, val_d);

        else if((isupper(token[0])) != 0)       // se for uma letra maiúscula coloca o seu valor na stack
            letra(s, token[0]);

        else if(strchr(token, ':') != NULL)  {  // se forem detetados ":" pega na letra que está à frente dos pontos
            char *letra = strchr(token, ':');
            atributo(s, &letra[1]);             // a letra é inserida como parametro para a função atributo
        }
        else {                                  // caso contrário -> operador/char/string -> contemplados nos casos seguintes
        
            switch (token[0]) {
        // operações base

                case '+' :
        	        soma(s);
                    break;

                case '-' :
                    subtrai(s);
                    break;

                case '*' :
                    multiplica(s);
                    break;

                case '/' :
                    divide(s);
                    break;

                case ')' :
                    incrementa(s);
                    break;

                case '(' :
                    decrementa(s);
                    break;

                case '%' :
                    modulo(s);
                    break;

                case '#' :
                    expoente(s);
                    break;

                case '&' :
                    E(s);
                    break;

                case '|' :
                    ou(s);
                    break;

                case '^' :
                    xor(s);
                    break;

                case '~' :
                    not(s);
                    break;

                case '=' :
                    igual(s);
                    break;

                case '!' :
                    nono(s);
                    break;

                case '<' :
                    menor(s);
                    break;

                case '>' :
                    maior(s);
                    break;

                case 'e' :
                    if (strcmp(token, "e&") == 0)
                        eE(s);
                    else if (strcmp(token, "e|") == 0)
                        eOU(s);
                    else if (strcmp(token, "e<") == 0)
                        emenor(s);
                    else if (strcmp(token, "e>") == 0)
                        emaior(s);
                    else 
                        push_CHAR(s, 'e');
                    break;

                case 'i' :
                    intz(s);
                    break;

                case 'f' :
                    doublez(s);
                    break;

                case 'c' :
                    charz(s);
                    break;

                case 's' :
                    stringz(s);
                    break;

                case '_' :
                    duplica(s);
                    break;

                case '\\' :
                    troca(s);
                    break;

                case ';' :
                    pop(s);
                    break;

                case '@' :
                    rodar(s);
                    break;

                case '$' :
                    copia(s);
                    break;

                case '?' :
                    question(s);
                    break;

                case 'l' :
                    lerl(s);
                    break;

                case 'p' :
                    printt(s);
                    break;

                default:
                    push_STRING(s, token);
                    break;

            }                   // end of switch
        }                       // end of else condition
    }                           // end of for
	print_stack(s);             // print result
	free(s);                    // clear stack
}                               // end of parser function
