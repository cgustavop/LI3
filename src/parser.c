/**
 * @file Funcão que diz respeito ao parser
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"
//#include "stack.c"

// gcc -std=gnu11 -Wall -Weval_longtra -pedantic-errors -O parser.c -lm

/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 * 
 * Analisa a linha de eval_long inserida e faz a sua separação em operadores e operandos consoante espaços, tabs ou mudanças de linhas.
 * Interpreta cada token e executa a sua função no conto da linguagem.
 *
 * 
 * @param line A linha que foi lida e da qual se vai fazer o parse
 * @param token Operadores contidos na linha
 * @param sobra Vai guardando elementos da stack que não sofreram nenhuma transformação
 * @val_i 
 * 
 * @returns O tamanho da stack resultante
 */


void parse(char *line) {
    Stack stack = create_stack(10240);

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
         //char *sobra;
         //long val_i = strtol(token, &sobra, 10);

        // void push(Stack stack, const enum stack_type type, ...)
        // void pop(Stack stack, void *p)

        // vars novas
        int val_int, val_int2;
        char val_char, val_char2; 
        long val_long, val_long2;     
        double val_double,  val_double2; 
        void *val_pointer;

        switch (token[0]){ 

        // operações básicas

            case '+':
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 += val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 += val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 += val_double;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 += val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

            case '-': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 -= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 -= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 -= val_double;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 -= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

             case '*': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 *= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 *= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 *= val_double;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 *= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

            case '/': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 /= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 /= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 /= val_double;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 /= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

        // incrementação e decrementação

            case '(': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 += 1;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 += 1;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 += 1;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 += 1;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;
                }
                break;

            case ')': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 -= 1;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 -= 1;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        pop(stack, &val_double2);
                        val_double2 -= 1;
                        push(stack, STACK_DOUBLE, val_double2);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 -= 1;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

        // módulo e exponenciação

            case '%': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 %= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 %= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 %= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

            case '#': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 = pow(val_int2,val_int);
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 = pow(val_long2,val_long);
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 = pow(val_char2,val_char);
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;


                }
                break;

        // tabelas de verdades e bits oriented

            case '&': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 &= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 &= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 &= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

            case '|':
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 |= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 |= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 |= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;

            case '^': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        pop(stack, &val_int2);
                        val_int2 ^= val_int;
                        push(stack, STACK_INT, val_int2);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        pop(stack, &val_long2);
                        val_long2 ^= val_long;
                        push(stack, STACK_LONG, val_long2);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        pop(stack, &val_char2);
                        val_char2 ^= val_char;
                        push(stack, STACK_CHAR, val_char2);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;
            
            case '~': 
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        val_int = (~val_int);
                        push(stack, STACK_INT, val_int);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        val_long = (~val_long);
                        push(stack, STACK_LONG, val_long);
                        break;

                    case (STACK_DOUBLE):
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        val_char = (~val_char);
                        push(stack, STACK_CHAR, val_char);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;

                }
                break;      
        
            // conversões do topo da stack

            case 'i' : // Converter o topo da stack num inteiro
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        val_int = (int)(val_int);
                        push(stack, STACK_INT, val_int);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        val_long = (int)(val_long);
                        push(stack, STACK_INT, val_long);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        val_double = (int)(val_int);
                        push(stack, STACK_INT, val_double);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        val_char = (int)(val_char);
                        push(stack, STACK_INT, val_char);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;


            case 'f' : // Converter o topo da stack num double
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        val_int = (double)(val_int);
                        push(stack, STACK_DOUBLE, val_int);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        val_long = (double)(val_long);
                        push(stack, STACK_DOUBLE, val_long);
                        break;

                    case (STACK_DOUBLE):
                        pop(stack, &val_double);
                        val_double = (double)(val_int);
                        push(stack, STACK_DOUBLE, val_double);
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        val_char = (double)(val_char);
                        push(stack, STACK_DOUBLE, val_char);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;
                }
                break; 

                pop(stack, &val_double);
                pop(stack, &val_double2);

                
                push (stack, STACK_DOUBLE, val_double2);


            case 'c' : // Converter o topo da stack para caracter (ascii)
                switch (top_type(stack)){
                    case (STACK_INT):
                        pop(stack, &val_int);
                        val_int = (char)(val_int);
                        push(stack, STACK_CHAR, val_int);
                        break;

                    case (STACK_LONG):
                        pop(stack, &val_long);
                        val_long = (char)(val_long);
                        push(stack, STACK_CHAR, val_long);
                        break;

                    case (STACK_DOUBLE): // não faz double
                        break;

                    case (STACK_CHAR):
                        pop(stack, &val_char);
                        val_char = (char)(val_char);
                        push(stack, STACK_CHAR, val_char);
                        break;

                    case (STACK_STRING):
                        push(stack, STACK_STRING, val_pointer);
                        break;            

        // ler linhas e imprimir linhas || incompleto

            case 'l' : // ler linha abaixo
                //fgets();
                // ..
                break;

            case 't' : // ler todas as linhas
                //fgets();
                //..
                break;
            
            case '@' : // Rodar os 3 elementos no topo da stack
                char aux[3]; 
                for (int i=0;i<3;i++){
                    switch (top_type(stack)){
                        case (STACK_INT):
                            pop(stack, &val_int);
                            aux[i] = &val_int;
                            break;

                        case (STACK_LONG):
                            pop(stack, &val_long);
                            aux[i] = &val_long;
                            break;

                        case (STACK_DOUBLE):
                            pop(stack, &val_double);
                            aux[i] = &val_double;
                            break;

                        case (STACK_CHAR):
                            pop(stack, &val_char);
                            aux[i] = &val_char;
                            break;

                        case (STACK_STRING):
                            break;            
                }

                push(stack, STACK_CHAR, aux[0]);
                push(stack, STACK_CHAR, aux[2]);
                push(stack, STACK_CHAR, aux[1]); 

                break;
               
            case 'p' : // printar topo 
                if ((top_type(stack)) == (STACK_CHAR)){
                    pop(stack, &val_char);
                    push(stack, STACK_CHAR, val_char);
                } else if ((top_type(stack)) == (STACK_LONG)){
                    pop(stack, &val_long);
                    push(stack, STACK_LONG, val_long);
                } else if ((top_type(stack)) == (STACK_DOUBLE)){
                    pop(stack, &val_double);
                    push(stack, STACK_DOUBLE, val_double);
                } else if ((top_type(stack)) == (STACK_STRING)){
                    pop(stack, &val_pointer);
                    push(stack, STACK_STRING, val_pointer);
                } else {
                    pop(stack, val_int);
                    push(stack, STACK_INT, val_int);
                }
                break;
                
            
            case ';' : // Pop
                if ((top_type(stack)) == (STACK_CHAR)){
                    pop(stack, &val_char);
                } else if ((top_type(stack)) == (STACK_LONG)){
                     pop(stack, &val_long);
                } else if ((top_type(stack)) == (STACK_DOUBLE)){
                    pop(stack, &val_double); 
                } else
                    pop(stack, &val_int);
                
                break;

            case '_' : // Duplicar
                if ((top_type(stack)) == (STACK_CHAR)){
                    pop(stack, &val_char);
                    push(stack, STACK_CHAR, val_char);
                    push(stack, STACK_CHAR, val_char);
                } else if ((top_type(stack)) == (STACK_LONG)){
                    pop(stack, &val_long);
                    push(stack, STACK_LONG, val_long);
                    push(stack, STACK_LONG, val_long);
                } else if ((top_type(stack)) == (STACK_DOUBLE)){
                    pop(stack, &val_double);
                    push(stack, STACK_DOUBLE, val_double);
                    push(stack, STACK_DOUBLE, val_double);  
                } else if ((top_type(stack)) == (STACK_STRING)){
                    pop(stack, &val_pointer);
                    push(stack, STACK_STRING, val_pointer);
                    push(stack, STACK_STRING, val_pointer);
                } else { 
                    pop(stack, &val_int);
                    push(stack, STACK_LONG, val_int);
                    push(stack, STACK_LONG, val_int);
                }

                break;

            /*
            7 1 4 3 2 $
            7 1 4 3 1 
            case '$' : // Copia n-ésimo elemento para o topo da stack, 0 é o topo da stack  
                switch (stack->type((stack_element->top) + 1) ){
                    case (STACK_INT):
                        (int)stack_element->top = val_int;
                        break;

                    case (STACK_LONG):
                        (long)stack_element->top = val_long;
                        break;

                    case (STACK_DOUBLE):
                        (double)stack_element->top = val_double;
                        break;

                    case (STACK_CHAR):
                        (char)stack_element->top = val_char;
                        break;
                    
                    case (STACK_STRING):
                        break;
                           
                }

                for (int i=0;i<(int)(stack->capacity);i++){
                    if ((top_type(stack)) == (STACK_CHAR)){
                        pop(stack, &val_char);
                    } else if ((top_type(stack)) == (STACK_LONG)){
                        pop(stack, &val_long);
                    } else if ((top_type(stack)) == (STACK_DOUBLE)){
                        pop(stack, &val_double); 
                    } else if ((top_type(stack)) == (STACK_INT))
                        pop(stack, &val_int);
                    } else {
                        pop(stack, &val_pointer);
                    }
                }
                for (int j=0;j<(int)(stack->capacity);j++){
                    if ((top_type(stack)) == (STACK_CHAR)){
                        push(stack, STACK_CHAR, val_char);
                    } else if ((top_type(stack)) == (STACK_LONG)){
                        push(stack, STACK_LONG, val_long);
                    } else if ((top_type(stack)) == (STACK_DOUBLE)){
                        push(stack, STACK_DOUBLE, val_double); 
                    } else if ((top_type(stack)) == (STACK_INT)
                        push(stack, STACK_INT,val_int);
                    } else {
                        push(stack, STACK_STRING,val_pointer);
                    }
                }   
                    
                break;


            
            */
            case '\\n': // Trocar os dois elementos do topo da stack
                char aux2[2]; 
                for (int i=0;i<2;i++){
                    switch (top_type(stack)){
                        case (STACK_INT):
                            pop(stack, &val_int);
                            aux2[i] = &val_int;
                            break;

                        case (STACK_LONG):
                            pop(stack, &val_long);
                            aux2[i] = &val_long;
                            break;

                        case (STACK_DOUBLE):
                            pop(stack, &val_double);
                            aux2[i] = &val_double;
                            break;

                        case (STACK_CHAR):
                            pop(stack, &val_char);
                            aux2[i] = &val_char;
                            break;

                        case (STACK_STRING):
                            break;            
                }

                push(stack, STACK_CHAR, aux2[0]);
                push(stack, STACK_CHAR, aux2[1]);

                break;
            
        }


    print_stack(stack);
    stack_size(stack);

}
