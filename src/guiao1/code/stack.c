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
        stack[top] == NULL;
        top--;
    }
}




