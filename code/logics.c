#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "logics.h"
#include "stack.h"

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

void igual(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);

    if(has_type(x, LONG) && has_type(y, LONG)){
        if (x.LONG == y.LONG)
            push_LONG(s, 1);

    } else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        if (x.DOUBLE == y.DOUBLE)
            push_LONG(s, 1);

    } else if (has_type(x, CHAR) && has_type(y, CHAR)){
        if (x.CHAR == y.CHAR)
            push_LONG(s, 1);

    } else if (has_type(x, STRING) && has_type(y, STRING)){
        if (strcmp(x.STRING,y.STRING) == 0)
            push_LONG(s, 1);
    } else
        push_LONG(s, 0);
}

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

void nono(STACK *s){ // !
    DATA x = pop(s);

    if (has_type(x, LONG)) {
        if (x.LONG == 0)
            push_LONG(s, x.LONG + 1);
        else if (x.LONG == 1)
            push_LONG(s, x.LONG - 1);

    } else if (has_type(x, DOUBLE)) {
        push_DOUBLE(s, x.DOUBLE);

    } else if (has_type(x, CHAR)) {
        push_DOUBLE(s, x.CHAR);

    } else if (has_type(x, STRING)){
        push_STRING(s, x.STRING);
    }
}


void eE(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    
    if (has_type(x, LONG) && has_type(y, LONG)){
        if ( (x.LONG != 0) && (y.LONG != 0) )
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    } else {
        push_LONG(s, 0);
    }
}

void eOU(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    
    if (has_type(x, LONG) && has_type(y, LONG)){
        if ( (x.LONG != 0) || (y.LONG != 0) )
            push_LONG(s, 1);
        else
            push_LONG(s, 0);
    } else
        push_LONG(s, 0);
}


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
