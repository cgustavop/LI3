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

typedef struct stack *Stack;

void parse(char *line);
Stack create_stack(const size_t capacity);
void destroy_stack(Stack stack);
void push(Stack stack, const enum stack_type type, ...);
void pop(Stack stack, void * p);
void top(Stack stack, void * p);
enum stack_type top_type(Stack stack);
enum stack_type stack_peek(Stack stack);
bool stack_empty(Stack stack);
int stack_size(Stack stack);
void print_stack(Stack stack);

#endif  
