#include<stdio.h>
int main()
{
    int m,p,i,j;
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
    printf("                            Worst Fit                             \n");
    printf("------------------------------------------------------------------\n");
    printf(" Process no    Process Size    Block no    Block Size    Fragment\n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < p; i++)
    {
        int w= -1;
        for (j = 0; j < m; j++)
        {
            if (mb[j] >= process[i])
            {
                if (w == -1)
                    w = j;
                else if (mb[w] < mb[j])
                    w = j;
            }
        }

        if (w != -1)
        {
            printf("    %d               %d            %d           %d           %d\n",(i+1),process[i],(w+1),mb[w],(mb[w]-process[i]));
            mb[w]=mb[w]-process[i];
        }
        else
            printf("    %d             %d           unallocated\n",(i+1),process[i]);
    }
    printf("==================================================================\n");
}
