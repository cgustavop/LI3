/**
 * @file logics.c
 * @brief Ficheiro com funções relativas a operações lógicas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "logics.h"
#include "stack.h"
/**
 * @brief E lógico entre dois elementos da stack
 *
 * Inicializada com o token "&"
 */
void E(STACK *s){ // E "&"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG & x.LONG);
    }
}
/**
 * @brief OU lógico entre dois elementos da stack
 *
 * Inicializada com o token "|"
 */
void ou(STACK *s){ // OU "|"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG | x.LONG);
    }
}
/**
 * @brief OU Exclusivo (aka XOR) entre dois elementos da stack
 *
 * Inicializada com o token "^"
 */
void xor(STACK *s){ // XOR "^"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG ^ x.LONG);
    }
}
/**
 * @brief Negação de um elemento da stack
 *
 * Inicializada com o token "~"
 */
void not(STACK *s){ // NOT "~"
    DATA x = pop(s);

    if(has_type(x, LONG)){
        push_LONG(s, (~x.LONG));
    }
}
/**
 * @brief Teste de igualdade entre os 2 elementos no topo da stack
 *
 * Inicializada com o token "="
 */
void igual(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        if (x.LONG == y.LONG)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (x.DOUBLE == y.DOUBLE)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    
    } else if(has_type(x, DOUBLE) && has_type(y, LONG)){
        if ((fmod(x.DOUBLE,1) == 0) && ((long)x.DOUBLE == y.LONG))
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    
    }else if(has_type(y, DOUBLE) && has_type(x, LONG)){
        if ((fmod(y.DOUBLE,1) == 0) && (x.LONG == (long)y.DOUBLE))
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    
    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (x.CHAR == y.CHAR)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strcmp(x.STRING,y.STRING) == 0)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    } else
        push_LONG(s, 0);
}
/**
 * @brief Teste de comparação dos 2 elementos no topo da stack
 *
 * Inicializada com o token "<"
 */
void menor(STACK *s){ // <
    DATA x = pop(s);
    DATA y = pop(s);

    if (has_type(x, LONG) && has_type(y, LONG)){
        if (y.LONG < x.LONG)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        if (y.DOUBLE < x.LONG)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (y.DOUBLE < x.DOUBLE)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        if (y.LONG < x.DOUBLE)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, LONG) && has_type(y, CHAR)){
        char a = x.LONG;
        if (y.CHAR < a)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, CHAR) && has_type(y, LONG)){
        char a = y.LONG;
        if (a < x.CHAR)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (y.CHAR < x.CHAR)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    
    } else if (has_type(x, CHAR) && has_type(y, STRING)){
        if ((char)(strlen(y.STRING)) < x.CHAR )
            push_LONG(s, 1);
        else 
            push_LONG(s, 0);
          
    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strlen(y.STRING) < strlen(x.STRING)) 
            push_LONG(s, 1);
        else
            push_LONG(s ,0);

    } else if (has_type(x, STRING) && has_type(y, CHAR)){
        if ( (y.CHAR) < (char)(strlen(x.STRING)) )
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    }
}
/**
 * @brief Teste de comparação dos 2 elementos no topo da stack
 *
 * Inicializada com o token ">"
 */
void maior(STACK *s){ // >
    DATA x = pop(s);
    DATA y = pop(s);

    if (has_type(x, LONG) && has_type(y, LONG)){
        if (y.LONG > x.LONG)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        if (y.DOUBLE > x.LONG)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (y.DOUBLE > x.DOUBLE)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        if (y.LONG > x.DOUBLE)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (y.CHAR > x.CHAR)
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    
    } else if (has_type(x, CHAR) && has_type(y, STRING)){
        if ((char)(strlen(y.STRING)) > x.CHAR )
            push_LONG(s, 1);
        else 
            push_LONG(s, 0);
          
    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strlen(y.STRING) > strlen(x.STRING)) 
            push_LONG(s, 1);
        else
            push_LONG(s ,0);

    } else if (has_type(x, STRING) && has_type(y, CHAR)){
        if ( (y.CHAR) > (char)(strlen(x.STRING)) )
            push_LONG(s, 1);
        else
            push_LONG(s, 0);

    }
}
/**
 * @brief Negação do elemento no topo da stack
 *
 * Inicializada com o token "!"
 */
void nono(STACK *s){ // !
    DATA x = pop(s);

    if (has_type(x, LONG)) {
        if (x.LONG == 0)
            push_LONG(s, 1);
        else if (x.LONG == 1)
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE)) {
        if (x.DOUBLE == 0)
            push_LONG(s, 1);
        else if (x.DOUBLE == 1)
            push_LONG(s, 0);

    } else if (has_type(x, CHAR)) {
        if (x.CHAR == '0')
            push_LONG(s, 1);
        else if (x.CHAR == '1')
            push_LONG(s, 0);

    } else if (has_type(x, STRING)){
        if (strcmp(x.STRING,"0") == 0)
            push_LONG(s, 1);
        else if ((strcmp(x.STRING,"1") == 0))
            push_LONG(s, 0);
    }
}


/**
 * @brief E lógico entre dois elementos da stack
 *
 * Inicializada com o token "e&"
 */
