#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "maths.h"
#include "stack.h"

void soma(STACK *s){ // SOMAR "+"
      
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

void subtrai(STACK *s){ // SUBTRAIR "-"
      
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

void multiplica(STACK *s){ // MULTIPLICAR "*"

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

void divide(STACK *s){ // DIVIDIR "/"

    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_DOUBLE(s, y.LONG / x.LONG);
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

void incrementa(STACK *s){ // INCREMENTAR ")"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG + 1);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE + 1);
    }
}

void decrementa(STACK *s){ // DECREMENTAR "("
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG - 1);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE - 1);
    }
}


void modulo(STACK *s){ //  MÓDULO "%"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG % x.LONG);
    }
}
void expoente(STACK *s){ // EXPONENCIAÇÃO "#"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, powl(y.LONG,x.LONG));
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, powf(y.DOUBLE,x.DOUBLE));
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, powf(y.DOUBLE,x.LONG));
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, powf(y.LONG,x.DOUBLE));
    }
}

void E(STACK *s){ // E "&"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG & x.LONG);
    }
}


void ou(STACK *s){ // OU "|"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG | x.LONG);
    }
}

void xor(STACK *s){ // XOR "^"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG ^ x.LONG);
    }
}

void not(STACK *s){ // NOT "~"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, (~x.LONG));
    }
}

void intz(STACK *s){ // CONVERTE O ELEMENTO NO TOPO DA STACK NUM INTEIRO "i"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)){
        push_LONG(s, (long)x.DOUBLE);
    }
    else if(has_type(x, CHAR)){
        push_LONG(s, (long)x.CHAR);
    }
    else if(has_type(x, STRING)){
        long temp = atof(x.STRING);      
        push_LONG(s,temp);
    }
}

void doublez(STACK *s){ // CONVERTE O ELEMENTO NO TOPO DA STACK NUM DOUBLE "f"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_DOUBLE(s, (double)x.LONG);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)){
        push_DOUBLE(s, (double)x.CHAR);
    }
    else if(has_type(x, STRING)){
        double temp = atof(x.STRING);      
        push_DOUBLE(s,temp);
    }
}

void charz(STACK *s){ //   CONVERTE O ELEMENTO NO TOPO DA STACK NUM CARATERE "c"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_CHAR(s, (char)x.LONG);
    }
    else if(has_type(x, DOUBLE)){
        push_CHAR(s, (char)x.DOUBLE);
    }
    else if(has_type(x, CHAR)){
        push_CHAR(s, x.CHAR);
    }
    else if(has_type(x, STRING)){
        push_STRING(s, x.STRING);
    }
}

void stringz(STACK *s){ // CONVERTE O ELEMENTO NO TOPO DA STACK NUMA STRING "s"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, x.LONG);
    }
    else if(has_type(x, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
    }
    else if(has_type(x, CHAR)){
        push_STRING(s, x.STRING);
    }
    else if(has_type(x, STRING)){
        push_STRING(s, x.STRING);
    }
}


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
    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, x.LONG);
        push_LONG(s, y.LONG);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_LONG(s, x.LONG);
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(x, LONG) && has_type(y, CHAR)){
        push_CHAR(s, x.CHAR);
        push_LONG(s, y.LONG);
    }
    else if(has_type(x, LONG) && has_type(y, STRING)){
        push_STRING(s, x.STRING);
        push_LONG(s, y.LONG);
    }
    else if(has_type(x, DOUBLE) && has_type(y, LONG)){
        push_LONG(s, x.LONG);
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(x, DOUBLE) && has_type(y, CHAR)){
        push_CHAR(s, x.CHAR);
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(x, DOUBLE) && has_type(y, STRING)){
        push_STRING(s, x.STRING);
        push_DOUBLE(s, y.DOUBLE);
    }
    else if(has_type(x, CHAR) && has_type(y, LONG)){
        push_LONG(s, x.LONG);
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(x, CHAR) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(x, CHAR) && has_type(y, CHAR)){
        push_CHAR(s, x.CHAR);
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(x, CHAR) && has_type(y, STRING)){
        push_STRING(s, x.STRING);
        push_CHAR(s, y.CHAR);
    }
    else if(has_type(x, STRING) && has_type(y, LONG)){
        push_LONG(s, x.LONG);
        push_STRING(s, y.STRING);
    }
    else if(has_type(x, STRING) && has_type(y, DOUBLE)){
        push_DOUBLE(s, x.DOUBLE);
        push_STRING(s, y.STRING);
    }
    else if(has_type(x, STRING) && has_type(y, CHAR)){
        push_CHAR(s, x.CHAR);
        push_STRING(s, y.STRING);
    }
    else if(has_type(x, STRING) && has_type(y, STRING)){
        push_STRING(s, x.STRING);
        push_STRING(s, y.STRING);
    }
}


void rodar(STACK *s){ // RODAR OS 3 ELEMENTOS NO TOPO DA STACK "@"
    DATA z = pop(s);
    DATA y = pop(s);
    DATA x = pop(s); // 3x 4y 7z -> 4y 7z 3x

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
void lerl(STACK *s){
    char aux[10240];
    assert(fgets(aux,10240,stdin)!=NULL);
    assert(aux[strlen(aux)-1]=='\n');
    aux[strlen(aux)-1] = '\0';
    push_STRING(s,aux);
}

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










