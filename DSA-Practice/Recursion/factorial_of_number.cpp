#include<iostream>
int factorial_using_recursion(int n)
{
    if(n>0)
        return factorial_using_recursion(n-1)*n;
    else
        return 1;
}
int factorial_using_loop(int n)
{
    int fact=1;
    while(n>0)
    {
        fact=fact*n;
        n--;
    }
    return fact;
}
int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);
    printf("The factorial of %d using recursion is %d\n",x,factorial_using_recursion(x));
    printf("The factorial of %d using loop is %d\n",x,factorial_using_loop(x));
    return 0;
}