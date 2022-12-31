#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
    int len=ub-lb+1;
    int b[len];
    int i=lb,j=mid+1,k=0;
    while(k<len)
    {
        if((i<=mid)&&((j>ub)||(a[i]<=a[j])))
        {
            b[k]=a[i];
            i++;k++;
        }
        if((j<=ub)&&((i>mid)||(a[j]<a[i])))
        {
            b[k]=a[j];
            j++;k++;
        }
    }
    for(i=lb;i<=ub;i++)
        a[i]=b[i-lb];
}
void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        mergesort(a,lb,(lb+ub)/2);
        mergesort(a,(lb+ub)/2+1,ub);
        merge(a,lb,(lb+ub)/2,ub);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\n");
}
