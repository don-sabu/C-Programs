#include<stdio.h>
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int i,j,n,ttat=0,twt=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int p[n],bt[n],tat[n],wt[n];
    printf("Enter the burst time for each process\n");
    for(i=0;i<n;i++)
    {
        printf("Burst Time for p%d: ",i);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(bt[i]>bt[j])
            {
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
    wt[0]=0;
    for(i=0;i<n;i++)
    {
        if(i==0)
            tat[i]=bt[i];
        else
        {
            tat[i]=tat[i-1]+bt[i];
            wt[i]=wt[i-1]+bt[i-1];
        }
        ttat=ttat+tat[i];
        twt=twt+wt[i];
    }
    printf("Process\t\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for(i=0;i<n;i++)
        printf("  P%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[i],tat[i],wt[i]);
    printf("Total Turn Around Time : %d\n",ttat);
    printf("Average Turn Around Time : %f\n",(float)ttat/n);
    printf("Total Waiting Time : %d\n",twt);
    printf("Average Waiting Time : %f\n",(float) twt/n);
}
