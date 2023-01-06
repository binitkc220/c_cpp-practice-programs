//Secant Method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
    return (pow(x,3)+3*pow(x,2)-5);
}
int main()
{
    float a,b,c;
    int count=0;
    printf("Enter the interval : ");
    scanf("%f%f",&a,&b);
    printf("i\tx(i-1)\tx(i)\tx(i+1)\n");
    do
    {
        if(f(a)==f(b))
        {
            printf("\n\tError in finding root !");
            exit(0);
        }
        c = (a*f(b)-b*f(a))/(f(b)-f(a));
        printf("%d\t%.4f\t%.4f\t%.4f\n",count,a,b,c);
        a=b;
        b=c;
        count++;
    }while(fabs(f(c))>0.00005 && count<100);
    if(count==100)
    {
        printf("\n\tOscillatory Condition !");
        exit(0);
    }
    printf("\n\tRoot = %.4f",c);
    return 0;
}