#include <stdio.h>
int n,front=-1,rear=-1,queue[20];
void enqueue()
{
    if((rear+1)%n==front)
        printf("QUEUE IS FULL\n");
    else
    {
        if((front==-1)&&(rear==-1))
            front=rear=0;
        else
            rear=(rear+1)%n;
        printf("Enter the item to ENQUEUE: ");
        int item;
        scanf("%d",&item);
        queue[rear]=item;
    }
}
void dequeue()
{
    if((front==-1)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("DEQUEUED ITEM: %d\n",queue[front]);
        if(front==rear)
            rear=front=-1;
        else
            front=(front+1)%n;
    }
}
void display()
{
    int i;
    if((front==-1)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else
    {
    	if(front<rear)
		    for(i=front;i<=rear;i++)
		        printf("%d\t",queue[i]);
		else
		    for(i=front;i<=(rear+n);i++)
		        printf("%d\t",queue[i%n]);
        printf("\n");
    }
}
int main()
{
    int c;
    printf("Enter the size of the QUEUE\n");
    scanf("%d",&n);
    printf("CIRCULAR QUEUE OPERATIONS\n");
    do
    {
        printf("0. EXIT\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                printf("Exiting from QUEUE...\n");
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(c!=0);
}
