#include<iostream>
#include<cstdlib>
double pow(double x, int n)
{
    if(n==0)
        return 1;
    if(n>0)
    {
        if(n%2==0)
            return pow(x*x,n/2);
        else
            return x*pow(x*x,(n-1)/2);
    }
    else
    {
        n=abs(n);
        if(n%2==0)
            return pow(1/(x*x),n/2);
        else
            return (1/x)*pow(1/(x*x),(n-1)/2);
    }
}
int main()
{
    // int x,n;
    // printf("Enter x,n of x^n : ");
    // scanf("%d%d",&x,&n);
    printf("Ans = %lf\n",pow(2.0000,-2));
    return 0;
}