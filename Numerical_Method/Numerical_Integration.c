#include<stdio.h>

float f(float x)
{
    return 1.0/(1+x*x);
}

int main()
{
    float x0,xn,h,trap_s=0,sim13_s=0,sim38_s=0;
    int n,i;
    printf("Enter the starting point : ");
    scanf("%f",&x0);
    printf("Enter the ending point : ");
    scanf("%f",&xn);
    printf("Enter the interval : ");
    scanf("%d",&n);
    h = (xn-x0)/n;
    
    trap_s = sim13_s = sim38_s = f(x0) + f(xn);

    //Trapezoidal
    for(i=1;i<n;i++)
        trap_s += 2*f(x0+i*h);
    trap_s *= h/2;
    
    //Simpsons 1/3
    for(i=1;i<n;i++)
    {
        if(i%2==0)
            sim13_s += 2*f(x0+i*h);
        else
            sim13_s += 4*f(x0+i*h);
    }
    sim13_s *= h/3;

    //Simpsons 3/8
    for(i=1;i<n;i++)
    {
        if(i%3==0)
            sim38_s += 2*f(x0+i*h);
        else
            sim38_s += 3*f(x0+i*h);
    }
    sim38_s *= 3*h/8;

    printf("The sum by Trapezoidal Rule is %.3f\n",trap_s);
    printf("The sum by Simpson's 1/3 Rule is %.3f\n",sim13_s);
    printf("The sum by Simpson's 3/8 Rule is %.3f\n",sim38_s);
    return 0;
}