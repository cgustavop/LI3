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
 * Analisa a linha de texto inserida e faz a sua separação em operadores e operandos consoante espaços, tabs ou mudanças de linhas.
 * Interpreta cada token e executa a sua função no contexto da linguagem.
 *
 * 
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @param token Operadores contidos na linha
 * @param sobra Vai guardando elementos da stack que não sofreram nenhuma transformação
 * @val_i 
 * @param ascii_c Usado no operando de conversão ASCII
 * @returns O tamanho da stack resultante
 */
/*
int parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;                             // ???
        long Y; long X; long Z;
        long val_i = strtol(token, &sobra, 10);  // ???
        char ascii_c;

        switch (token[0]){ 

        // operações básicas

            case '+': 
                Y = pop();
                X = pop();
                push(X += Y);
                break;

            case '-': 
                Y = pop();
                X = pop();
                push(X -= Y);
                break;

            case '*': 
                Y = pop();
                X = pop();
                push(X *= Y);
                break;

            case '/': 
                Y = pop();
                X = pop();
                push(X /= Y);
                break;

        // incrementação e decrementação

            case '(': 
                Y = pop();
                push(Y -= 1);
                break;

            case ')': 
                Y = pop();
                push(Y += 1);
                break;

        // módulo e exponenciação

            case '%': 
                Y = pop();
                X = pop();
                push(X %= Y);
                break;

            case '#': 
                Y = pop();
                X = pop();
                push(pow(X,Y));
                break;

        // tabelas de verdades e bits oriented

            case '&': 
                Y = pop();
                X = pop();
                push(X &= Y);
                break;

            case '|':
                Y = pop();
                X = pop();
                push(X |= Y);
                break;

            case '^': 
                Y = pop();
                X = pop();
                push(X ^= Y);
                break;
            
            case '~': 
                Y = pop();
                push((~ Y));
                break;       

        // conversões do topo da stack || incompleto

            case 'i' : // converter em int
                Y = pop();
                // ...
                push();
                break;

            case 'f' : // converter em double
                Y = pop();
                // ...
                push();
                break;

            case 's' : // converter em string
                Y = pop();
                // ...
                push();
                break; 

            case 'c': // converter em char (ASCII)
                Y = pop();
                ascii_c = Y;
                push(ascii_c);
                break;

        // ler linhas e imprimir linhas || incompleto

            case 'l' : // ler linha abaixo
                fgets();
                // ..
                break;

            case 't' : // ler todas as linhas guião 3/4
                fgets();
                //..
                break;

            case 'p' : // printar topo || guião 3/4
                Y = pop();
                push(Y);
                break;

            case '@' : // Rodar os 3 elementos no topo da stack
                Z = pop();
                Y = pop();
                X = pop();
                push(Y);
                push(Z);
                push(X);                
                break;

            case ';' : // Pop
                pop();
                break;

            case '_' : // Duplicar
                Y = pop();
                push(Y);
                push(Y);
                break;

            case '$' : // Copia n-ésimo elemento para o topo da stack, 0 é o topo da stack
                int i, n;

                Y = pop();
                X = pop();
                push(X);
                push(Y);

                for(i=X;i<0;i--){
                	n = mystack[top];
                	top--;                  
                }

                pop();
                push(n);
                break;
           
            case '\' : // Trocar os dois elementos do topo da stack
                Y = pop();
                X = pop();
                push(Y);
                push(X);
                break;

        // caso default

            default :
                push(val_i);

        }
    }

    print_stack();
    return stack_size();
}
*/

int parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;                             // ???
        long Y; long X; long Z;
        long val_i = strtol(token, &sobra, 10);  // ???
        char ascii_c;
        
        //vars novas
        char val_char;
        int val_int;  
        long val_long;     
        double val_double;
        void * val_pointer;

        switch (token[0]){ 

        // operações básicas

            case '+': 
                Y = pop(new_stack, val_pointer);
                X = pop();
                push(X += Y);
                break;

            case '-': 
                Y = pop();
                X = pop();
                push(X -= Y);
                break;

            case '*': 
                Y = pop();
                X = pop();
                push(X *= Y);
                break;

            case '/': 
                Y = pop();
                X = pop();
                push(X /= Y);
                break;


}