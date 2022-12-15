#include<stdio.h>
int main()
{
    int m,p,i,j,b=-1;
    printf("Enter the number of memory blocks: ");
    scanf("%d",&m);
    int mb[m];
    for(i=0;i<m;i++)
    {
        printf("Enter the size of block %d: ",(i+1));
        scanf("%d",&mb[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    int process[p];
    for(i=0;i<p;i++)
    {
        printf("Enter the size of process %d: ",(i+1));
        scanf("%d",&process[i]);
    }
    printf("==================================================================\n");
    printf("                             Best Fit                             \n");
    printf("------------------------------------------------------------------\n");
    printf(" Process no    Process Size    Block no    Block Size    Fragment\n");
    printf("------------------------------------------------------------------\n");
    for(i=0;i<p;i++)
    {
        b=-1;
        for (j = 0; j < m; j++)
        {
            if (mb[j] >= process[i])
            {
                if (b == -1)
                    b = j;
                else if (mb[b] > mb[j])
                    b = j;
            }
        }
        if(b!=-1)
        {
            printf("    %d               %d            %d           %d           %d\n",(i+1),process[i],(b+1),mb[b],(mb[b]-process[i]));
            mb[b]=mb[b]-process[i];
        }
        else
            printf("    %d             %d           unallocated\n",(i+1),process[i]);
    }
    printf("==================================================================\n");
}
