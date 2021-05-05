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
    while(aux->n_elems > 0){
	DATA x = pop(aux);
                            // case quando x é long
            switch(x.type){                                     
                case 1 :                                        
                push_LONG(pri, x.LONG);
                break;

                case 2 :                                        
                push_DOUBLE(pri, x.DOUBLE);
                break;

                case 4 :                                                                              
                push_CHAR(pri, x.CHAR);
                break;

                case 8 :                                        
                push_STRING(pri, x.STRING);
                break;

                case 16 :
                push_ARRAY(pri, x.ARRAY);                                   
                break;
            }
    }
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
            break;

        case 16 :              
            push_LONG(s, x.ARRAY->n_elems);
            break;
    }
}
/*
void despejo(STACK *s){
    DATA x = pop(s);

    switch(x.type){
        case 1 :
            break;

        case 2 :
            break;

        case 4 :
            break;

        case 8 :
            break;

        case 16 :
            concatenar(s, x.ARRAY);
            break;
    }
} */

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

void concatvar(STACK *s, long i){
    STACK *aux = s;
    STACK *aux2 = s;
    
    while(i > 0){

        aux2 = s;

        concatenar(aux,aux2);
        
        i--;
    }

    concatenar(s,aux);
}   















