#include <stdio.h>
int n,front=0,rear=-1,queue[20];
void enqueue_front()
{
	if(front==0)
		printf("CANNOT ADD ELEMENT TO FRONT END\n");
	else
	{
		front--;
		printf("Enter the item to ENQUEUE: ");
        int item;
        scanf("%d",&item);
        queue[front]=item;
	}
}
void enqueue_rear()
{
	if(rear==n-1)
		printf("CANNOT ADD ELEMENT TO REAR END\n");
	else
	{
		rear++;
        printf("Enter the item to ENQUEUE: ");
        int item;
        scanf("%d",&item);
        queue[rear]=item;
	}
}
void dequeue_front()
{
	if((front==0)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("DEQUEUED ITEM: %d\n",queue[front]);
        front++;
        if(front>rear)
        {
            front=0;
            rear=-1;
        }
    }
}
void dequeue_rear()
{
	if((front==0)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("DEQUEUED ITEM: %d\n",queue[rear]);
        rear--;
        if(front>rear)
        {
            front=0;
            rear=-1;
        }
    }
}
void display()
{
    int i;
    if((front==0)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
        printf("\n");
    }
}
int main()
{
    int c;
    printf("Enter the size of the QUEUE\n");
    scanf("%d",&n);
    printf("DOUBLE ENDED QUEUE OPERATIONS\n");
    do
    {
        printf("0. EXIT\n1. ENQUEUE - FRONT\n2. ENQUEUE - REAR\n3. DEQUEUE - FRONT\n4. DEQUEUE - REAR\n5. DISPLAY\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                printf("Exiting from DOUBLE ENDED QUEUE...\n");
                break;
            case 1:
                enqueue_front();
                break;
            case 2:
                enqueue_rear();
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(c!=0);
}
