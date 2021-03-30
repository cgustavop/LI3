/**
 * @file Ficheiro que contem a nossa versão do stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#include <stack.h>

#define EMPTY (-1)
#define STACK_EMPTY INT_MIN
#define STACK_OPERATION(_type, _name)         \
  void push_##_name(STACK *s, _type val) {    \
    DATA elem;                                \
    elem.type = _name;                        \
    elem._name = val;                         \
    push(s, elem);                            \
  }                                           \
  _type pop_##_name(STACK *s) {               \
    DATA elem = pop(s);                       \
    assert(elem.type == _name);               \
    return elem._name;                        \
  }

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)        



// gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O stack.c -lm

/**
 * \brief Conjunto de funções utilizadas numa biblioteca default stack
 *
 * Realização da função push, pop, print_stack, stack_size
 *
 * Print do tamanho e do resultado da operação submetida ao stack
 */

int mystack[100];
int top = EMPTY;

/**
 * \brief 
 * 
 * @param elem
 * @param mask
 * @returns
 */

int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}

/* bem definido?
DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}

int is_empty(STACK *s) {
  return s->n_elems == 0;

*/

/**
 * \brief Função que faz push de um elemento do stack
 * 
 * Após receber um valor, insere-o no topo da stack.
 * 
 * @param value Valor a inserir no topo da stack
 * @param top Indica o índice do elemento no topo da stack
 * @param mystack Array onde a nossa stack se encontra guardada
 * 
 * @returns um inteiro representante de um valor boleano
 */
STACK *create_stack() {
  STACK *s = (STACK *) calloc(1, sizeof(STACK));
  //s->n_elems = 0;
  s->size = 100;
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}

int push(int value){

	if (top >= 99) 
         return false;

    top++;
    mystack[top] = value;
    return true;
}

void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {
    s->size += 100;
    s->stack = (DATA*) realloc(s->stack, s->size * sizeof(DATA));
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}

/**
 * \brief Função que faz pop de um elemento do stack
 * 
 * Altera o valor que indica o índice do elemento no topo da stack de modo a "retirar" elementos da stack.
 * 
 * @param top Indica o índice do elemento no topo da stack
 * @param result elemento que se encontra no topo da stack
 * 
 * @returns elemento que se encontra no topo da stack
 */

int pop(){

    if (top == EMPTY) return STACK_EMPTY;

    int result = mystack[top];
    top--;
    return result;
}

DATA pop(STACK *s) {
  s->n_elems--;s<-n_elems
  return s->stack[s->n_elems];
}
/**
 * \brief Função que imprime a stack
 * 
 * Vai imprimindo o array que guarda a nossa stack tendo em conta os tipos dos elementos presentes no array.
 * 
 * @param i Contador em função for
 * @param j Contador em função for
 * 
 * @returns void
 */

void print_stack() {
    int i;

    // temporario mas pode ajudar
    if ( (mystack[i] >= 'a' && mystack[i] <= 'z') || (mystack[i] >= 'A' && mystack[i] <= 'Z') ) {
        elem.type = CHAR;
    } else if (mystack[i] >= '0' && mystack[i] <= '9') {
        elem.type = LONG;
    } else if (for (j=0;j!='\0';j++)) {
        elem.type = STRING;
    } else elem.type = DOUBLE;
    //-------------------------------

    for(i=0;i<s->n_elems;i++) {
        DATA elem = s->mystack[i];
        TYPE type = elem.type;
        switch(type) {

        case LONG:
            printf("%ld ", elem.LONG); 
            break;

        case DOUBLE:
            printf("%g ", elem.DOUBLE); 
            break;

        case CHAR:
            printf("%c ", elem.CHAR); 
            break;

        case STRING:
            printf("%s ", elem.STRING); 
            break;
        }
    }
} 

/**
 * \brief Função que indica a dimensão da nossa stack
 *
 * @param p Contador
 * @returns o valor 0
 */

int stack_size(){ 
    int p;

    while ( (p = POP() ) != STACK_EMPTY )
        return (sizeof(p));
    
    return 0;
}

