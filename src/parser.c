/**
 * @file Funcão que diz respeito ao parser
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"

// gcc -std=gnu11 -Wall -Weval_longtra -pedantic-errors -O parser.c -lm

/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 * 
 * Analisa a linha de teval_longto inserida e faz a sua separação em operadores e operandos consoante espaços, tabs ou mudanças de linhas.
 * Interpreta cada token e eval_longecuta a sua função no conteval_longto da linguagem.
 *
 * 
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @param token Operadores contidos na linha
 * @param sobra Vai guardando elementos da stack que não sofreram nenhuma transformação
 * @val_i 
 * @param ascii_c Usado no operando de conversão ASCII
 * @returns O tamanho da stack resultante
 */


int parse(char *line) {
    Stack mystack = create_stack(100);

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);  

        // void push(Stack stack, const enum stack_type type, ...)
        // void pop(Stack stack, void *p)

        // vars novas

        //char val_char, val_char2, val_char3, check1; 
        long val_long, val_long2; //val_long3, check2;     
        //double val_double, val_double2, val_double3, check3;
        //void *val_pointer, *check4;

        /*

        // checks de tipos do top
        // copiar para os casos necessários

        if ((top_type(token)) == (STACK_CHAR)){
            token[0] = check1;
        } else if ((top_type(token)) == (STACK_LONG)){
            token[0] = check2;
        } else if ((top_type(token)) == (STACK_DOUBLE)){
            token[0] = check3;
        } else if ((top_type(token)) == (STACK_STRING)){
            token[0] = check4;
        } else token[0] = check2; // default é int

        */

        switch (token[0]){ 

        // operações básicas

            case '+': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res = val_long2 += val_long;
                push(mystack, STACK_LONG, res);
                break;

            case '-': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res2 = val_long2 -= val_long;
                push(mystack, STACK_LONG, res);
                break;

            case '*': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res3 = val_long2 *= val_long;
                push(mystack, STACK_LONG, res3);
                break;

            case '/': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res4 = val_long2 /= val_long;
                push(mystack, STACK_LONG, res4);
                break;

        // incrementação e decrementação

            case '(': 
                pop(mystack, &val_long);
                int res5 = val_long -= 1;
                push(mystack, STACK_LONG, res5);
                break;

            case ')': 
                pop(mystack, &val_long);
                int res6 = val_long += 1;
                push(mystack, STACK_LONG, res5);
                break;

        // módulo e exponenciação

            case '%': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                res6 = val_long2 %= val_long;
                push(mystack, STACK_LONG, res6);
                break;

            case '#': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res7 = pow(val_long2,val_long);
                push(mystack, STACK_LONG, res7);
                break;

        // tabelas de verdades e bits oriented

            case '&': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res8 = (val_long2 &= val_long);
                push(mystack, STACK_LONG, res8);
                break;

            case '|':
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res9 = (val_long2 |= val_long);
                push(mystack, STACK_LONG, res9);
                break;

            case '^': 
                pop(mystack, &val_long);
                pop(mystack, &val_long2);
                int res10 = (val_long2 ^= val_long);
                push(mystack, STACK_LONG, res10);
                break;
            
            case '~': 
                pop(mystack, &val_long);
                int res11 = ((~ val_long));
                push(mystack, STACK_LONG, res11);
                break;       
                /*
        // conversões do topo da stack || incompleto

            case 'i' : // int

                break;

            case 'f' : // double

                break;

            case 'c' : // char (ascii)
                
                
                break;

        // ler linhas e imprimir linhas || incompleto

            case 'l' : // ler linha abaiXo
                fgets();
                // ..
                break;

            case 't' : // ler todas as linhas guião 3/4
                fgets();
                //..
                break;

            case 'p' : // printar topo || guião 3/4
                if ((top_type(token)) == (STACK_CHAR)){
                    token[0] = check1;
                    check1 = pop(*token, &check1);
                    push(token, STACK_CHAR, check1);
                } else if ((top_type(token)) == (STACK_LONG)){
                    token[0] = check2;
                    check2 = pop(*token, &check2);
                    push(token, STACK_LONG, check2);
                } else if ((top_type(token)) == (STACK_DOUBLE)){
                    token[0] = check3;
                    check3 = pop(*token, &check3);
                    push(token, STACK_DOUBLE, check3);
                } else if ((top_type(token)) == (STACK_STRING)){
                    token[0] = check4;
                    check4 = pop(*token, &check4);
                    push(token, STACK_STRING, check4);
                } else {
                    token[0] = check2;
                    check2 = pop(*token, &check2);
                    push(token, STACK_LONG, check2);
                break;

            case '@' : // Rodar os 3 elementos no topo da stack (inc)
                val_long = pop();
                val_long2 = pop();
                val_long3 = pop();
                push(val_long);
                push(val_long3);
                push(val_long2);                
                break;

            case ';' : // Pop
                pop(*token, top_type(token));
                break;

            case '_' : // Duplicar
                if ((top_type(token)) == (STACK_CHAR)){
                    token[0] = check1;
                    check1 = pop(*token, &check1);
                    push(token, STACK_CHAR, check1);
                    push(token, STACK_CHAR, check1);
                } else if ((top_type(token)) == (STACK_LONG)){
                    token[0] = check2;
                    check2 = pop(*token, &check2);
                    push(token, STACK_LONG, check2);
                    push(token, STACK_LONG, check2);
                } else if ((top_type(token)) == (STACK_DOUBLE)){
                    token[0] = check3;
                    check3 = pop(*token, &check3);
                    push(token, STACK_DOUBLE, check3);
                    push(token, STACK_DOUBLE, check3);  
                } else if ((top_type(token)) == (STACK_STRING)){
                    token[0] = check2;
                    check4 = pop(*token, &check4);
                    push(token, STACK_STRING, check4);
                    push(token, STACK_STRING, check4);
                } else { 
                    token[0] = check2;
                    check2 = pop(*token, &check2);
                    push(token, STACK_LONG, check2);
                    push(token, STACK_LONG, check2);
                }

                break;

            case '$' : // Copia n-ésimo elemento para o topo da stack, 0 é o topo da stack
                int i, n;

                val_long = pop();
                val_long2 = pop();
                push(val_long);
                push(val_long);

                for(i=val_long2;i<0;i--){
                	n = token[top];
                	top--;                  
                }

                pop();
                push(n);
                break;
           
            case '\\n': // Trocar os dois elementos do topo da stack
                val_long = pop();
                val_long2 = pop();
                push(val_long);
                push(val_long2);
                break;
            */
        // caso default

            default :
                push(mystack, STACK_LONG,val_i);

        }
    }

    print_stack(mystack);
    return stack_size(mystack);
}
