#include<iostream>
void funB(int);
void funA(int n)
{
    if(n>0)
    {
        printf("%d\t",n);
        funB(n-1);
    }
}
void funB(int n=0)
{
    if(n>1)
    {
        printf("%d\t",n);
        funA(n/2);
    }
}
int main()
{
    funA(20);

}