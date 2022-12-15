#include<stdio.h>
int main()
{
    int m,p,i,j,f=0;
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
    printf("                            First Fit                             \n");
    printf("------------------------------------------------------------------\n");
    printf(" Process no    Process Size    Block no    Block Size    Fragment\n");
    printf("------------------------------------------------------------------\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<m;j++)
            if(process[i]<=mb[j])
            {
                printf("    %d               %d            %d           %d           %d\n",(i+1),process[i],(j+1),mb[j],(mb[j]-process[i]));
                mb[j]=mb[j]-process[i];
                f=1;
                break;
            }
        if(f==0)
        {
            printf("    %d             %d           unallocated\n",(i+1),process[i]);
        }
        f=0;
    }
    printf("==================================================================\n");
}
