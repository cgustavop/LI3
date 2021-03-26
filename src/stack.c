/**
 * @file Ficheiro que contem a nossa versão do stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY (-1)
#define STACK_EMPTY INT_MIN
#define STACK_OPERATION(_type, _name)         
  
STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)


// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O stack.c -lm

/**
 * \brief Conjunto de funções utilizadas numa biblioteca default stack
 *
 * Realização da função PUSH, POP, PRINT_STACK, STACK_SIZE
 *
 * Print do tamanho e do resultado da operação submetida ao stack
 */

int mystack[100];
int top = EMPTY;

int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}

int PUSH(int value){

	if (top >= 99) 
         return false;

    top++;
    mystack[top] = value;
    return true;
}

int POP(){

    if (top == EMPTY) return STACK_EMPTY;

    int result = mystack[top];
    top--;
    return result;
}

void PRINT_STACK() {
    int i;

    for(i= 0;i<=top;i++) {
        DATA elem = mystack[i];
        TYPE type = elem.type;

        switch(type) {

        case LONG:
            printf("%ld", elem.LONG); 
            break;

        case DOUBLE:
            printf("%g", elem.DOUBLE); 
            break;

        case CHAR:
            printf("%c", elem.CHAR); 
            break;

        case STRING:
            printf("%s", elem.STRING); 
            break;
        }
    }
}  

int STACK_SIZE(){ 
    int p;

    while ( (p = POP() ) != STACK_EMPTY )
        return (sizeof(p));
    
    return 0;
}