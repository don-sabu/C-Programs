#include<stdio.h>
int main()
{
	int n,i,j,t,min,c=1;
	printf("Enter the number of elements\n");c++;
	scanf("%d",&n);c++;
	int a[n];c++;
	printf("Enter %d numbers\n",n);c++;
	c++;for(i=0;i<n;i++,c++)
	{
		scanf("%d",&a[i]);c++;
	}
	printf("The original array is:\n");c++;
	c++;for(i=0;i<n;i++,c++)
	{
		printf("%d\t",a[i]);c++;
	}
	c++;for(i=0;i<n-1;i++,c++)
	{
		min=i;c++;
		c++;for(j=i+1;j<n;j++,c++)
		{
			c++;if(a[min]>a[j])
			{
				min=j;c++;
			}
		}
		t=a[min];c++;
		a[min]=a[i];c++;
		a[i]=t;c++;
	}
	printf("\nThe sorted array is:\n");c++;
	c++;for(i=0;i<n;i++,c++)
	{
		printf("%d\t",a[i]);c++;
	}
	printf("\nSpace Complexity: %d bytes",((5+n)*4));
	printf("\nTime Complexity in frequency count: %d\n",c);
}
