#include<stdio.h>
int main()
{
	int n,i,j,t,k,c=1;
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
	c++;for(i=1;i<n;i++,c++)
	{
		j=i-1;c++;
		k=a[i];c++;
		c++;while((j>=0)&&(a[j]>k))
		{c++;
			a[j+1]=a[j];c++;
			j--;c++;
		}
		a[j+1]=k;c++;
	}
	
	printf("\nThe sorted array is:\n");c++;
	c++;for(i=0;i<n;i++,c++)
	{
		printf("%d\t",a[i]);c++;
	}
	printf("\nSpace Complexity: %d bytes",((5+n)*4));
	printf("\nTime Complexity in frequency count: %d\n",c);
}
