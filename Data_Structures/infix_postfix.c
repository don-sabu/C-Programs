#include<stdio.h>
#include<string.h>
char post[50],stack[50];
int top=-1,ptop=-1;
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return stack[top--];
}
void postpush(char item)
{
    printf("%c",item);
    post[++ptop]=item;
}
int priority(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if (c=='*'||c=='/')
        return 2;
    else
        return 3;
}
int main()
{
    int i=0;
    char infix[50],c,ch,chr;
    printf("Enter the infix expression\n");
    gets(infix);
    infix[strlen(infix)]=')';
    infix[strlen(infix)+1]='\0';
    push('(');
    while (top!=-1)
    {
        c=infix[i];
        if(c=='(')
            push(c);
        else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
            postpush(c);
        else if(c==')')
            while ((ch=pop())!='(')
                postpush(ch);
        else
        {
            chr=pop();
            if(priority(c)<=priority(chr))
                while((chr!='(')&&(priority(c)<=priority(chr)))
                {
                    postpush(chr);
                    chr=pop();
                }
            push(chr);
            push(c);
        }
        i++;
    }
}