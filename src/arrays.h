/**
 * @file logics.h
 * @brief Header que inicializa as funções do ficheiro arrays.c
 */
#include "stack.h"
void concatenar(STACK *pri, STACK *sec);
void range(STACK *s);
//void despejo(STACK *s);
void sspace(STACK *s);
void nspace(STACK *s);
void seek(long n, STACK *array, STACK *stack);
void concatvar(STACK *s, long i);