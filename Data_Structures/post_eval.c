#include<stdio.h>
#include<ctype.h>
int top=-1,stack[20];
void push(char c)
{
	top++;
	stack[top]=(int)c;
}
int pop()
{
	return stack[top--];
}
int power(int x,int y)
{
	int res=1,i;
	for(i=0;i<y;i++)
		res*=x;
	return res;
}
int main()
{
	char exp[20],c;
	int i=0,a,b;
	printf("Enter the postfix expression: ");
	scanf("%s",exp);
	while(exp[i]!='\0')
	{
		c=exp[i];
		if(isdigit(c))
			push(c-'0');
		else
		{
			a=pop();
			b=pop();
			switch(c)
			{
				case '+':
					push(a+b);
					break;
				case '-':
					push(a-b);
					break;
				case '*':
					push(a*b);
					break;
				case '/':
					push(a/b);
					break;
				case '^':
					int x = power(a,b);
					push(x);
					break;
			}
		}
		i++;
	}
	printf("The result is : %d\n",stack[0]);
}
