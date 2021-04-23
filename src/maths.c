#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "maths.h"
#include "stack.h"

void soma(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, x.LONG + y.LONG);
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE + y.DOUBLE);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.LONG + y.DOUBLE);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, x.DOUBLE + y.LONG);
    }
}

void subtrai(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG - x.LONG);
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, y.DOUBLE - x.DOUBLE);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, y.DOUBLE - x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, y.LONG - y.DOUBLE);
    }
}

void multiplica(STACK *s){

    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, x.LONG * y.LONG);
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE * y.DOUBLE);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.LONG * y.DOUBLE);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, x.DOUBLE * y.LONG);
    }

}

void divide(STACK *s){

    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG / x.LONG);
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, y.DOUBLE / x.DOUBLE);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, y.DOUBLE / x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, y.LONG / x.DOUBLE);
    }

}

void incrementa(STACK *s){
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG + 1);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE + 1);
    }
}

void decrementa(STACK *s){
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG - 1);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE - 1);
    }
}


void modulo(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG % x.LONG);
    }
}
void expoente(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, pow(y.LONG,x.LONG));
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, pow(y.DOUBLE,x.DOUBLE));
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, pow(y.DOUBLE,x.LONG));
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, pow(y.LONG,y.DOUBLE));
    }
}

void E(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG & x.LONG);
    }
}


void ou(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG | x.LONG);
    }
}

void xor(STACK *s){
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG ^ x.LONG);
    }
}

void not(STACK *s){
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, (~x.LONG));
    }
}

//POR CORRIGIR CHAR E STRING
void duplica(STACK *s){
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

void apaga(STACK *s){
    pop(s);
}
/*
void troca(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(x, LONG)){
        push_LONG(s, y);
        push_LONG(s, x);
    }
    else if(has_type(x, LONG) && has_type(x, DOUBLE)){
        push_DOUBLE(s, y);
        push_LONG(s, x);
    }
    else if(has_type(x, LONG) && has_type(x, CHAR)){
        push_CHAR(s, y);
        push_LONG(s, x);
    }
    else if(has_type(x, LONG) && has_type(x, STRING)){
        push_STRING(s, y);
        push_LONG(s, x);
    }
    else if(has_type(x, DOUBLE) && has_type(x, LONG)){
        push_LONG(s, y);
        push_DOUBLE(s, x);
    }
    else if(has_type(x, DOUBLE) && has_type(x, DOUBLE)){
        push_DOUBLE(s, y);
        push_DOUBLE(s, x);
    }
    else if(has_type(x, DOUBLE) && has_type(x, CHAR)){
        push_CHAR(s, y);
        push_DOUBLE(s, x);
    }
    else if(has_type(x, DOUBLE) && has_type(x, STRING)){
        push_STRING(s, y);
        push_DOUBLE(s, x);
    }
    else if(has_type(x, CHAR) && has_type(x, LONG)){
        push_LONG(s, y);
        push_CHAR(s, x);
    }
    else if(has_type(x, CHAR) && has_type(x, DOUBLE)){
        push_DOUBLE(s, y);
        push_CHAR(s, x);
    }
    else if(has_type(x, CHAR) && has_type(x, CHAR)){
        push_CHAR(s, y);
        push_CHAR(s, x);
    }
    else if(has_type(x, CHAR) && has_type(x, STRING)){
        push_STRING(s, y);
        push_CHAR(s, x);
    }
    else if(has_type(x, STRING) && has_type(x, LONG)){
        push_LONG(s, y);
        push_STRING(s, x);
    }
    else if(has_type(x, STRING) && has_type(x, DOUBLE)){
        push_DOUBLE(s, y);
        push_STRING(s, x);
    }
    else if(has_type(x, STRING) && has_type(x, CHAR)){
        push_CHAR(s, y);
        push_STRING(s, x);
    }
    else if(has_type(x, STRING) && has_type(x, STRING)){
        push_STRING(s, y);
        push_STRING(s, x);
    }
}

void rodar(STACK *s){

}

void copia(STACK +S){

}
*/







