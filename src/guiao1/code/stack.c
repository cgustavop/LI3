#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void push(int n)
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
}


void pop()
{

    if(top <= 0)
    {
        printf("Error");
    }
    else
    {
        stack[top] == NULL
        top--;
    }
}




