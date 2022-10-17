#include<stdio.h>
int main()
{
	int n,i,j,t,c=1;
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
		c++;for(j=0;j<n-i-1;j++,c++)
		{
			c++;if(a[j]>a[j+1])
			{
				t=a[j];c++;
				a[j]=a[j+1];c++;
				a[j+1]=t;c++;
			}
		}
	}
	printf("\nThe sorted array is:\n");c++;
	c++;for(i=0;i<n;i++,c++)
	{
		printf("%d\t",a[i]);c++;
	}
	printf("\nSpace Complexity: %dbytes",((4+n)*4));
	printf("\nTime Complexity in frequency count: %d\n",c);
}
