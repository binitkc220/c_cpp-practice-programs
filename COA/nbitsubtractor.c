#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 8   //n=bit

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

void padding(char *num) {
    int len = strlen(num);
    int paddingZeros = n - len;
    
    // Shift the characters to the right by the number of padding zeros
    for (int i = len; i >= 0; i--){
        num[i + paddingZeros] = num[i];
    }

    // Add padding zeros to the beginning of the string
    for (int i = 0; i < paddingZeros; i++){
        num[i] = '0';
    }
}

void nbitadder(char num1[], char num2[], char* sum) {
    char c='0', a, b, s, n1[n+1],n2[n+1];
    int i;
    strcpy(n1,num1);
    strcpy(n2,num2);

    padding(n1);
    padding(n2);

    strrev(n1);
    strrev(n2);
    for(i=0;i<n;i++) {
        a = n1[i];
        b = n2[i];
        s = XOR(XOR(a,b),c);
        c = (c=='0')? AND(a,b) : OR(a,b);
        sum[i] = s;
    }
    sum[i] = '\0';
    strrev(sum);
}

void twoscomplement(char *num, char *result) {
    int i;
    padding(num);
    for(int i=0;i<n;i++)
        num[i] = (num[i]=='0')?'1':'0';
    nbitadder(num,"1",result);
}

void nbitsubtractor(char num1[], char num2[], char* difference) {
    char n1[n+1], n2[n+1], resulttwoscomplement[n+1];
    strcpy(n1,num1);
    strcpy(n2,num2);
    twoscomplement(n2, resulttwoscomplement);
    nbitadder(n1,resulttwoscomplement,difference);
}

int main()
{
    char a[n+1], b[n+1]; //n=bit and +1 for null character \0
    char difference[n];
    printf("Enter the first number : ");
    scanf("%s",&a);
    printf("Enter the second number : ");
    scanf("%s",&b);
    nbitsubtractor(a,b,difference);
    printf("The difference is %s\n",difference);
    return 0;
}