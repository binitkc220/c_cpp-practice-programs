#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of datas : ");
    scanf("%d",&n);
    float x[n],  y[n], sum=0, prod, xp;
    int i,j;
    printf("Enter the datas of x : \n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("Enter the datas of y : \n");
    for(i=0;i<n;i++)
        scanf("%f",&y[i]);
    printf("Enter the interpolating value : ");
    scanf("%f",&xp);
    for(i=0;i<n;i++)
    {
        prod = 1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
                prod = prod * (xp-x[j]) / (x[i]-x[j]);
        }
        sum = sum + y[i]*prod;
    }
    printf("\n\ty(x)=%.2f",sum);
    return 0;
}