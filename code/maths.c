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
    else if(has_type(x, CHAR)){
        push_CHAR(s, x.CHAR + 1);
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
    else if(has_type(x, CHAR)){
        push_CHAR(s, x.CHAR - 1);
    }
}


void modulo(STACK *s){ //  MÓDULO "%"
      
    DATA x = pop(s);
    DATA y = pop(s);
    
    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, y.LONG % x.LONG);
    }
    else if(has_type(x, LONG) && has_type(y, DOUBLE)){
        push_DOUBLE(s, fmod(y.DOUBLE ,x.LONG));
    }
    else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        push_DOUBLE(s, fmod(y.DOUBLE ,x.DOUBLE));
    }
    else if(has_type(x, DOUBLE) && has_type(y, LONG)){
        push_DOUBLE(s, fmod(y.LONG ,x.DOUBLE));
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
