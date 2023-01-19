#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float *x, *y, a, b, SUMx = 0, SUMy = 0, SUMxy = 0, SUMx2 = 0;
    int n, i;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    x = (float *)malloc(n*sizeof(float));
    y = (float *)malloc(n*sizeof(float));
    printf("Enter the data of x\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the data of y\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    for(i = 0; i < n; i++)
    {
        SUMx = x[i] + SUMx;
        SUMy = log(y[i]) + SUMy;
        SUMxy += x[i] * log(y[i]);
        SUMx2 += x[i] * x[i];
    }
    if ((n * SUMx2 - SUMx * SUMx) != 0)
    {
        a = (SUMy * SUMx2 - SUMx * SUMxy) / (n * SUMx2 - SUMx * SUMx);
        b = (n * SUMxy - SUMx * SUMy) / (n * SUMx2 - SUMx * SUMx);
        a = exp(a);
    }
    else
    {
        printf("Determinant cannot be zero\n");
        exit(0);
    }
    printf("The best fit equation is y=%.2fe^(%.2fx)", a, b);
}