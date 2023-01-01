#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x)
{
    return x*sin(x)+cos(x);
}

int main()
{
    float a,b,m,root,n;
    int i=1, min_steps;
    printf("Enter the interval : ");
    scanf("%f%f",&a,&b);
    if(f(a)*f(b) > 0)
    {
        printf("Root doesnot exist in given interval !");
        exit(0);
    }
    if(f(a)*f(b)==0)
    {
        if(f(a)==0)
            root = a;
        else if(f(b)==0)
            root = b;
    }
    n = ceil((log(b-a)-log(0.0005))/log(2));
    min_steps = (int) n;
    printf("Minimun Iteration to solve given equation = %d \n",min_steps);
    printf("Itr\ta\tb\tc\tf(c)\n");
    do
    {
        m = (a+b)/2;
        printf("%d\t%.4f\t%.4f\t%.4f\t%.4f\n",i,a,b,m,f(m));
        if(f(a)*f(m)<0)
            b = m;
        else
            a = m;
        root = m;
        i++;
    }while((fabs(f(m)))>0.0005 && i<=min_steps);
    printf("\n\tRoot = %.4f",root);
    return 0;
}