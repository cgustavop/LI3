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

    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
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

    switch(y.type){
        case 1 :
            push_LONG(s, y.LONG);
            break;

        case 2 :
            push_DOUBLE(s, y.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, y.CHAR);
            break;

        case 8 :
            push_STRING(s, y.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }

    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
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

    switch(y.type){
        case 1 :
            push_LONG(s, y.LONG);
            break;

        case 2 :
            push_DOUBLE(s, y.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, y.CHAR);
            break;

        case 8 :
            push_STRING(s, y.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }


    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }

    switch(z.type){
        case 1 :
            push_LONG(s, z.LONG);
            break;

        case 2 :
            push_DOUBLE(s, z.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, z.CHAR);
            break;

        case 8 :
            push_STRING(s, z.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
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

    
    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
    
}

/**
 * @brief Devolve o valor guardado pela variável dada
 *
 * Inicializada por qualquer letra maiúscula 
 */
void letra(STACK *s, char letra){ // variaveis
    long a = letra;
    TYPE x = (s->array[a-65].type);

    switch(x){
        case 1 :
            push_LONG(s, s->array[a-65].LONG);
            break;

        case 2 :
            push_DOUBLE(s, (s->array[a-65]).DOUBLE);
            break;

        case 4 :
            push_CHAR(s, (s->array[a-65]).CHAR);
            break;

        case 8 :
            push_STRING(s, (s->array[a-65]).STRING);
            break;

        default:
            push_CHAR(s, letra);
    }
}

/**
 * @brief Guarda o elemento no topo da stack na variável dada
 *
 * Inicializada com o token ":" mais uma letra maiúscula
 */
void atributo(STACK *s, char *letra){ // variaveis
    long a = (char)*letra;
    DATA x = pop(s);

    switch(x.type){
        case 1 :
            s->array[a-65].type = LONG;
            s->array[a-65].LONG = x.LONG;
            push_LONG(s, x.LONG);
            break;

        case 2 :
            s->array[a-65].type = DOUBLE;
            s->array[a-65].DOUBLE = x.DOUBLE;
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            s->array[a-65].type = CHAR;
            s->array[a-65].CHAR = x.CHAR;
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            s->array[a-65].type = STRING;
            s->array[a-65].STRING = x.STRING;
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
}

/**
 * @brief if then else com os 3 elementos anteriores
 *
 * Inicializada com o token "?
 */
void question(STACK *s){ // if then else com os 3 elementos anteriores
    DATA z = pop(s);
    DATA y = pop(s);
    DATA x = pop(s);

    switch(x.type){   
        case 1 :
            if (x.LONG != 0){
                switch(y.type){
                    case 1:
                        push_LONG(s, y.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, y.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, y.CHAR);
                        break;

                    case 8:
                        push_STRING(s, y.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
        
            } else {
                switch(z.type){
                    case 1:
                        push_LONG(s, z.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, z.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, z.CHAR);
                        break;

                    case 8:
                        push_STRING(s, z.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
            }
            break;
    
        case 2 :
            if (x.DOUBLE != 0){
                                switch(y.type){
                    case 1:
                        push_LONG(s, y.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, y.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, y.CHAR);
                        break;

                    case 8:
                        push_STRING(s, y.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
        
            } else {
                switch(z.type){
                    case 1:
                        push_LONG(s, z.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, z.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, z.CHAR);
                        break;

                    case 8:
                        push_STRING(s, z.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
            }
            break;

        case 4 :
            if (x.CHAR != '0'){
                switch(y.type){
                    case 1:
                        push_LONG(s, y.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, y.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, y.CHAR);
                        break;

                    case 8:
                        push_STRING(s, y.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
        
            } else {
                switch(z.type){
                    case 1:
                        push_LONG(s, z.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, z.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, z.CHAR);
                        break;

                    case 8:
                        push_STRING(s, z.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
            }
            break;

        case 8 :
            if (strcmp(x.STRING, "0") != 0){
                switch(y.type){
                    case 1:
                        push_LONG(s, y.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, y.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, y.CHAR);
                        break;

                    case 8:
                        push_STRING(s, y.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
        
            } else {
                switch(z.type){
                    case 1:
                        push_LONG(s, z.LONG);
                        break;

                    case 2:
                        push_DOUBLE(s, z.DOUBLE);
                        break;

                    case 4:
                        push_CHAR(s, z.CHAR);
                        break;

                    case 8:
                        push_STRING(s, z.STRING);
                        break;

                    case 16 :                                    // case de ser 16, de x ser do tipo array
                        break;
                }
            }

            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
                break;
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
    assert(fgets(aux,10240,stdin)!=NULL);
    assert(aux[strlen(aux)-1]=='\n');
    aux[strlen(aux)-1] = '\0';
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
    
    switch(x.type){
        case 1 :
            push_LONG(s,x.LONG);
            break;

        case 2 :
            push_DOUBLE(s,x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :
            push_ARRAY(s, x.ARRAY);                                   // case de ser 16, de x ser do tipo array
            break;        
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

    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_LONG(s, (long)x.DOUBLE);
            break;

        case 4 :
            push_LONG(s, (long)x.CHAR);
            break;

        case 8 :      
            push_LONG(s, atof(x.STRING));
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
}
/**
 * @brief Converte o elemento no topo da stack num double
 *
 * Inicializada com o token "f"
 */
void doublez(STACK *s){ // CONVERTE O ELEMENTO NO TOPO DA STACK NUM DOUBLE "f"
    DATA x = pop(s);

    switch(x.type){
        case 1 :
            push_DOUBLE(s, (double)x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_DOUBLE(s, (double)x.CHAR);
            break;

        case 8 :      
            push_DOUBLE(s, atof(x.STRING));
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
}
/**
 * @brief Converte o elemento no topo da stack num char
 *
 * Inicializada com o token "c"
 */
void charz(STACK *s){ //   CONVERTE O ELEMENTO NO TOPO DA STACK NUM CARATERE "c"
    DATA x = pop(s);

    switch(x.type){
        case 1 :
            push_CHAR(s, (char)x.LONG);
            break;

        case 2 :
            push_CHAR(s, (char)x.DOUBLE);
            break;

        case 4 :
            push_CHAR(s, x.CHAR);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
}
/**
 * @brief Converte o elemento no topo da stack numa string
 *
 * Inicializada com o token "s"
 */
void stringz(STACK *s){ // CONVERTE O ELEMENTO NO TOPO DA STACK NUMA STRING "s"
    DATA x = pop(s);

    switch(x.type){
        case 1 :
            push_LONG(s, x.LONG);
            break;

        case 2 :
            push_DOUBLE(s, x.DOUBLE);
            break;

        case 4 :
            push_STRING(s, x.STRING);
            break;

        case 8 :
            push_STRING(s, x.STRING);
            break;

        case 16 :                                    // case de ser 16, de x ser do tipo array
            break;
    }
}