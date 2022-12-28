#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int u)
{
    int s=l,e=l+1,p=l;
    while(e<=u)
    {
        if(a[e]<a[p])
        {
            s++;
            swap(&a[s],&a[e]);
        }
        e++;
    }
    swap(&a[p],&a[s]);
    return s;
}
void quicksort(int a[],int l,int u)
{
    if(l<u)
    {
        int mid=partition(a,l,u);
        quicksort(a,l,mid-1);
        quicksort(a,mid+1,u); 
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
    quicksort(a,0,n-1);
    printf("The sorted elements are: ");
    for(int i=0;i<n;i++)
        printf("  %d",a[i]);
    printf("\n");
}
