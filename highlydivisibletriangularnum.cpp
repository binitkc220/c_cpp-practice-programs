#include<iostream>
using namespace std;
int main()
{
    int triangular_num=0;
    int i=1,j,n,num_factors,power;
    while(true)
    {
        triangular_num = 0;
        for(j=1;j<=i;j++)
        {
            triangular_num = triangular_num+j;
        }
        n = triangular_num;
        num_factors = 1;
        for(int k=2;k*k<=triangular_num;k++)
        {
            power=0;
            while(n%k==0)
            {
                n=n/k;
                ++power;
            }
            num_factors = num_factors * (power+1);
        }
        if(n>1)
        {
            num_factors = num_factors *2;
        }
        if(num_factors>500)
        {
            cout << triangular_num;
            break;
        }
        i++;
    }
}