#include<stdio.h>
int main()
{
	int n,i,ns,f,c=1;
	printf("Enter the size of the array\n");c++;
	scanf("%d",&n);c++;
	int ar[n];c++;
	printf("Enter %d elements\n",n);c++;
	c++;for(i=0;i<n;i++,c++)
	{
		scanf("%d",&ar[i]);c++;
	}	
	printf("Enter the element be searched in the array\n");c++;
	scanf("%d",&ns);c++;
	printf("The elements in the array are:\n");c++;
	c++;for(i=0;i<n;i++,c++)
	{
		printf("%d\t",ar[i]);c++;
	}
	c++;for(i=0;i<n;i++,c++)
	{
		c++;if(ar[i]==ns)
		{
			f=1;c++;
			c++;break;
		}
	}
	if(f==1)
	{c++;
		printf("\nThe element is found in position: %d\n",(i+1));c++;
	}
	else
	{c++;
		printf("\nThe element is not found\n");c++;
	}
	
	
	printf("Size complexity: %d bytes\n",((4+n)*4));
	printf("Time complexity - Frequency Count: %d\n",c);
} 
