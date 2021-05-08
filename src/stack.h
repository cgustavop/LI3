/**
 * @file stack.h
 * @brief Header que inicializa as funções do ficheiro stack.c
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <stdbool.h>
#include <assert.h>

<<<<<<< HEAD
/** Atribuição de constantes aos tipos (masks) */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8, ARRAY = 16} TYPE;

/* pré definição da stack */
=======
/**
 * Oferece a possibilidade de nomear types por constantes
 *
 * Recebe os diferentes tipos e atribui-lhes uma constante
 * LONG = 1
 * DOUBLE = 2
 * CHAR = 4
 * STRING= 8
 *
 * @returns uma constante representativa de um tpe
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8, ARRAY = 16, BLOCO = 32} TYPE;
>>>>>>> 618f59dc37240838aa51246e629db9f242be4390
struct stack;

/** pré definição dos tipos stack */
typedef struct stack STACK;

/** Tipos possíveis de data */
typedef struct data {
	/** forma de identificar um tipo */
	TYPE type;
	/** tipo long */
	long LONG;
	/** tipo double */
	double DOUBLE;
	/** tipo char */
	char CHAR;
	/** tipo string */
	char *STRING;
	/** tipo array */
	STACK *ARRAY;
	char *BLOCO;
} DATA;

/** Stack */
typedef struct stack{
<<<<<<< HEAD
	/** array com todos os possíveis chars para atributos (abcedário) */
	DATA array[26];
	/** input da stack */
=======
>>>>>>> 618f59dc37240838aa51246e629db9f242be4390
	DATA *stack;
	/** espaço de memória total que a stack permite */
	int size;
	/** número de elementos dados para a stack */
	int n_elems;
} STACK;

void parse(char *line);
int has_type(DATA elem, int mask);
STACK *new_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);
void print_array(STACK *s);
void push_LONG(STACK *s, long val);
void push_DOUBLE(STACK *s, double val);
void push_CHAR(STACK *s, char val);
void push_STRING(STACK *s, char * val);
void push_ARRAY(STACK *s, STACK * val);
void push_BLOCO(STACK *s, char * val);
long pop_LONG(STACK *s);
double pop_DOUBLE(STACK *s);
char pop_CHAR(STACK *s);
char *pop_STRING(STACK *s);
STACK *pop_ARRAY(STACK *s);
void allocvars(DATA *array);

#endif