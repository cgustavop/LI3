/**
 * @file Ficheiro que contem a nossa versão do stack.
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "maths.h"
#include "logics.h"
#include "manipulations.h"

int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}
/**
 * /brief Cria stacks de diferentes tipos
 *
 * Recebe os tipos dos quais serão feitos os arrays da nossa stack e reserva a memória necessária definindo os parâmetros da capacidade e o topo nesse array.
 * No caso de não haver memória suficiente para alocar um novo array resulta num aviso de erro.
 * 
 * @returns um array representante da nova stack.
 */
STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->size = 100;
	s->stack = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}

void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 100;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}

DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}

DATA top(STACK *s){
	return s->stack[s->n_elems -1];
}

int is_empty(STACK *s){
	return (s->n_elems == 0);
}

void print_stack(STACK *s){
	for(int i = 0; i <s->n_elems; i++){
		DATA elem = s->stack[i];
		TYPE type = elem.type;
		switch(type){
			case LONG: printf("%ld", elem.LONG);
				break;
			case DOUBLE: printf("%g", elem.DOUBLE);
				break;
			case CHAR: printf("%c", elem.CHAR);
				break;
			case STRING: printf("%s", elem.STRING);
				break;
		}
	}
	printf("\n");
}

void push_LONG(STACK *s, long val){
		DATA elem;
		elem.type = LONG;
		elem.LONG = val;
		push(s, elem);
	}

void push_DOUBLE(STACK *s, double val){
		DATA elem;
		elem.type = DOUBLE;
		elem.DOUBLE = val;
		push(s, elem);
	}

void push_CHAR(STACK *s, char val){
		DATA elem;
		elem.type = CHAR;
		elem.CHAR = val;
		push(s, elem);
	}

void push_STRING(STACK *s, char * val){
		DATA elem;
		elem.type = STRING;
		elem.STRING = val;
		push(s, elem);
	}

long pop_LONG(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == LONG);
		return elem.LONG;
	}

double pop_DOUBLE(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == DOUBLE);
		return elem.DOUBLE;
	}

char pop_CHAR(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == CHAR);
		return elem.CHAR;
	}

char * pop_STRING(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == STRING);
		return elem.STRING;
	}