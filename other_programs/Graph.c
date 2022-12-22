#include<stdio.h>
int top=-1,front=-1,rear=-1,a[20][20],ar[20],S[20],Q[20];
void enqueue(int item)
{
	if(rear==19)
		printf("Queue Full");
	else
	{
		if(rear==-1)
		{
			Q[++rear]=item;
			front++;
		}
		else
			Q[++rear]=item;
	}
}
int dequeue()
{
	int k;
	if((front>rear)||(front==-1))
		return 0;
	else
	{
		k=Q[front++];
		return k;
	}
}
void push(int item)
{
	if(top==19)
		printf("Stack overflow\n");
	else
		S[++top]=item;
}
int pop()
{
	if(top==-1)
		return 0;
	else
		return(S[top--]);
}
void bfs(int s,int n)
{
	int p,i;
	enqueue(s);
	ar[s]=1;
	p=dequeue();
	if(p!=0)
		printf("%d\t",p);
	while(p!=0)
	{
		for(i=1;i<=n;i++)
			if((a[p][i]!=0)&&(ar[i]==0))
			{
				enqueue(i);
				ar[i]=1;
			}
		p=dequeue();
		if(p!=0)
			printf("%d\t",p);
	}
	for(i=1;i<=n;i++)
		if(ar[i]==0)
			bfs(i,n);
	printf("\n");
}
void dfs(int s,int n)
{
    int i,k;
    push(s);
    ar[s]=1;
    k=pop();
    if(k!=0)
        printf("%d\t",k);
    while(k!=0)
    {
        for(i=1;i<=n;i++)
            if((a[k][i]!=0)&&(ar[i]==0))
            {
                push(i);
                ar[i]=1;
            }
        k=pop();
        if(k!=0)
            printf("%d\t",k);
    }
    for(i=1;i<=n;i++)
        if(ar[i]==0)
            dfs(i,n);
    printf("\n");
}
int main()
{
	int n,i,s,c,j;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			printf("Enter 1 if %d has a node with %d else 0: ",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("-----Adjacency Matrix-----\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	do
	{
		for(i=1;i<=n;i++)
			ar[i]=0;
		printf("Options\n1.Breadth First Search\t2.Depth First Search\t3.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the source vertex: ");
					scanf("%d",&s);
					bfs(s,n);
					break;
			case 2: printf("Enter the source vertex: ");
					scanf("%d",&s);
					dfs(s,n);
					break;
			case 3: printf("Terminated...\n");
					break;
			default:printf("invalid choice\n");
					break;
		}
	}while(c!=3);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
