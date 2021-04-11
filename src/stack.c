/**
 * @file Ficheiro que contem a nossa versão do stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

/*
void print_stack(struct stack * stack) {
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

/*
int stack_size(struct stack * stack){ 
    int p;

    while ( (p = POP() ) != STACK_EMPTY )
        return (sizeof(p));
    
    return 0;
}

*/

//  Struct that contains stack element  

struct stack_element {
    enum stack_type type;
    union {
        char val_c;
        int val_i;  
        long val_l;     
        double val_d;
        void * val_p;
    } data;
};

//  Struct that contains stack 

struct stack {
    size_t top;
    size_t capacity;
    enum stack_type type;
    struct stack_element * elements;
};

//  Creates and returns a new stack of specified type and capacity  

struct stack * create_stack(const size_t capacity)
{
    struct stack * new_stack = malloc(sizeof *new_stack);
    if ( !new_stack ) {
        perror("couldn't allocate memory for stack");
        exit(EXIT_FAILURE);
    }

    new_stack->capacity = capacity; // definir capacidade
    new_stack->top = 0; // definir top

    new_stack->elements = malloc(sizeof *new_stack->elements * capacity);
    if ( !new_stack->elements ) {
        free(new_stack);
        perror("couldn't allocate memory for stack elements");
        exit(EXIT_FAILURE);
    }

    return new_stack;
}

//  Destroys a previously created stack 

void destroy_stack(struct stack * stack)
{
    free(stack->elements);
    free(stack);
} 

/*  Pushes an element onto the stack  */

void push(struct stack * stack, const enum stack_type type, ...)
{
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

        case STACK_LONG:
            stack->elements[stack->top].data.val_l = va_arg(ap, long);
            break;

        case STACK_INT:
            *((int *) p) = stack->elements[stack->top].data.val_i;
            break;

        case STACK_DOUBLE:
            stack->elements[stack->top].data.val_d = va_arg(ap, double);
            break;

        case STACK_STRING:
            stack->elements[stack->top].data.val_p = va_arg(ap, void *);
            break;

        default:
            fprintf(stderr, "Unknown type in push()\n");
            exit(EXIT_FAILURE);
    }

    stack->elements[stack->top++].type = type;

    va_end(ap);
}

/*  Pops an element from the stack  */

void pop(struct stack * stack, void * p)
{
    if ( stack->top == 0 ) {
        fprintf(stderr, "Stack empty!\n");
        exit(EXIT_FAILURE);
    }

    switch ( stack->elements[--stack->top].type ) {
        case STACK_CHAR:
            *((char *) p) = stack->elements[stack->top].data.val_c;
            break;

        case STACK_LONG:
            *((long *) p) = stack->elements[stack->top].data.val_l;
            break;

        case STACK_INT:
            *((int *) p) = stack->elements[stack->top].data.val_i;
            break;

        case STACK_DOUBLE:
            *((double *) p) = stack->elements[stack->top].data.val_d;
            break;

        case STACK_STRING:
            *((void **) p) = stack->elements[stack->top].data.val_p;
            break;

        default:
            fprintf(stderr, "Unknown type in pop()\n");
            exit(EXIT_FAILURE);
    }
}

/*  Returns the type of the top element on the stack  */

enum stack_type top_type(struct stack * stack)
{
    if ( stack->top == 0 ) {
        fprintf(stderr, "Stack empty!\n");
        exit(EXIT_FAILURE);
    }