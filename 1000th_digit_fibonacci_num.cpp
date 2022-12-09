#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long int a=0,b=1,i=1,sum;
    while(true)
    {
        sum=a+b;
        b=a;
        a=sum;
        if(int(log10(a)+1)==1000)
        {
            cout << i << " = " << a;
            break;
        }
        i++;
    }
}