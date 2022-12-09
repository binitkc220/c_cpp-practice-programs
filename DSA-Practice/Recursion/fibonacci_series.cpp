#include<iostream>
int fib_using_loop(int n)
{
    int t1=0,t2=1,s;
    for(int i=2;i<=n;i++)
    {
        s=t1+t2;
        t1=t2;
        t2=s; 
    }    
    return t2;
}
int fib_using_normal_recursion(int n)
{
    if(n<=1)
        return n;
    else
        return fib_using_normal_recursion(n-2)+fib_using_normal_recursion(n-1);
}
//Optimized recursion
int F[100];
int fib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2] = fib(n-2);
        if(F[n-1]==-1)
            F[n-1] = fib(n-1);
        return F[n-2]+F[n-1];
    }
}
int main()
{
    for(int i=0;i<10;i++)
        F[i] = -1;
    printf("%d",fib(8));
}