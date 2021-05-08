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
 * 
 */
void parse(char *line) {

    STACK *s = new_stack();                      // criação da stack

    char *delims = " \t\n";                      // elementos que representam a separação dos tokens

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;
      
        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);
      
        if(strlen(sobra1) == 0)                  // tamanho sobra1 == 0, então é um elemento do tipo LONG (dá push a esse elemento)
        	push_LONG(s, val_l);
       
        else if(strlen(sobra2) == 0)             // tamanho sobra2 == 0, então é um elemento do tipo DOUBLE (dá push a esse elemento)
        	push_DOUBLE(s, val_d);

        else if((isupper(token[0])) != 0)        // se for uma letra maiúscula coloca o seu valor na stack
            letra(s, token[0]);

        else if(strchr(token, ':') != NULL)  {   // se forem detetados ":" pega na letra que está à frente dos pontos
            char *letra = strchr(token, ':');
            atributo(s, &letra[1]);              // a letra é inserida como parametro para a função atributo
        }
        else {                                   // caso contrário -> operador/char/string -> contemplados nos casos seguintes
        
            switch (token[0]) {
        // operações base

                case '+' :                       // função soma
        	        soma(s);
                    break;

                case '-' :                       // função subtração
                    subtrai(s);
                    break;

                case '*' :                       // função multiplicação
                    multiplica(s);
                    break;

                case '/' :                       // função divisão
                    divide(s);
                    break;

                case ')' :                       // função incrementa
                    incrementa(s);
                    break;

                case '(' :                       // função decrementa
                    decrementa(s);
                    break;

                case '%' :                       // função módulo
                    modulo(s);
                    break;

                case '#' :                       // função exponencialização
                    expoente(s);
                    break;

                case '&' :                       // função e lógico
                    E(s);
                    break;

                case '|' :                       // função ou lógico
                    ou(s);
                    break;

                case '^' :                       // função xor
                    xor(s);
                    break;

                case '~' :                       // função negação lógica
                    not(s);
                    break;

                case '=' :                       // função igualdade
                    igual(s);
                    break;

                case '!' :                       // função negação
                    nono(s);
                    break;

                case '<' :                       // função menor que
                    menor(s);
                    break;

                case '>' :                       // função maior que
                    maior(s);
                    break;

                case 'e' :                       // funções exclusivas
                    if (strcmp(token, "e&") == 0)
                        eE(s);
                    else if (strcmp(token, "e|") == 0)
                        eOU(s);
                    else if (strcmp(token, "e<") == 0)
                        emenor(s);
                    else if (strcmp(token, "e>") == 0)
                        emaior(s);
                    else 
                        push_CHAR(s, 'e');       // caso o "e" detetado seja um simples char
                    break;

                case 'i' :                       // função converte a int
                    intz(s);
                    break;

                case 'f' :                       // função converte a double
                    doublez(s);
                    break;

                case 'c' :                       // função converte a char
                    charz(s);
                    break;

                case 's' :                       // função converte a string
                    stringz(s);
                    break;

                case '_' :                       // função duplica
                    duplica(s);
                    break;

                case '\\' :                      // troca os 2 elementos no topo da stack
                    troca(s);
                    break;

                case ';' :                       // pop a um elemento no topo da stack
                    pop(s);
                    break;

                case '@' :                       // troca 3 elementos no topo da stack
                    rodar(s);
                    break;

                case '$' :                       // troca o elemento no topo da stack pelo n-ésimo elemento da mesma
                    copia(s);
                    break;

                case '?' :                       // if then else com os 3 elementos no topo da stack
                    question(s);
                    break;

                case 'l' :                       // lê uma linha
                    lerl(s);
                    break;

                case 'p' :                       // imprime uma linha
                    printt(s);
                    break;

                default:                       // se não se trata de um operador faz push à string
                    push_STRING(s, token);
                    break;

            }                   // end of switch
        }                       // end of else condition
    }                           // end of for
	print_stack(s);             // print result
	free(s);                    // clear stack
}                               // end of parser function
