#include<stdio.h>
int main()
{
	int n,i,ns,f,c=1;
	printf("Enter the size of the array\n");c++;
	scanf("%d",&n);c++;
	int ar[n], fpos=0, lpos=n-1, mid;c++;
	printf("Enter %d elements\n",n);c++;
	c++;for(i=0;i<n;i++,c++)
	{
		scanf("%d",&ar[i]);c++;
	}
	printf("Enter the element to be searched in the array\n");c++;
	scanf("%d",&ns);c++;
	c++;while(fpos<=lpos)
	{c++;
		mid=(fpos+lpos)/2;c++;
		c++;if(ar[mid]<ns)
		{
			fpos=mid+1;c++;
		}
		else if(ar[mid]>ns)
		{c++;
			lpos=mid-1;c++;
		}
		else
		{c++;
			f=1;c++;
			c++;break;
		}
	}
	if(f==1)
	{c++;
		printf("The element is found in position: %d\n",(mid+1));c++;
	}
	else	
	{c++;
		printf("The element is not found\n");c++;
	}
	
	printf("Size complexity: %d bytes\n",((7+n)*4));
	printf("Time complexity - Frequency Count: %d\n",c);
}
