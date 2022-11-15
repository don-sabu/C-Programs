#include <stdio.h>
char stack[20],postexp[20];
int stop=-1,ptop=-1;
void ppush(char item)
{
	ptop++;
	postexp[ptop]=item;
}
void spush(char item)
{
	stop++;
	stack[stop]=item;
}
char pop()
{
	return stack[stop--];
}
int priority(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/'||c=='%')
		return 2;
	else
		return 1;
}
void display()
{
	while(ptop>=0)
		printf("%c",postexp[ptop--]);
	printf("\n");
}
int main()
{
	char exp[20],c,ch,chr;
	int i=0;
	printf("Enter the infix expression\n");
	scanf("%s",exp);
	spush('(');
	do
	{
		ch=exp[i];
		if(((ch>='A')&&(ch<='Z'))||((ch>='a')&&(ch<='z')))
			ppush(ch);
		else if(ch=='(')
			spush(ch);
		else if(ch==')')
		{
			c=pop();
			while(c!='(')
			{
				ppush(c);
				c=pop();
			}
		}
		else
		{
			chr=pop();
			while(chr!='(')
			{
				if(priority(c)>priority(chr))
				{
					spush(chr);
					break;
				}
				else
					ppush(chr);
				chr=pop();
			}
			spush(c);
		}
		i++;
	}while(stop!=-1);
	display();
}
