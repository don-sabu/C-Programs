#include<stdio.h>
void maxheapify(int a[],int n,int i)
{
    int l=2*i+1,r=2*i+2,large=i,tmp;
    if((l<n)&&(a[l]>a[large]))
        large=l;
    if((r<n)&&a[r]>a[large])
        large=r;
    if(large!=i)
    {
        tmp=a[large];
        a[large]=a[i];
        a[i]=tmp;
        maxheapify(a,n,large);
    }
}
void heapsort(int a[],int n)
{
    int i,j,tmp;
    for(i=n/2-1;i>=0;i--)
        maxheapify(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        tmp=a[i];
        a[i]=a[0];
        a[0]=tmp;
        maxheapify(a,i,0);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted array:");
	for(i=0;i<n;i++)
		printf("  %d",a[i]);
	printf("\n");
}
