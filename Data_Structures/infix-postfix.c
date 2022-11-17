#include<stdio.h>
int stop=0,ptop=-1;
char stack[50],Q[50],postfix[50];
char c,ch,chr;
void spush(char ch)
{
    stop++;
    stack[stop]=ch;
}
void ppush(char ch)
{
        ptop++;
        postfix[ptop]=ch;
}
char pop()
{
    ch=stack[stop];
    stop--;
    return(ch);
}
int priority(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else
        return 3;
}
void display()
{
    printf("%s\n",postfix);
}
int main()
{
    int i=0;
    printf("Enter an infix expression with closing bracket\n");
    scanf("%s",Q);
    stack[stop]='(';
    while(stop!=-1)
    {
        c=Q[i];
        i++;
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
            ppush(c);
        else if(c=='(')
            spush(c);
        else if(c==')')
        {
            while(stack[stop]!='(')
            {
                chr=pop();
                ppush(chr);
            }
            stop--;
        }
        else
        {
            do
            {   
                chr=pop();
                if(chr=='(')
                {
                    spush(chr);
                    break;
                }
                else if(priority(c)>priority(chr))
                {
                    spush(chr);
                    break;
                }
                else if(priority(c)<priority(chr))
                    ppush(chr);
                else
                    ppush(chr);
            }while(chr!='(');
            spush
        (c);
        }
    }
    display();
}
