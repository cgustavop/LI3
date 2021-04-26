#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "manipulations.h"
#include "stack.h"

void duplica(STACK *s){ // DUPLICAR "_"

    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG);
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)){
        push_CHAR(s, x.CHAR);
        push_CHAR(s, x.CHAR);
    }
    else if(has_type(x, STRING)){
        push_STRING(s, x.STRING);
        push_STRING(s, x.STRING);
    }
}

void troca(STACK *s){ // TROCAR DOIS ELEMENTOS DO TOPO DA STACK "\"
    DATA y = pop(s);
    DATA x = pop(s);

    if(has_type(y, LONG)) {
        push_LONG(s, y.LONG);
    }
    else if(has_type(y, DOUBLE)) {
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(y, CHAR)) {
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(y, STRING)) {
        push_STRING(s, y.STRING);
    }

    if(has_type(x, LONG)) {
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)) {
        push_CHAR(s, x.CHAR);
    }
    else if(has_type(x, STRING)) {
        push_STRING(s, x.STRING);
    }
}


void rodar(STACK *s){ // RODAR OS 3 ELEMENTOS NO TOPO DA STACK "@"
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s); // a b c -> b c a

    if(has_type(y, LONG)) {
        push_LONG(s, y.LONG);
    }
    else if(has_type(y, DOUBLE)) {
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(y, CHAR)) {
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(y, STRING)) {
        push_STRING(s, y.STRING);
    }


    if(has_type(x, LONG)) {
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)) {
        push_CHAR(s, x.CHAR);
    }
    else if(has_type(x, STRING)) {
        push_STRING(s, x.STRING);
    }

    if(has_type(z, LONG)) {
        push_LONG(s, z.LONG);
    }
    else if(has_type(z, DOUBLE)) {
       push_DOUBLE(s, z.DOUBLE); 
    }
    else if(has_type(z, CHAR)) {
        push_CHAR(s, z.CHAR);
    }
    else if(has_type(z, STRING)) {
        push_STRING(s, z.STRING);
    }
}

void copia(STACK *s){ // COPIA N-ÉSIMO ELEMENTO PARA O TOPO DA STACK "n $"
    DATA n = pop(s);
    DATA x = s->stack[(s->n_elems) - n.LONG - 1];

    
    if(has_type(x, LONG)) {
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)) {
        push_CHAR(s, x.CHAR);
    }
    else if(has_type(x, STRING)) {
        push_STRING(s, x.STRING);
    }
    
}
/*
void HEX(STACK *s){ // variaveis
    DATA x = pop(s);
    DATA y = pop(s);

    if (has_type(x, CHAR) && x.CHAR = "A")
        if 
}


void question(STACK *s){ // if then else com os 3 elementos anteriores
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
}
*/