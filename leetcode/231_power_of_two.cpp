#include<iostream>
bool isPowerOfTwo(int n)
{
    while(n>0)
    {
        if(n==1)
            return 1;
        if(n%2==0)
            n=n/2;
        else
            return 0;
    }
    return 1;
}
int main()
{
    printf("%d\n",isPowerOfTwo(24));
}