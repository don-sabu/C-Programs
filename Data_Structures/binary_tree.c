#include<stdio.h>
#include<stdlib.h>
int count=1;
struct node
{
	int data;
	struct node *leftchild,*rightchild;
}*root=NULL,*newnode;
struct node* insert(struct node *root, int value)
{
	if(root==NULL)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=value;
		newnode->leftchild=newnode->rightchild=NULL;
		root=newnode;
		count++;
	}
	else
	{
		if(count%2==0)
			root->leftchild=insert(root->leftchild,value);
		else
			root->rightchild=insert(root->rightchild,value);
	}
	return root;
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("  %d",root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->leftchild);
		printf("  %d",root->data);
		inorder(root->rightchild);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("  %d",root->data);
	}
}
int main()
{
	int c,value;
	printf("***************BINARY TREE***************\n");
	do
	{
		printf("          Binary Tree Operations\n");
		printf("         0. Exit    1.Insert\n");
		printf("Display: 2.Preorder 3.Inorder 4.Postorder\n");
		printf("Enter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				printf("Exiting from binary tree...\n");
				break;
			case 1:
				printf("Enter the value to insert: ");
				scanf("%d",&value);
				root=insert(root,value);
				break;
			case 2:
				printf("Preorder: ");
				preorder(root);
				printf("\n");
				break;
			case 3:
				printf("Inorder: ");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder: ");
				postorder(root);
				printf("\n");
				break;
			default:
				printf("Invalid Choice\n");
		}
	}while(c!=0);
}
