#ifndef stack_h
#define stack_h

#include <stdbool.h>
#include <assert.h>

enum stack_type {
    STACK_CHAR,
    STACK_INT,
    STACK_LONG,
    STACK_DOUBLE,
    STACK_STRING
};

typedef struct stack * Stack;

int parse(char *line);
Stack create_stack(const size_t capacity);
void destroy_stack(Stack stack);
void push(Stack stack, const enum stack_type type, ...);
void pop(Stack stack, void *p);
void top(Stack stack, void *p);
enum stack_type top_type(Stack stack);
int stack_empty(Stack stack);
int stack_size(Stack stack);
void print_stack(struct stack *stack);

#endif  

/*
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

int parse(char *line);
int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
int stack_empty(STACK *s);
void print_stack(STACK *s);
int stack_size(STACK *s);
*/



