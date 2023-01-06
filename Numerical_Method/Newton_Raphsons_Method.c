//Newton Raphsons Method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
    return (x*sin(x)+cos(x));
}
float df(float x)
{
    return (x*cos(x));
}

int main()
{
    float x0,x1,abs_error,count=0;
    printf("Enter the initial x0 : ");
    scanf("%f",&x0);
    printf("i\tx(i)\tx(i+1)\tAbsolute Error\n");
    do
    {
        if(fabs(df(x0))<=0.00005)
        {
            printf("Error in finding root !");
            exit(0);
        }
        x1 = x0-(f(x0)/df(x0));
        abs_error = fabs(x1-x0);
        printf("%d\t%.5f\t%.5f\t%.5f\n",count,x0,x1,abs_error);
        x0=x1;
        count++;
    }while(abs_error>0.000005 && count<100);
    printf("\n\t Root = %.5f",x1);
    return 0;
}