#include<stdio.h>
struct sparse
{
	int row,column,value;
};
void sparse_matrix(struct sparse sm[],int ro,int co,int ar[][co])
{
	int i,j,k=0;
	for(i=0;i<ro;i++)
		for(j=0;j<co;j++)
			if(ar[i][j]!=0)
			{
				sm[k].row=i;
				sm[k].column=j;
				sm[k].value=ar[i][j];
				k++;
			}
}
int main()
{
	int i,j,r,c,n=0;
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of column: ");
	scanf("%d",&c);
	int a[r][c];
	printf("Enter the elements in the matrix\n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
				n++;
		
		}
    printf("The Matrix is:\n");
    for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d  ",a[i][j]);
        printf("\n");
    }
	struct sparse s[n];
	sparse_matrix(s,r,c,a);
	printf("SPARSE MATRIX REPRESENTATION\n");
	printf("Row(%d)  Column(%d)  value(%d)\n",r,c,n);
	for(i=0;i<n;i++)
		printf("  %d        %d         %d\n",s[i].row,s[i].column,s[i].value);

}
