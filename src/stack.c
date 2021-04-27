/**
 * @file stack.c
 * @brief Ficheiro que contém as funções relativas ao funcionamento da nossa stack
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "maths.h"
#include "logics.h"
#include "manpln.h"

/**
 * @brief Verifica o tipo de um elemento
 *
 * Recebendo um elemento do tipo DATA e uma mask analisa se o tipo do elemento coincide com o da máscara indicada.
 * 
 * @param elem Elemento que queremos avaliar
 * @param mask Máscara que representa um tipo de dados
 * @returns 0 se o elemento for do tipo da máscara e diferente de 0 caso contrário.
 */
int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}
/**
 * @brief Função que reserva memória para a stack
 *
 * Reserva a memória necessária definindo os parâmetros da capacidade e o topo da stack.
 *
 * @returns uma struct representante da stack
 */
STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->size = 100;
	s->array[0]= (DATA *) 10; s->array[1]= (DATA *) 11; s->array[2]= (DATA *) 12; s->array[3]= (DATA *) 13; s->array[4]= (DATA *) 14; s->array[5]= (DATA *) 15; // definição por omissão A a F
	s->array[13]= (DATA *) '\n'; s->array[18]= (DATA *) ' '; s->array[23]= (DATA *) 1; s->array[24]= (DATA *) 2; s->array[25]= (DATA *) 3; // definição por omissão N, S, X, Y, Z
	s->stack = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}
/**
 * @brief Faz push de um elemento para a stack
 *
 * Incrementa o indicador do topo da stack e insere o elemento dado.
 * Reserva espaço adicional para a stack caso necessário.
 * 
 * @param *s Struct onde se encontra a stack
 * @param elem Elemento para inserir na stack
 * @returns esta função não devolve nenhum valor
 */
void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 100;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}
/**
 * @brief Faz pop de um elemento para fora a stack
 *
 * Decrementa o indicador do topo da stack e insere o elemento dado.
 * 
 * @param *s Struct onde se encontra a stack
 * @returns elemento que saiu da stack
 */
DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}
/**
 * @brief Indica o elemento no topo da stack
 * 
 * @param *s Struct onde se encontra a stack
 * @returns o elemento no topo da stack
 */
DATA top(STACK *s){
	return s->stack[s->n_elems -1];
}
/**
 * @brief Indica se a stack está vazia
 * 
 * @param *s Struct onde se encontra a stack
 * @returns 0 se estiver vazia e um nº diferente de zero se não estiver
 */
int is_empty(STACK *s){
	return (s->n_elems == 0);
}
/**
 * @brief Imprime a stack
 * 
 * Percorre a stack e imprime os elementos nela contidos.
 *
 * @param *s Struct onde se encontra a stack
 * @returns esta função não devolve nenhum valor
 */
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
/**
 * @brief Função push para elementos do tipo LONG
 */
void push_LONG(STACK *s, long val){
		DATA elem;
		elem.type = LONG;
		elem.LONG = val;
		push(s, elem);
	}
/**
 * @brief Função push para elementos do tipo DOUBLE
 */
void push_DOUBLE(STACK *s, double val){
		DATA elem;
		elem.type = DOUBLE;
		elem.DOUBLE = val;
		push(s, elem);
	}
/**
 * @brief Função push para elementos do tipo CHAR
 */
void push_CHAR(STACK *s, char val){
		DATA elem;
		elem.type = CHAR;
		elem.CHAR = val;
		push(s, elem);
	}
/**
 * @brief Função push para elementos do tipo STRING
 */
void push_STRING(STACK *s, char * val){
		DATA elem;
		elem.type = STRING;
		elem.STRING = val;
		push(s, elem);
	}
/**
 * @brief Função pop para elementos do tipo LONG
 */
long pop_LONG(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == LONG);
		return elem.LONG;
	}
/**
 * @brief Função pop para elementos do tipo DOUBLE
 */
double pop_DOUBLE(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == DOUBLE);
		return elem.DOUBLE;
	}
/**
 * @brief Função pop para elementos do tipo CHAR
 */
char pop_CHAR(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == CHAR);
		return elem.CHAR;
	}
/**
 * @brief Função pop para elementos do tipo STRING
 */
char * pop_STRING(STACK *s){
		DATA elem = pop(s);
		assert(elem.type == STRING);
		return elem.STRING;
	}