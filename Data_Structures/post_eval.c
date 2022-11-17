#include<stdio.h>
#include<ctype.h>
int top=-1;
char st[50],P[50];
char chr,ch;
void push(char ch)
{
    top++;
    st[top]=ch;
}
char pop()
{
    ch=st[top];
    top--;
    return(ch);
}
int main()
{
    int i,val=0,a,b;
    printf("Enter a postfix expression with closing bracket\n");
    for(i=0;P[i-1]!=')';i++)
    {
        scanf("%c",&P[i]);
    }
    i=0;
    do
    {
        chr=P[i];
        i++;
        if(isdigit(chr))
            push(chr- '0');
        else if(chr=='+'||chr=='-'||chr=='/'||chr=='*'||chr=='^')
        {
           a=pop();
           b=pop();
           printf("%d  %d\n",a,b);
           switch(chr)
           {
                case '+':
                        val=b+a;
                        break;
                case '-':
                        val=b-a;
                        break;
                case '*':
                        val=b*a;
                        break;
                case '/':
                        val=b/a;
                        break;
                case '^':
                        val=b^a;
                        break;
           }
           push(val);
        }
    }while(chr!=')');
    printf("Evaluated value: %d",st[top]);
}
