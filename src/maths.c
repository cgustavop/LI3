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
    
    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG + x.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE + x.LONG);
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s,  y.LONG + x.DOUBLE);
                break;

                case 2 :
                push_DOUBLE(s,  y.DOUBLE + x.DOUBLE);
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }
}

/**
 * @brief Subtração entre dois elementos da stack
 *
 * Inicializada com o token "-"
 */
void subtrai(STACK *s){ // SUBTRAIR "-"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG - x.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE - x.LONG);
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s, y.LONG - x.DOUBLE);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }
}

/**
 * @brief Multiplicação entre dois elementos da stack
 *
 * Inicializada com o token "*"
 */
void multiplica(STACK *s){ // MULTIPLICAR "*"

    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, x.LONG * y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, x.LONG * y.DOUBLE);
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s, x.DOUBLE * y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }

}

/**
 * @brief Divisão entre dois elementos da stack
 *
 * Inicializada com o token "/"
 */
void divide(STACK *s){ // DIVIDIR "/"

    DATA x = pop(s);
    DATA y = pop(s);

    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG / x.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE / x.LONG);
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s, y.LONG / x.DOUBLE);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }

}

/**
 * @brief Incrementação do elemento no topo da stack
 *
 * Inicializada com o token ")"
 */
void incrementa(STACK *s){ // INCREMENTAR ")"
    DATA x = pop(s);

    switch(x.type){
        case 1 : 
            push_LONG(s, x.LONG + 1);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE + 1);
            break;

        case 4 : 
            push_CHAR(s, x.CHAR + 1);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;
    }
}

/**
 * @brief Decrementação do elemento no topo da stack
 *
 * Inicializada com o token "("
 */
void decrementa(STACK *s){ // DECREMENTAR "("
    DATA x = pop(s);

    switch(x.type){
        case 1 : 
            push_LONG(s, x.LONG - 1);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE - 1);
            break;

        case 4 : 
            push_CHAR(s, x.CHAR - 1);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;
    }
}

/**
 * @brief Módulo entre dois elementos da stack
 *
 * Inicializada com o token "%"
 */
void modulo(STACK *s){ //  MÓDULO "%"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG % x.LONG);
                break;

                case 2 :
                push_DOUBLE(s, fmod(y.DOUBLE, x.LONG));
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s, fmod(y.LONG, x.DOUBLE));
                break;

                case 2 :
                push_DOUBLE(s, fmod(y.DOUBLE, x.DOUBLE));
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }
}

/**
 * @brief Exponenciação de um elemento segundo outro
 *
 * Inicializada com o token "#"
 */
void expoente(STACK *s){ // EXPONENCIAÇÃO "#"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    switch(x.type){
        case 1 : 
            switch(y.type){
                case 1 :
                push_LONG(s, powl(y.LONG,x.LONG));
                break;

                case 2 :
                push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
                break;

                case 4 :
                push_LONG(s, x.LONG);
                break;

                case 8 :
                push_LONG(s, x.LONG);
                break;
            }
            break;

        case 2 :
            switch(y.type){
                case 1 :
                push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
                break;

                case 2 :
                push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
                break;

                case 4 :
                push_DOUBLE(s, x.DOUBLE);
                break;

                case 8 :
                push_DOUBLE(s, x.DOUBLE);
                break;
            }
            break;

        case 4 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_CHAR(s, x.CHAR);
                push_CHAR(s, y.CHAR);
                break;

                case 8 :
                push_DOUBLE(s, x.CHAR);
                break;
            }
            break;

        case 8 :
            switch(y.type){
                case 1 :
                push_LONG(s, y.LONG);
                break;

                case 2 :
                push_DOUBLE(s, y.DOUBLE);
                break;

                case 4 :
                push_STRING(s, x.STRING);
                break;

                case 8 :
                push_STRING(s, x.STRING);
                push_STRING(s, y.STRING);
                break;
            }
            break;

    }
}