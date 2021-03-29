#ifndef stack_h
#define stack_h

#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING 8} TYPE;

#define INTEGER (LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)

typedef strct data{
	// futura union if needed
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
	//---------------------
} DATA;

typedef struct stack{
	DATA *stack;
	int size;
	int n_elems;
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int stack_empty(STACK *s);
void print_stack(STACK *s);
int stack_size(STACK *s);

#define STACK_OPERATION_PROTO(_type, _name)
	void push_##_name(STACK *s, _type val);