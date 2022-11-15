#include <stdio.h>
int n,front=0,rear=-1,queue[20];
void display()
{
	if(rear==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		int i;
		printf("QUEUE: ");
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
		printf("\n");
	}
}
void enqueue()
{
	if(rear+1==n)
		printf("QUEUE IS FULL\n");
	else
	{
		int item,i;
		printf("Enter the element to enqueue: ");
		scanf("%d",&item);
		i=rear;
		rear++;
		while((i>=0)&&(queue[i]>item))
		{
			queue[i+1]=queue[i];
			i--;
		}
		queue[i+1]=item;
	}
	display();
}
void dequeue()
{
	if(rear==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		printf("Dequeued element: %d\n",queue[front]);
		front++;
		if(front>rear)
		{
			front=0;
			rear=-1;
		}
		display();
	}
}
int main()
{
	int c;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);
	do
	{
		printf("QUEUE OPERATIONS\n");
		printf("0. EXIT\n1. ENQUEUE\n2. DEQUEUE\n");
		printf("Enter your choice\n");
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
			default:
				printf("INVALID CHOICE\n");
		}
	}while(c!=0);
}
