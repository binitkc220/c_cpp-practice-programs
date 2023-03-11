#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of datas : ");
    scanf("%d",&n);
    float x[n], sum=0,h;
    printf("Enter the datas of x : \n");
    for(int i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("Enter the step-size : ");
    scanf("%f",&h);
    sum = x[0] + x[n-1];
    for(int i=1;i<n-1;i++)
    {
        sum += 2*x[i];
    }
    sum *= h/2;
    printf("The sum by Trapezoidal Rule is %.3f",sum);
    return 0;
}