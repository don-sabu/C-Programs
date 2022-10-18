#include <stdio.h>
int n,top=-1,stack[20];
void push()
{
    if(top==n-1)
        printf("STACK IS FULL\n");
    else
    {
        int item;
        printf("Enter the item to push: ");
        scanf("%d",&item);
        stack[++top]=item;
    }
}
void pop()
{
    if(top==-1)
        printf("STACK IS EMPTY\n");
    else
    {
        printf("ITEM POPED: %d\n",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("STACK IS EMPTY\n");
    else
    {
        printf("The elements in STACK:\n");
        for(i=top;i>=0;i--)
            printf("%d\t",stack[i]);
        printf("\n");
    }
}
int main()
{
    int c=1;
    printf("Enter the size of the stack\n");
    scanf("%d",&n);
    printf("STACK OPERATIONS\n");
    while(c!=0)
    {
        printf("0. EXIT\n1. PUSH\n2. POP\n3. DISPLAY\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                printf("Exiting from STACK...\n");
                break;
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}
