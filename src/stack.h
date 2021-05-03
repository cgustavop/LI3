/**
 * @file stack.h
 * @brief Header que inicializa as funções do ficheiro stack.c
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <stdbool.h>
#include <assert.h>

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
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8, ARRAY = 16} TYPE;
struct stack;
typedef struct stack STACK;
/**
 * Obtem os diferentes types do input utilizado masks
 *
 * Recebe os elementos dos quais pertencerão à stack e atribui-lhes a mask do tipo.
 * O tipo tem de ser obrigatoriamente um destes, não há caso para tal indefinição.
 * 
 * @returns um elemento com o tipo.
 */
typedef struct data {
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
	STACK *ARRAY;
} DATA;

/**
 * Cria stacks de diferentes tipos
 *
 * Recebe os elementos dos quais serão feitos os arrays da nossa stack e reserva a memória necessária definindo os parâmetros de tamanho, separando o array de letras.
 * No caso de não haver memória suficiente para alocar um novo array resulta num aviso de erro.
 * 
 * @returns um array representante da nova stack.
 */
typedef struct stack{
	DATA array[26];
	DATA *stack;
	int size;
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
void push_LONG(STACK *s, long val);
void push_DOUBLE(STACK *s, double val);
void push_CHAR(STACK *s, char val);
void push_STRING(STACK *s, char * val);
void push_ARRAY(STACK *s, STACK * val);
long pop_LONG(STACK *s);
double pop_DOUBLE(STACK *s);
char pop_CHAR(STACK *s);
char *pop_STRING(STACK *s);
STACK *pop_ARRAY(STACK *s);

#endif