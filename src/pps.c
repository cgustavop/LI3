#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "pps.h"
#include "stack.h"

void lerl(STACK *s){
    char aux[10240];
    assert(fgets(aux,10240,stdin)!=NULL);
    assert(aux[strlen(aux)-1]=='\n');
    aux[strlen(aux)-1] = '\0';
    push_STRING(s,aux);
}

/*
void lert(STACK *s){ // t
    char aux[100];
    assert(fgets(aux,sizeof aux,stdin));
    for(int i=0;aux[i];i++)
        pop(s, x.STRING)
}
*/

void printt(STACK *s){ // IMPRIME TOPO DA STACK "p"
    DATA x = pop(s);
    
    if (has_type(x, LONG)) {
        push_LONG(s,x.LONG);
    } else if (has_type(x, DOUBLE)) {
        push_DOUBLE(s,x.DOUBLE);
    } else if (has_type(x, CHAR)) {
        push_CHAR(s, x.CHAR);
    } else {
        push_STRING(s, x.STRING);            
    }
}
