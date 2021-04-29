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
    
    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, x.LONG + y.LONG);
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, x.DOUBLE + y.DOUBLE);
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, x.LONG + y.DOUBLE);
    }
    else if (has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, x.DOUBLE + y.LONG);
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
    
    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, y.LONG - x.LONG);
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, y.DOUBLE - x.LONG);
    }
    else if (has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, y.LONG - y.DOUBLE);
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
    
    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, x.LONG * y.LONG);
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, x.LONG * y.DOUBLE);
    }
    else if (has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, x.DOUBLE * y.LONG);
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

    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, y.LONG / x.LONG);
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, y.DOUBLE / x.LONG);
    }
    else if (has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, y.LONG / x.DOUBLE);
    }

}
/**
 * @brief Incrementação do elemento no topo da stack
 *
 * Inicializada com o token ")"
 */
void incrementa(STACK *s){ // INCREMENTAR ")"
    DATA x = pop(s);

    if(has_type(x, 1)){
        push_LONG(s, x.LONG + 1);
    }
    else if(has_type(x, 2)){
        push_DOUBLE(s, x.DOUBLE + 1);
    }
    else if(has_type(x, 4)){
        push_CHAR(s, x.CHAR + 1);
    }
}
/**
 * @brief Decrementação do elemento no topo da stack
 *
 * Inicializada com o token "("
 */
void decrementa(STACK *s){ // DECREMENTAR "("
    DATA x = pop(s);

    if(has_type(x, 1)){
        push_LONG(s, x.LONG - 1);
    }
    else if(has_type(x, 2)){
        push_DOUBLE(s, x.DOUBLE - 1);
    }
    else if(has_type(x, 4)){
        push_CHAR(s, x.CHAR - 1);
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
    
    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, y.LONG % x.LONG);
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, fmod(y.DOUBLE ,x.LONG));
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, fmod(y.DOUBLE ,x.DOUBLE));
    }
    else if(has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, fmod(y.LONG ,x.DOUBLE));
    }
}
/**1
 * @brief Exponenciação de um elemento segundo outro
 *
 * Inicializada com o token "#"
 */
void expoente(STACK *s){ // EXPONENCIAÇÃO "#"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, 1) && has_type(y, 1)){
        push_LONG(s, powl(y.LONG,x.LONG));
    }
    else if(has_type(x, 2) && has_type(y, 2)){
        push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
    }
    else if(has_type(x, 1) && has_type(y, 2)){
        push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
    }
    else if (has_type(x, 2) && has_type(y, 1)){
        push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
    }
}
