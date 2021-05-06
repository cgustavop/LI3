/**
 * @file logics.h
 * @brief Header que inicializa as funções do ficheiro arrays.c
 */
#include "stack.h"
void inverteArray(STACK *input, STACK *output);
void concatenar(STACK *pri, STACK *sec);
void range(STACK *s);
//void despejo(STACK *s);
void sspace(STACK *s);
void nspace(STACK *s);
void seek(long n, STACK *array, STACK *stack);
void takeXstart(long n, STACK *array);
STACK *takeXend(long n, STACK *array);
void seeknstring(long n, char *string, STACK *stack);
void concatvar(STACK *s, long i);
void concatvarstr(char *string, long n);
void removeUltArray(STACK *stack, STACK *array);
void removePrimArray(STACK *stack, STACK *array);
void concatSTART(DATA elem, STACK* array);