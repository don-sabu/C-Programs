#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
}*chain;
void insert(struct node *head[],int n,int key)
{
    int hash = key%n;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value=key;
    newnode->next=NULL;
    if(head[hash]==NULL)
        head[hash]=newnode;
    else
    {
        chain=head[hash];
        while(chain->next!=NULL)
            chain=chain->next;
        chain->next=newnode;
    }
}
void display(struct node *head[],int n)
{
    printf("==========================\n");
    printf("--------Hash Table--------\n");
    printf("--------------------------\n");
    printf(" Index     Key\n");
    printf("--------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("   %d",i);
        printf("       ");
        chain=head[i];
        if(chain==NULL)
            printf("null");
        else
            while(chain!=NULL)
            {
                printf("%d",chain->value);
                chain=chain->next;
                if(chain!=NULL)
                    printf("-->");
            }
        printf("\n");
    }
    printf("==========================\n");
}
int main()
{
    int n,c,k,i;
    printf("Enter the size of hash table: ");
    scanf("%d",&n);
    struct node *head[n];
    for(i=0;i<n;i++)
        head[i]=NULL;
    printf("Enter number of keys: ");
    scanf("%d",&k);
    int key[k];
    printf("Enter %d key values\n",k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&key[i]);
        insert(head,n,key[i]);
    }
    display(head,n);
}
