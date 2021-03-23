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

// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O stack.c -lm

/**
 * \brief Conjunto de funções utilizadas numa biblioteca default stack
 *
 * Realização da função PUSH e POP
 *
 * Print do tamanho e do resultado da operação submetida ao stack
 */

int mystack[100];
int top = EMPTY;

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

void PRINT_STACK(){
    int p;

    while ( (p = POP() ) != STACK_EMPTY ){
        printf("%d", p);
    }
    printf("\n");
}

int STACK_SIZE(){ 
    int p;

    while ( (p = POP() ) != STACK_EMPTY )
        return (sizeof(p));
    
    return 0;
}