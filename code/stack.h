#ifndef ___STACK_H___
#define ___STACK_H___

#include <stdbool.h>
#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

typedef struct data {
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
} DATA;

typedef struct stack{
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
long pop_LONG(STACK *s);
double pop_DOUBLE(STACK *s);
char pop_CHAR(STACK *s);
char * pop_STRING(STACK *s);

#endif