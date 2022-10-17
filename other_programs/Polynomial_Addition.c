#include<stdio.h>
struct poly
{
	int coef,exp;
};
void read(struct poly x[],int l)
{
    int i;
    printf("Enter %d terms in decreasing order of exponents\n",l);
    for(i=0;i<l;i++)
    {
        printf(" Coefficient: ");
        scanf("%d",&x[i].coef);
        printf("    Exponent: ");
        scanf("%d",&x[i].exp);
    }
}
int add(struct poly a[],struct poly b[],struct poly c[],int l1,int l2)
{
    int i=0,j=0,k=0;
    while((i<l1)||(j<l2))
    {
        if((i<l1)&&((j==l2)||(a[i].exp>b[j].exp)))
        {
            c[k].coef=a[i].coef;
            c[k].exp=a[i].exp;
            i++;k++;
        }
        if((j<l2)&&((i==l1)||(a[i].exp<b[j].exp)))
        {
            c[k].coef=b[j].coef;
            c[k].exp=b[j].exp;
            j++;k++;
        }
        if(a[i].exp==b[j].exp)
        {
            c[k].coef=a[i].coef+b[j].coef;
            c[k].exp=a[i].exp;
            i++;j++;k++;
        }
    }
    return k;
}
void display(struct poly x[],int l)
{
    int i;
    for(i=0;i<l;i++)
    {
        printf("%dX^%d",x[i].coef,x[i].exp);
        if(i<l-1)
            printf(" + ");
        else
            printf("\n");
    }
}
int main()
{
    int f,s,l;
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d",&f);
    struct poly x1[f];
    read(x1,f);
    printf("\nEnter the number of terms for the second polynomial: ");
    scanf("%d",&s);
    struct poly x2[s];
    read(x2,s);
    struct poly x3[f+s];
    l=add(x1,x2,x3,f,s);
    printf("\nPolynomial 1: ");
    display(x1,f);
    printf("Polynomial 2: ");
    display(x2,s);
    printf(" Sum of both: ");
    display(x3,l);
}
