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

/*
void concatvar(STACK *s, long i){
	while(i > 0){
	concatenar(s,s);
    i--;
    }   
}
*/

void range(STACK *s){
    DATA x = pop(s);
    long i;

    switch(x.type){
        case 1 :
            for(i = 0;i<=x.LONG;i++)
                push_LONG(s, i);
            break;

        case 2 :
            break;

        case 4 :
            break;

        case 8 :
            break;

        case 16 :
            
            break;
    }
}