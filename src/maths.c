/**
 * @file maths.c
 * @brief Ficheiro com funções relativas a operações matemáticas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "maths.h"
#include "stack.h"


/**
 * @brief Soma de dois elementos da stack
 *
 * Inicializada com o token "+"
 */
void soma(STACK *s){ // SOMAR "+"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, y.LONG + x.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, y.DOUBLE + x.LONG);
                break;

                case 4 :                                        // case quando y é char enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s,  y.LONG + x.DOUBLE);
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s,  y.DOUBLE + x.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char
                push_DOUBLE(s, x.CHAR);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é string
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
                break;

    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "+"

/**
 * @brief Subtração entre dois elementos da stack
 *
 * Inicializada com o token "-"
 */
void subtrai(STACK *s){ // SUBTRAIR "-"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, y.LONG - x.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, y.DOUBLE - x.LONG);
                break;

                case 4 :                                        // case quando y é char enquanto x é long                                       
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double                                            
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s, y.LONG - x.DOUBLE);
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char
                push_DOUBLE(s, x.CHAR);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é string
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
                break;

    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "-"

/**
 * @brief Multiplicação entre dois elementos da stack
 *
 * Inicializada com o token "*"
 */
void multiplica(STACK *s){ // MULTIPLICAR "*"

    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, x.LONG * y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, x.LONG * y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                       // case quando y é array enquanto x é long           
                while(x.LONG != 0){
                push_ARRAY(s, y.ARRAY);
                x.LONG --;
                }
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s, x.DOUBLE * y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :
                push_DOUBLE(s, x.DOUBLE);                       // case quando y é array enquanto x é double
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char                                                
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char
                push_CHAR(s, x.CHAR);
                break;

                case 16 :                                       // case quando y é array enquanto x é char
                push_CHAR(s, x.CHAR);
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;

                case 16 :                                       // case quando y é array enquanto x é string
                push_STRING(s, x.STRING);
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é string
            break;                                              // fim do case quando x é string

        case 16 :                                               // case quando x é array
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é array
                case 1 :                                        // case quando y é long enquanto x é array
                while(y.LONG != 0){
                push_ARRAY(s, x.ARRAY);
                y.LONG --;
                }
                break;

                case 2 :                                        // case quando y é double enquanto x é array
                push_ARRAY(s, x.ARRAY);
                break;

                case 4 :                                        // case quando y é char enquanto x é array
                push_ARRAY(s, x.ARRAY);
                break;

                case 8 :                                        // case quando y é string enquanto x é array
                push_ARRAY(s, x.ARRAY);
                break;

                case 16 :
                push_ARRAY(s, x.ARRAY);                         // case quando y é array enquanto x é array
                break;
            }
            break;
            

    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "*"

/**
 * @brief Divisão entre dois elementos da stack
 *
 * Inicializada com o token "/"
 */
void divide(STACK *s){ // DIVIDIR "/"

    DATA x = pop(s);
    DATA y = pop(s);

    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, y.LONG / x.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, y.DOUBLE / x.LONG);
                break;

                case 4 :                                        // case quando y é char enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s, y.LONG / x.DOUBLE);
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char

                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char
                push_DOUBLE(s, x.CHAR);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string                   
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é string
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "/"                                                                                              

/**
 * @brief Incrementação do elemento no topo da stack
 *
 * Inicializada com o token ")"
 */
void incrementa(STACK *s){ // INCREMENTAR ")"
    DATA x = pop(s);

    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            push_LONG(s, x.LONG + 1);
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            push_DOUBLE(s, x.DOUBLE + 1);
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            push_CHAR(s, x.CHAR + 1);
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            push_STRING(s, x.STRING);
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função ")"

/**
 * @brief Decrementação do elemento no topo da stack
 *
 * Inicializada com o token "("
 */
void decrementa(STACK *s){ // DECREMENTAR "("
    DATA x = pop(s);

    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            push_LONG(s, x.LONG - 1);
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            push_DOUBLE(s, x.DOUBLE - 1);
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            push_CHAR(s, x.CHAR - 1);
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            push_STRING(s, x.STRING);
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "("

/**
 * @brief Módulo entre dois elementos da stack
 *
 * Inicializada com o token "%"
 */
void modulo(STACK *s){ //  MÓDULO "%"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){                                             // switch case para os diferentes tipos de x                                                 
        case 1 :                                                // case quando x é long 
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, y.LONG % x.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, fmod(y.DOUBLE, x.LONG));
                break;

                case 4 :                                        // case quando y é char enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s, fmod(y.LONG, x.DOUBLE));
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s, fmod(y.DOUBLE, x.DOUBLE));
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char                                      
                push_DOUBLE(s, x.CHAR);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;                                          // fim do switch case para os diferentes tipos de y enquanto x é string

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }
            break;                                              // fim do case quando x é string 

        case 16 :
            break;                                           

    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "%"

/**
 * @brief Exponenciação de um elemento segundo outro
 *
 * Inicializada com o token "#"
 */
void expoente(STACK *s){ // EXPONENCIAÇÃO "#"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){                                             // switch case para os diferentes tipos de x
        case 1 :                                                // case quando x é long
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é long
                case 1 :                                        // case quando y é long enquanto x é long
                push_LONG(s, powl(y.LONG,x.LONG));
                break;

                case 2 :                                        // case quando y é double enquanto x é long
                push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
                break;

                case 4 :                                        // case quando y é char enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 8 :                                        // case quando y é string enquanto x é long
                push_LONG(s, x.LONG);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é long
            break;                                              // fim do case quando x é long

        case 2 :                                                // case quando x é double
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é double
                case 1 :                                        // case quando y é long enquanto x é double
                push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
                break;

                case 2 :                                        // case quando y é double enquanto x é double
                push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
                break;

                case 4 :                                        // case quando y é char enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :                                        // case quando y é string enquanto x é double
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é double
            break;                                              // fim do case quando x é double

        case 4 :                                                // case quando x é char
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é char
                case 1 :                                        // case quando y é long enquanto x é char
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é char
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é char
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :                                        // case quando y é string enquanto x é char
                push_DOUBLE(s, x.CHAR);
                break;

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é char
            break;                                              // fim do case quando x é char

        case 8 :                                                // case quando x é string
            switch(y.type){                                     // switch case para os diferentes tipos de y enquanto x é string
                case 1 :                                        // case quando y é long enquanto x é string
                push_LONG(s, y.LONG);
                break;

                case 2 :                                        // case quando y é double enquanto x é string
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :                                        // case quando y é char enquanto x é string
                push_STRING(s, x.STRING);
                break;

                case 8 :                                        // case quando y é string enquanto x é string
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;  

                case 16 :                                    // case de ser 16, de x ser do tipo array
                break;                                        
            }                                                   // fim do switch case para os diferentes tipos de y enquanto x é string
            break;                                              // fim do case quando x é string

        case 16 :                                    // case de ser 16, de x ser do tipo array
                break;

    }                                                           // fim do switch case para os diferentes tipos de x
}                                                               // fim da função "#"