#include<iostream>

//Using Recursion
double e(int x, int n)
{
    static double r=1;
    if(n==0)
        return r;
    r=1+x*r/n;
    return e(x,n-1);
}
int main()
{
    printf("%lf",e(4,20));
}

//Using Loop
// double e(int x, int n)
// {
//     double s=1;
//     while(n>0)
//     {
//         s=1+x*s/n;
//         n--;
//     }
//     return s;
// }
// int main()
// {
//     printf("%lf",e(4,20));
// }