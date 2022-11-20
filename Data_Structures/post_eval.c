#include<stdio.h>
int stack[50],top=-1;
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
int power(int x, int y)
{
    int e,i;
    for(i=0,e=1;i<y;i++,e*=x);
    return e;
}
int main()
{
    int i=0,a,b;
    char exp[50],c;
    printf("Enter the postfix expression\n");
    gets(exp);
    while((c=exp[i])!='\0')
    {
        if(c>='0'&&c<='9')
            push(c-'0');
        else
        {
            a=pop();
            b=pop();
            switch(c)
            {
                case '+':
                        push(b+a);
                        break;
                case '-':
                        push(b-a);
                        break;
                case '*':
                        push(b*a);
                        break;
                case '/':
                        push(b/a);
                        break;
                case '^':
                        push(power(a,b));
                        break;
              }
        }
        i++;
    }
    printf("Result of the expression: %d",stack[0]);
}