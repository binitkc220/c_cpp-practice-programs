#include<iostream>
int fun(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
}
int main()
{
    int a=5;
    printf("%d",fun(a));
    return 0;
}