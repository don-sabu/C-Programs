#include<stdio.h>
#include<stdlib.h>
int tb,n,table[10];
struct node
{
	int data;
	struct node* link;
}*head[10]={0},*temp,*newnode;
void insert(int key)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->link=0;
	n=key%tb;
	if(head[n]==0)
		head[n]=newnode;
	else
	{
		temp=head[n];
		while(temp->link!=0)
			temp=temp->link;
		temp->link=newnode;
	}
}
void search()
{
	int key;
	printf("Enter the key to be searched: ");
	scanf("%d",&key);
	n=key%tb;
	if(head[n]==0)
		printf("Element not found\n");
	else
	{
		temp=head[n];
		int i=1;
		while(temp!=0)
		{
			if(temp->data==key)
			{
				printf("Element found at index %d in column %d\n",n,i);
				break;
			}
			temp=temp->link;
			i++;
		}
		if(temp==0)
			printf("Element not found\n");
	}
}
void display()
{	
	printf("------The Hashed Table------\n");
	for(int i=0;i<tb;i++)
	{
		printf("\t%d-->",i);
		temp=head[i];
		while(temp!=0)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int main()
{	
	int choice;
	printf("Enter table size: ");
	scanf("%d",&tb);
	printf("Enter key values:\n");
	for(int i=0;i<tb;i++)
		scanf("%d",&table[i]);
	for(int i=0;i<tb;i++)
		insert(table[i]);
	do
	{
		printf("Options\n1.Search\t2.Display\t3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: search();
					break;
			case 2: display();
					break;
			case 3: printf("Terminated....\n");
					break;
			default:printf("Invalid choice\n");
					break;
		}
	}while(choice!=3);
}
