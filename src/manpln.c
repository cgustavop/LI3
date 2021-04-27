/**
 * @file manpln.c
 * @brief Ficheiro com funções de manipulação da stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "manpln.h"
#include "stack.h"
/**
 * @brief Duplica o elemento no topo da stack
 *
 * Inicializada com o token "_"
 */
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
/**
 * @brief Troca os 2 elementos no topo da stack
 *
 * Inicializada com o token "\"
 */
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

/**
 * @brief Roda os 3 elementos no topo da stack
 *
 * Inicializada com o token "@"
 */
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
/**
 * @brief Copia o n-ésimo elemento para o topo da stack
 *
 * Inicializada com os tokens "n $"
 */
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
void letraA(STACK *s, char letra){ // variaveis
    long a = letra;
    TYPE x = (s->array[a-65].type);
    if (x == LONG) {
        push_LONG(s, s->array[a-65].LONG);
    }
    else if (x == DOUBLE) {
        push_DOUBLE(s, (s->array[a-65]).DOUBLE);
    }
    else if (x == CHAR) {
        push_CHAR(s, (s->array[a-65]).CHAR);
    }
    else if (x == STRING) {
        push_STRING(s, (s->array[a-65]).STRING);
    }
    else push_CHAR(s, letra);
}

void atributoA(STACK *s, char letra){ // variaveis
    long a = letra;
    DATA x = pop(s);
    if (has_type(x, LONG)) {
        s->array[a-65].type = LONG;
        s->array[a-65].LONG = x.LONG;
        push_LONG(s, x.LONG);

    } else if (has_type(x, DOUBLE)) {
        s->array[a-65].type = DOUBLE;
        s->array[a-65].DOUBLE = x.DOUBLE;
        push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, CHAR)) {
        s->array[a-65].type = CHAR;
        s->array[a-65].CHAR = x.CHAR;
        push_CHAR(s, x.CHAR);

    } else if (has_type(x, STRING)) {
        s->array[a-65].type = STRING;
        s->array[a-65].STRING = x.STRING;
        push_STRING(s, x.STRING);
    }
}

void question(STACK *s){ // if then else com os 3 elementos anteriores
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);

    if (has_type(x, LONG)) {
        if (x.LONG != 0){
            if (has_type(y, LONG))
                push_LONG(s, y.LONG);

            else if (has_type(y, DOUBLE))
                push_DOUBLE(s, y.DOUBLE);

            else if (has_type(y, CHAR))
                push_CHAR(s, y.CHAR);
        
            else if (has_type(y, STRING))
                push_STRING(s, y.STRING);
        
        } else {
            if (has_type(z, LONG))
                push_LONG(s, z.LONG);

            else if (has_type(z, DOUBLE))
                push_DOUBLE(s, z.DOUBLE);

            else if (has_type(z, CHAR))
                push_CHAR(s, z.CHAR);

            else if (has_type(z, STRING))
                push_STRING(s, z.STRING);
        }
    }

    if (has_type(x, CHAR)) {
        if (x.CHAR != '0'){
            if (has_type(y, LONG))
                push_LONG(s, y.LONG);

            else if (has_type(y, DOUBLE))
                push_DOUBLE(s, y.DOUBLE);

            else if (has_type(y, CHAR))
                push_CHAR(s, y.CHAR);
        
            else if (has_type(y, STRING))
                push_STRING(s, y.STRING);
        
        } else {
            if (has_type(z, LONG))
                push_LONG(s, z.LONG);

            else if (has_type(z, DOUBLE))
                push_DOUBLE(s, z.DOUBLE);

            else if (has_type(z, CHAR))
                push_CHAR(s, z.CHAR);

            else if (has_type(z, STRING))
                push_STRING(s, z.STRING);
        }
    }

    if (has_type(x, DOUBLE)){
        if (x.DOUBLE != 0){
            if (has_type(y, LONG))
                push_LONG(s, y.LONG);

            else if (has_type(y, DOUBLE))
                push_DOUBLE(s, y.DOUBLE);

            else if (has_type(y, CHAR))
                push_CHAR(s, y.CHAR);
        
            else if (has_type(y, STRING))
                push_STRING(s, y.STRING);
      
        } else {
            if (has_type(z, LONG))
                push_LONG(s, z.LONG);

            else if (has_type(z, DOUBLE))
                push_DOUBLE(s, z.DOUBLE);

            else if (has_type(z, CHAR))
                push_CHAR(s, z.CHAR);

            else if (has_type(z, STRING))
                push_STRING(s, z.STRING);
        }
    }

    if (has_type(x, STRING)) {
        if (strcmp(x.STRING,"0") != 0){
            if (has_type(y, LONG))
                push_LONG(s, y.LONG);

            else if (has_type(y, DOUBLE))
                push_DOUBLE(s, y.DOUBLE);

            else if (has_type(y, CHAR))
                push_CHAR(s, y.CHAR);
        
            else if (has_type(y, STRING))
                push_STRING(s, y.STRING);
        
        } else {
            if (has_type(z, LONG))
                push_LONG(s, z.LONG);

            else if (has_type(z, DOUBLE))
                push_DOUBLE(s, z.DOUBLE);

            else if (has_type(z, CHAR))
                push_CHAR(s, z.CHAR);

            else if (has_type(z, STRING))
                push_STRING(s, z.STRING);
        }
    }
}

/**
 * @brief Leitura de uma linha
 *
 * Inicializada com o token "l"
 *
 */
void lerl(STACK *s){
    char aux[10240];
    assert(fgets(aux,10240,stdin)!=NULL);
    assert(aux[strlen(aux)-1]=='\n');
    aux[strlen(aux)-1] = '\0';
    push_STRING(s,aux);
}


void lert(STACK *s){ // t
    char aux[10240];
    while (fgets(aux, 10240, stdin) != NULL){
       fgets(aux, 10240, stdin);
    }

    if (feof(stdin))
       push_STRING(s,aux);
}

/**
 * @brief Imprime o topo da stack
 *
 * Inicializada com o token "p"
 *
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



//CONVERSÕES
/**
 * @brief Converte o elemento no topo da stack num inteiro
 *
 * Inicializada com o token "i"
 */
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
/**
 * @brief Converte o elemento no topo da stack num double
 *
 * Inicializada com o token "f"
 */
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
/**
 * @brief Converte o elemento no topo da stack num char
 *
 * Inicializada com o token "c"
 */
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
/**
 * @brief Converte o elemento no topo da stack numa string
 *
 * Inicializada com o token "s"
 */
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