#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head,*temp,*prev,*newnode;
void read()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
}
void insert_front()
{
    temp=head;
    read();
    head=newnode;
    newnode->link=temp;
}
void insert_pos()
{
    int pos,i=0;
    printf("Enter the position to insert: ");
    scanf("%d",&pos);
    if(pos==0)
        insert_front();
    else
    {
    read();
    temp=head;
    while(i<pos)
    {
        prev=temp;
        temp=prev->link;
        i++;
    }
    prev->link=newnode;
    newnode->link=temp;
    }
}
void insert_end()
{
    read();
    temp=head;
    while(temp!=0)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=newnode;
    newnode->link=0;
}
void delete_front()
{
    if(head==0)
        printf("List Empty\n");
    else
    {
        temp=head;
        head=head->link;
        free(temp);
    }
}
void delete_pos()
{
    int pos,i=0;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    if(pos==0)
        delete_front();
    else
    {
        temp=head;
        while(i<pos)
        {
            prev=temp;
            temp=prev->link;
            i++;
        }
        prev->link=temp->link;
        free(temp);
    }
}
void delete_end()
{
    if(head==0)
        printf("List Empty\n");
    else
    {
        temp=head;
        while(temp->link!=0)
        {
            prev=temp;
            temp=temp->link;
        }
        free(temp);
        prev->link=0;
    }
}
void display()
{
    printf("--LIST DATA--\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main()
{
    int n,choice,i;
    head=0;
    printf("Enter the number of nodes to be created: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        read();
        newnode->link=0;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->link=newnode;
            temp=newnode;
        }
    }
    do
    {
        printf("----------LINKED LIST OPERATIONS----------\n");
		printf(" INSERTION- 1.Front 2.Rear 3.Any Position\n");
		printf("  DELETION- 4.Front 5.Rear 6.Any Position\n");
		printf("            7.Display      8.Exit\n");
		printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	insert_front();
            	break;
            case 2:
            	insert_end();
            	break;
            case 3:
            	insert_pos();
            	break;
            case 4:
            	delete_front();
            	break;
            case 5:
            	delete_end();
            	break;
            case 6:
            	delete_pos();
            	break;
            case 7:
            	display();
            	break;
            case 8:
            	printf("Exiting from the program...\n");
            	break;
            default:
            	printf("Invalid Choice\n");
            	break;
        }
    } while (choice!=8);
}
