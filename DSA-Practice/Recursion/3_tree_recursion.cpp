#include<iostream>
void fun(int n)
{
    if(n>0)
    {
        printf("%d\t",n);
        fun(n-1);
        fun(n-1);
    }
}
int main()
{
    fun(3);
}