#include<iostream>
int sum_using_recursion(int n)  //Time=O(n), Space=O(n)
{
    if(n>0)
        return n+sum_using_recursion(n-1);
    else
        return 0;
}
int sum_using_loop(int n)  //Time=O(n), Space=O(n)
{
    int sum=0;
    while(n>0)
    {
        sum=sum+n;
        n--;
    }
    return sum;
}
int sum_using_formula(int n)  //Time=O(1), Space=O(1)
{
    return n*(n+1)/2;
}
int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);
    printf("The sum of first %d natural number using recursion is %d\n",x,sum_using_recursion(x));
    printf("The sum of first %d natural number using loop is %d\n",x,sum_using_loop(x));
    printf("The sum of first %d natural number using formula is %d\n",x,sum_using_formula(x));
    return 0;
}