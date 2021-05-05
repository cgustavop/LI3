/**
 * @file logics.c
 * @brief Ficheiro com funções relativas a operações com arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "logics.h"
#include "stack.h"
#include "eval.h"

void inverteArray(STACK *input, STACK *output) { // função auxiliar para inverter um array

    while(input->n_elems > 0){
    DATA x = pop(input);
                            // case quando x é long
            switch(x.type){                                     
                case 1 :                                        
                push_LONG(output, x.LONG);
                break;

                case 2 :                                        
                push_DOUBLE(output, x.DOUBLE);
                break;

                case 4 :                                                                              
                push_CHAR(output, x.CHAR);
                break;

                case 8 :                                        
                push_STRING(output, x.STRING);
                break;

                case 16 :
                push_ARRAY(output, x.ARRAY);                                   
                break;
            }
    }
}

void concatenar(STACK *pri, STACK *sec){

	STACK *aux = new_stack();

	while(sec->n_elems > 0){
	DATA x = pop(sec);
                            // case quando x é long
            switch(x.type){                                     
                case 1 :                                        
                push_LONG(aux, x.LONG);
                break;

                case 2 :                                        
                push_DOUBLE(aux, x.DOUBLE);
                break;

                case 4 :                                                                              
                push_CHAR(aux, x.CHAR);
                break;

                case 8 :                                        
                push_STRING(aux, x.STRING);
                break;

                case 16 :
                push_ARRAY(aux, x.ARRAY);                                   
                break;
            }
    }

    inverteArray(aux, pri);
    free(aux);     
}

void range(STACK *s){
    DATA x = pop(s);
    STACK *array = new_stack();
    long i;


    switch(x.type){
        case 1 :
            for (i = 0;i<x.LONG;i++) {
                push_LONG(array, i);
            }
                push_ARRAY(s, array);

            break;

        case 2 :
            break;

        case 4 :
            break;

        case 8 :
            push_LONG(s, strlen(x.STRING));
            break;

        case 16 :              
            push_LONG(s, x.ARRAY->n_elems);
            break;
    }
}

void sspace(STACK *s){
    DATA x = pop(s);
    long i;

    switch(x.type){
        case 1 :
            break;

        case 2 :
            break;

        case 4 :
            break;

        case 8 :
            for (i = 0; i <  (long)(strlen(x.STRING)); i++) {
                if(strchr(x.STRING, ' '))
                    push_ARRAY(s, x.ARRAY);
            }
            break;

        case 16 :
            break;
    }
}

void nspace(STACK *s){
    DATA x = pop(s);
    long i;

    switch(x.type){
        case 1 :
            break;

        case 2 :
            break;

        case 4 :
            break;

        case 8 :
            for (i = 0; i <  (long)(strlen(x.STRING)); i++) {
                if(strchr(x.STRING, '\n'))
                    push_ARRAY(s, x.ARRAY);
            }
            break;

        case 16 :
            break;
    
    }
}

void seek(long n, STACK *array, STACK *stack) {

    DATA nelem; long i = 0; //n++;

    while(i <= (array->n_elems) - n) {
        nelem = pop(array); 
        i++;
    } nelem = pop(array);

    switch(nelem.type){
        case 1 :
            push_LONG(stack, nelem.LONG);
            break;

        case 2 :
            push_DOUBLE(stack, nelem.DOUBLE);
            break;

        case 4 :
            push_CHAR(stack, nelem.CHAR);
            break;

        case 8 :
            push_STRING(stack, nelem.STRING);
            break;

        case 16 :
            push_ARRAY(stack, nelem.ARRAY);
            break;
    
    }
}

void takeXstart(long n, STACK *array) { // n <

    long vezes = (array->n_elems) - n;

    for(long i = 0; i < vezes; i++) {
        pop(array);
    }
}

STACK *takeXend(long n, STACK *array) { // n >

    STACK *store = new_stack();
    STACK *aux = new_stack();

    for(long i = 0; i < n; i++) {
        
        DATA z = pop(array);

        switch (z.type) {

            case 1 :
                push_LONG(aux, z.LONG);
                break;

            case 2 :
                push_DOUBLE(aux, z.DOUBLE);
                break;

            case 4 :
                push_CHAR(aux, z.CHAR);
                break;

            case 8 :
                push_STRING(aux, z.STRING);
                break;

            case 16 :
                push_ARRAY(aux, z.ARRAY);
                break;
        }
    }

    inverteArray(aux, store);
    free(aux); 
    return store;
}


void seeknstring(long n, char *string, STACK *stack) {

    char *ch = strndup(string + n, 1);
    push_STRING(stack, ch);
    
}

void concatvar(STACK *s, long i){
    
    STACK *aux = new_stack();
    STACK aux2 = *s;
    i--;

    while(i > 0){

        aux2 = *s;

        concatenar(aux,&aux2);
        
        i--;
    }

    concatenar(s,aux);
}   















