#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int len=0;
struct node
{
    int data;
    struct node *link;
}*head=NULL,*temp,*temp1,*temp2;
bool isvalid(int n)
{
    if(n>0&&n<=len+1)
        return true;
    else
    {
        printf("Invalid Position\n");
        return false;
    }
}
struct node* create()
{
    return (struct node*)malloc(sizeof(struct node));
}
struct node* traverse(int n)
{
    int i;
    temp=head;
    for(i=0;i<n-1;i++)
        temp=temp->link;
    return temp;
}
void append(int pos)
{
    if(isvalid(pos))
    {
        int d;
        printf("Enter the data: ");
        scanf("%d",&d);
        temp1=traverse(pos);
        if(temp1==NULL)
        {
            head=temp1=create();
            temp1->link=NULL;
        }
        else
        {
            temp2=temp1->link;
            temp1->link=create();
            temp1->link->link=temp2;
        }
        len++;
    }
}
void delete(int pos)
{
    if(isvalid(pos+2))
    {
        temp1=traverse(pos);
        temp2=temp1->link->link;
        free(temp1->link);
        temp1->link=temp2;
        printf("Node %d removed\n",pos);
        len--;
    }
}
void display()
{
    if(len<=0)
        printf("No elements present in the list\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
}
int main()
{
    int n,i,c,pos;
    printf("Enter the number of nodes to create: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        append(i);
    do
    {
        printf("LINKED LIST OPETARIONS\n");
        printf("0. EXIT\n");
        printf("INSERTION\n");
        printf("  1. Front\n  2. Rear\n  3. Any position\n");
        printf("DELETION\n");
        printf("  4. Front\n  5. Rear\n  6. Any position\n");
        printf("7. DISPLAY\n");
        printf("Enter your choice: \n");
        scanf("%d",&c);
        switch (c)
        {
        case 0:
            printf("Exiting from the program...\n");
            break;
        case 1:
            append(1);
            break;
        case 2:
            append(len+1);
            break;
        case 3:
            printf("Enter the position to insert: ");
            scanf("%d",&pos);
            append(pos);
            break;
        case 4:
         delete(1);
            break;
        case 5:
         delete(len);
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d",&pos);
         delete(pos);
            break;
        case 7:
            display();
            break;
        default:
            printf("Invalid Choice :(\n");
            break;
        }
    }while(c!=0);
}
