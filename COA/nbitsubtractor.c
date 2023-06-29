#include<stdio.h>
#include "nbitadder.c"

char* twoscomplement(char *num) {
    char toAdd[N+1]="1";
    padding(num);
    printf("padded num = %s\n",num);
    for(int i=0;i<strlen(num);i++)
        num[i] = (num[i]=='1')?'0':'1';
    printf("add num = %s\n",num);
    num = nbitadder(num,toAdd);
    printf("added num = %s\n",num);
    return num;
}

char* nbitsubtractor(char *n1, char *n2) {
    // printf("n2=%s\n",n2);
    twoscomplement(n2);
    printf("n2=%s\n",n2);
    char *sum = nbitadder(n1,n2);
    printf("sum is %s",sum);
    return sum;
}

int main()
{
    char a[N+1]="101", b[N+1]="10", *result;
    result = nbitsubtractor(a,b);
    printf("%s",result);
}