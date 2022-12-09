#include<iostream>
int pow(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return pow(m*m,n/2);
    else
        return m*pow(m*m,(n-1)/2);
}
int main()
{
    int m,n;
    printf("Enter m,n of m^n : ");
    scanf("%d%d",&m,&n);
    printf("Ans = %d\n",pow(m,n));
    return 0;
}