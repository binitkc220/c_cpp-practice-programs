#include<stdio.h>
#include<string.h>
#define N 8    //no. of bits

char AND(char a, char b) {
    if(a=='1' && b=='1')
        return '1';
    else
        return '0';
}

char OR(char a, char b) {
    if(a=='1' || b=='1')
        return '1';
    else
        return '0';
}

char NOT(char a) {
    if(a=='1')
        return '0';
    else
        return '1';
}

char XOR(char a, char b) {
    return OR(AND(NOT(a),b),AND(a,NOT(b)));
}

char* padding(char* num) {
    int len = strlen(num);
    int paddingZeros = N - len;
    for (int i = len; i >= 0; i--){
        num[i + paddingZeros] = num[i];
    }
    for (int i = 0; i < paddingZeros; i++){
        num[i] = '0';
    }
}

char* nbitadder(char* n1, char* n2) {
    char sum[N+1],c='0', a, b;
    padding(n1);
    padding(n2);
    strrev(n1);
    strrev(n2);
    for(int i=0;i<N;i++) {
        a = n1[i];
        b = n2[i];
        sum[i] = XOR(XOR(a,b),c);
        c = (c=='0')? (AND(a,b)) : (OR(a,b));
    }
    return strrev(sum);
}

int main()
{
    char a[N+1], b[N+1], *sum;
    printf("Enter the first number : ");
    scanf("%s",&a);
    printf("Enter the second number : ");
    scanf("%s",&b);
    sum = nbitadder(a,b);
    printf("The sum is %s",sum);
}