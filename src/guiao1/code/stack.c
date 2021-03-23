#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int PUSH(int n)
{

		if(top == 100-1)
		{
			printf("Error");
		}
		else
		{
    		stack[top]=n;
    		top++;	
		}
    return 0;
}


int POP()
{

    if(top <= 0)
    {
        printf("Error");
    }
    else
    {
        stack[top] == NULL;
        top--;
    }
    return 0;
}

void PRINT_STACK() { // testando
    int i;
    int a = strlen(stack);
    for(i=0; i<a; i++) printf("%d", stack[i]);
}

int STACK_SIZE() {  // testando

    int a = strlen(stack);
    return a;
}