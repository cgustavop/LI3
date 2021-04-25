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
        push_STRING(s, x.STRING);
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
        push_STRING(s, x.STRING);
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
    DATA x = pop(s);

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
}

void copia(STACK *s){ // COPIA N-ÉSIMO ELEMENTO PARA O TOPO DA STACK "n $"
    DATA n = pop(s);
    DATA x = s->stack[(s->n_elems) - n.LONG - 1];
    pop(s);
    
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

void lerl(STACK *s){ // LÊ UMA LINHA ABAIXO "l" ---- AINDA POR ARRANJAR
    /*
    DATA r;
    char aux[100];

    memset(aux, '\0', sizeof(aux));
    assert(fgets(aux,sizeof aux,stdin));
    
    strncpy(r.STRING, aux, 100);
    
    for(int i=0;i < (sizeof aux);i++) r = pop(s);
        push_STRING(s, r.STRING);
    */
    char linee[10240];
    assert(fgets(linee,10240,stdin)!=NULL);
    assert(linee[strlen(linee)-1]=='\n');
    push_STRING(s,linee);
    /*
        if(has_type(r, LONG)) {
            push_LONG(s, r.LONG);
        }
        else if(has_type(r, DOUBLE)) {
            push_DOUBLE(s, r.DOUBLE);
        }
        else if(has_type(r, CHAR)) {
            push_CHAR(s, r.CHAR);
        }
        else if(has_type(r, STRING)) {
            push_STRING(s, r.STRING);
        }
    }*/
    //push_STRING(s, (char *)aux);
}
/*
void lerl(STACK *s){
    char *delims = " \t\n";
    char aux[1024];
    fgets(aux,sizeof aux,stdin);
    for(char *token = strtok(aux, delims);token != NULL;token = strtok(NULL, delims)){
        char *sobra1;
        char *sobra2;
      
        long val_l = strtol(token, &sobra1, 10);            PODE AJUDAR A FAZER A FUNÇÃO L
        double val_d = strtod(token, &sobra2);

        if(strlen(sobra1) == 0)
            push_LONG(s, val_l);
       
        else if(strlen(sobra2) == 0)
            push_DOUBLE(s, val_d);
    }
}
*/
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
    
    if (has_type(x, LONG))
        push_LONG(s,x.LONG);
    else if (has_type(x, DOUBLE))
        push_DOUBLE(s,x.DOUBLE);
    else if (has_type(x, CHAR))
        push_CHAR(s, x.CHAR);
    else if (has_type(x, STRING)) 
        push_STRING(s, x.STRING);            
}










