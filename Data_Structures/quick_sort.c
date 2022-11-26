#include<stdio.h>
int a[10];
int partition(int ar[],int lb,int ub)
{
	int pivot=lb,start=lb,end=ub,temp;
	while(start<end)
	{
		while(ar[start]<=ar[pivot])
			start++;
		while(ar[end]>ar[pivot])
			end--;
		if(start<end)
		{
			temp=ar[start];
			ar[start]=ar[end];
			ar[end]=temp;
		}
	}
	temp=ar[pivot];
	ar[pivot]=ar[end];
	ar[end]=temp;
	return end;
}
void quicksort(int ar[],int lb, int ub)
{
	if(lb<ub)
	{
		int end = partition(ar,lb,ub);
		quicksort(ar,lb,end-1);
		quicksort(ar,end+1,ub);
	}
}
int main()
{
	int i,n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter %d numbers to the array\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("Sorted array:");
	for(i=0;i<n;i++)
		printf("  %d",a[i]);
	printf("\n");
}
