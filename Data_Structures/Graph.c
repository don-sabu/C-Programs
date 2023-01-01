#include<stdio.h>
int top=-1,front=0,rear=-1,stack[10],queue[10];
void enqueue(int item)
{
    queue[++rear]=item;
}
int dequeue()
{
    return queue[front++];
}
void bfs(int n,int e[][n],int s)
{
    int status[n];
    for(int i=0;i<n;i++)
        status[i]=1;
    enqueue(s);
    status[s]=2;
    while(rear>=front)
    {
        s=dequeue();
        status[s]=3;
        printf("%d",s+1);
        for(int i=0;i<n;i++)
            if(e[s][i]==1&&status[i]==1)
            {
                enqueue(i);
                status[i]=2;
            }
        if(rear>=front)
            printf(" --> ");
    }
    printf("\n");
}
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
void dfs(int n,int e[][n],int s)
{
    int status[n];
    for(int i=0;i<n;i++)
        status[i]=1;
    push(s);
    status[s]=2;
    while(top!=-1)
    {
        s=pop();
        status[s]=2;
        printf("%d",s+1);
        for(int i=0;i<n;i++)
            if(e[s][i]==1&&status[i]==1)
            {
                push(i);
                status[i]=2;
            }
        if(top!=-1)
            printf(" --> ");
    }
}
int main()
{
    int n,s;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int edge[n][n];
    printf("Enter 1 if there exists an edge. Otherwise 0\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            printf("%d --> %d: ",i+1,j+1);
            scanf("%d",&edge[i][j]);
        }
    printf("Vertices:");
    for(int i=0;i<n;i++)
        printf("  %d",i+1);
    printf("\n-----Adjacency Matrix-----\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf(" %d",edge[i][j]);
        printf("\n");
    }
    printf("Enter the source: ");
    scanf("%d",&s);
    bfs(n,edge,s-1);
    dfs(n,edge,s-1);
}