void eE(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    
    if (has_type(x, LONG) && has_type(y, LONG)){
        
        long a;
        if (x.LONG > y.LONG)
                a = x.LONG;
            else if (x.LONG < y.LONG)
                a = y.LONG;
            else
                a = y.LONG;

        if ( (x.LONG != 0) && (y.LONG != 0) )
            push_LONG(s, a);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        
        long a;
        if (x.DOUBLE > y.DOUBLE)
                a = (long)x.DOUBLE;
            else if (x.DOUBLE < y.DOUBLE)
                a = (long)y.DOUBLE;
            else
                a = (long)y.DOUBLE;

        if ( (x.DOUBLE != 0) && (y.LONG != 0) )
            push_LONG(s, a);
        else
            push_LONG(s, 0);

    } else if (has_type(x, DOUBLE) && has_type(y, LONG)){

        long a;
        if (x.DOUBLE > y.LONG)
                a = (long)x.DOUBLE;
            else if (x.DOUBLE < y.LONG)
                a = y.LONG;
            else
                a = y.LONG;

        if ( (x.DOUBLE != 0) && (y.LONG != 0) )
            push_LONG(s, a);
        else
            push_LONG(s, 0);

    } else if (has_type(x, LONG) && has_type(y, DOUBLE)){

        long a;
        if (x.LONG > y.DOUBLE)
                a = x.LONG;
            else if (x.LONG < y.DOUBLE)
                a = (long)y.DOUBLE;
            else
                a = (long)y.DOUBLE;

        if ( (x.LONG != 0) && (y.DOUBLE != 0) )
            push_LONG(s, a);
        else
            push_LONG(s, 0);
    }
}

/**
 * @brief OU lógico entre dois elementos da stack
 *
 * Inicializada com o token "e|"
 */
void eOU(STACK *s){
    DATA x = pop(s); //0
    DATA y = pop(s); //A
    
    if (has_type(x, LONG) && has_type(y, LONG)){
        long a;
        if (x.LONG < y.LONG) a = y.LONG;
        else a = x.LONG;

        if ( (x.LONG != 0) || (y.LONG != 0) )
            push_LONG(s, a);
        else
            push_LONG(s, 0);
    } else
        push_LONG(s, 0);
}

/**
 * @brief Coloca o menor de 2 valores no topo da stack
 *
 * Inicializada com o token "e<"
 */
void emenor(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);

    if (has_type(x, LONG) && has_type(y, LONG)){
        if (y.LONG < x.LONG)
            push_LONG(s, y.LONG);
        else
            push_LONG(s, x.LONG);

    } else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        if (y.DOUBLE < x.LONG)
            push_DOUBLE(s, y.DOUBLE);
        else
            push_LONG(s, x.LONG);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (y.DOUBLE < x.DOUBLE)
            push_DOUBLE(s, y.DOUBLE);
        else
            push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        if (y.LONG < x.DOUBLE)
            push_LONG(s, y.LONG);
        else
            push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (y.CHAR < x.CHAR)
            push_CHAR(s, y.CHAR);
        else
            push_CHAR(s, x.CHAR);
    
    } else if (has_type(x, CHAR) && has_type(y, STRING)){
        if ((char)(strlen(y.STRING)) < x.CHAR )
            push_STRING(s, y.STRING);
        else 
            push_CHAR(s, x.CHAR);
          
    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strlen(y.STRING) < strlen(x.STRING)) 
            push_STRING(s, y.STRING);
        else
            push_STRING(s , x.STRING);

    } else if (has_type(x, STRING) && has_type(y, CHAR)){
        if ( (y.CHAR) < (char)(strlen(x.STRING)) )
            push_CHAR(s, y.CHAR);
        else
            push_STRING(s, x.STRING);

    }
}
/**
 * @brief Coloca o maior de 2 valores no topo da stack
 *
 * Inicializada com o token "e>"
 */
void emaior(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);

    if (has_type(x, LONG) && has_type(y, LONG)){
        if (y.LONG > x.LONG)
            push_LONG(s, y.LONG);
        else
            push_LONG(s, x.LONG);

    } else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        if (y.DOUBLE > x.LONG)
            push_DOUBLE(s, y.DOUBLE);
        else
            push_LONG(s, x.LONG);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (y.DOUBLE > x.DOUBLE)
            push_DOUBLE(s, y.DOUBLE);
        else
            push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        if (y.LONG > x.DOUBLE)
            push_LONG(s, y.LONG);
        else
            push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (y.CHAR > x.CHAR)
            push_CHAR(s, y.CHAR);
        else
            push_CHAR(s, x.CHAR);
    
    } else if (has_type(x, CHAR) && has_type(y, STRING)){
        if ((char)(strlen(y.STRING)) > x.CHAR )
            push_STRING(s, y.STRING);
        else 
            push_CHAR(s, x.CHAR);
          
    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strlen(y.STRING) > strlen(x.STRING)) 
            push_STRING(s, y.STRING);
        else
            push_STRING(s , x.STRING);

    } else if (has_type(x, STRING) && has_type(y, CHAR)){
        if ( (y.CHAR) > (char)(strlen(x.STRING)) )
            push_CHAR(s, y.CHAR);
        else
            push_STRING(s, x.STRING);

    }
}
