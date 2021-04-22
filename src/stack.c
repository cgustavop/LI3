/**
 * @file Ficheiro que contem a nossa versão do stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

/// Struct que contém os elementos segundo o seu tipo
struct stack_element {
    enum stack_type type;
    union {
        char val_c;   ///< Elemento do tipo char
        int val_i;    ///< Elemento do tipo int
        long val_l;   ///< Elemento do tipo long   
        double val_d; ///< Elemento do tipo double
        void *val_p;  ///< Elemento do ser uma string
    } data;
} ;

/// Struct que representa os componentes da stack
struct stack {
    size_t top;                         ///< Topo da stack (sempre igual a 0)
    size_t capacity;                    ///< Tamanho da stack
    enum stack_type type;               ///< Indica o tipo do elemento da stack
    struct stack_element *elements;     ///< Elemento da stack
};

/**
 * Cria stacks de diferentes tipos
 *
 * Recebe os tipos dos quais serão feitos os arrays da nossa stack e reserva a memória necessária definindo os parâmetros da capacidade e o topo nesse array.
 * No caso de não haver memória suficiente para alocar um novo array resulta num aviso de erro.
 * 
 * @returns um array representante da nova stack.
 */
struct stack * create_stack(const size_t capacity){
    struct stack * new_stack = malloc(sizeof *new_stack);
    if ( !new_stack ) {
        perror("couldn't allocate memory for stack");
        exit(EXIT_FAILURE);
    }

    new_stack->capacity = capacity;
    new_stack->top = 0;

    new_stack->elements = malloc(sizeof *new_stack->elements * capacity);
    if ( !new_stack->elements ) {
        free(new_stack);
        perror("couldn't allocate memory for stack elements");
        exit(EXIT_FAILURE);
    }

    return new_stack;
}
/**
 * Indica o tipo do elemento no topo da stack
 *
 * @returns tipo do elemento no topo da stack.
 */
enum stack_type top_type(struct stack * stack){
  return stack->elements[--stack->top].type;
}

/**
 * Faz o push de um elemento para a stack
 *
 * Recebe o elemento e o seu tipo e compara para guardar no array do tipo correspondente.
 *
 * @returns void
 */

void push(struct stack * stack, const enum stack_type type, ...){
    if ( stack->top == stack->capacity ) {
        fprintf(stderr, "Stack full!\n");
        exit(EXIT_FAILURE);
    }

    va_list ap;
    va_start(ap, type);

    switch ( type ) {
        case STACK_CHAR:
          stack->elements[stack->top].data.val_c = (char) va_arg(ap, int);
        break;

        case STACK_INT:
          stack->elements[stack->top].data.val_i = va_arg(ap, int);
        break;

        case STACK_LONG:
          stack->elements[stack->top].data.val_l = va_arg(ap, long);
        break;

        case STACK_DOUBLE:
          stack->elements[stack->top].data.val_d = va_arg(ap, double);
        break;

        case STACK_STRING:
          stack->elements[stack->top].data.val_p = va_arg(ap, void *);
        break;

        default:
          fprintf(stderr, "Unknown type in stack_push()\n");
          exit(EXIT_FAILURE);
    }

    stack->elements[stack->top++].type = type;

    va_end(ap);
}

/**
 * Faz o pop de um elemento para fora da stack
 *
 * Retira um elemento da stack.
 *
 * @returns void
 */

void pop(struct stack * stack, void * p){

    if ( stack->top == 0 ) {
        fprintf(stderr, "Stack empty!\n");
        exit(EXIT_FAILURE);
    }

    switch ( stack->elements[--stack->top].type ) {
        case STACK_CHAR:
          *((char *) p) = stack->elements[stack->top].data.val_c;
        break;

        case STACK_INT:
          *((int *) p) = stack->elements[stack->top].data.val_i;
        break;

        case STACK_LONG:
          *((long *) p) = stack->elements[stack->top].data.val_l;
        break;

        case STACK_DOUBLE:
          *((double *) p) = stack->elements[stack->top].data.val_d;
        break;

        case STACK_STRING:
          *((void **) p) = stack->elements[stack->top].data.val_p;
        break;

        default:
          fprintf(stderr, "Unknown type in stack_pop()\n");
          exit(EXIT_FAILURE);
    }
}
/**
 * Imprime os elementos da stack
 *
 * @returns void
 */
// (verificar print_stack)
void print_stack(struct stack * stack){

  switch (top_type(stack)){
    case STACK_CHAR:
      printf("%c\n", stack->elements[stack->top].data.val_c);
    break;

    case STACK_LONG:
      printf("%ld\n", stack->elements[stack->top].data.val_l);
    break;

    case STACK_INT:
      printf("%i\n", stack->elements[stack->top].data.val_i);
    break;

    case STACK_DOUBLE:
      printf("%f\n", stack->elements[stack->top].data.val_d);
    break;

    case STACK_STRING:
      while (stack->top != '\0') 
        printf("%p", stack->elements[stack->top].data.val_p);
    break;

    default: 
      printf("%d\n", stack->elements[stack->top].data.val_i);
    break;

    }
}

/**
 * Destrói uma stack criada anteriormente
 *
 * Apagam-se a stack de forma a libertar memória que não esteja a ser utilizada.
 * 
 * @returns void
 */
void destroy_stack(struct stack * stack){
    free(stack->elements);
    free(stack);
} 

/**
 * Indica o tamanho da stack
 * 
 * @returns tamanho da stack.
 */

int stack_size(struct stack * stack){
  int cap = stack->capacity;
  return cap;
}

/*  Returns true if the stack is empty  */

bool stack_empty(struct stack * stack) {
    return stack->top == 0;
}

enum stack_type stack_peek(struct stack * stack) // se o topo for vazio então stack está empty
{
    if ( stack->top == 0 ) {
        fprintf(stderr, "Stack empty!\n");
        exit(EXIT_FAILURE);
    }

    return stack->elements[stack->top - 1].type;
}