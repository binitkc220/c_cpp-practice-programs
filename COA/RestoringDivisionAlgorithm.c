#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 6 // no. of bits

char AND(char a, char b)
{
    if (a == '1' && b == '1')
        return '1';
    else
        return '0';
}

char OR(char a, char b)
{
    if (a == '1' || b == '1')
        return '1';
    else
        return '0';
}

char NOT(char a)
{
    if (a == '1')
        return '0';
    else
        return '1';
}

char XOR(char a, char b)
{
    return OR(AND(NOT(a), b), AND(a, NOT(b)));
}

void padding(char *num, int n)
{
    int len = strlen(num);
    int paddingZeros = n - len;
    for (int i = len; i >= 0; i--)
    {
        num[i + paddingZeros] = num[i];
    }
    for (int i = 0; i < paddingZeros; i++)
    {
        num[i] = '0';
    }
}

void nbitadder(char num1[], char num2[], char *sum)
{
    char c = '0', a, b, s, n1[N + 1], n2[N + 1];
    int i;
    strcpy(n1, num1);
    strcpy(n2, num2);

    padding(n1, N);
    padding(n2, N);

    strrev(n1);
    strrev(n2);
    for (i = 0; i < N; i++)
    {
        a = n1[i];
        b = n2[i];
        s = XOR(XOR(a, b), c);
        c = (c == '0') ? AND(a, b) : OR(a, b);
        sum[i] = s;
    }
    sum[i] = '\0';
    strrev(sum);
}

void twoscomplement(char *num, char *result)
{
    int i;
    padding(num, N);
    for (int i = 0; i < N; i++)
        num[i] = (num[i] == '0') ? '1' : '0';
    nbitadder(num, "1", result);
}

void nbitsubtractor(char num1[], char num2[], char *difference)
{
    char n1[N + 1], n2[N + 1], resulttwoscomplement[N + 1];
    strcpy(n1, num1);
    strcpy(n2, num2);
    twoscomplement(n2, resulttwoscomplement);
    nbitadder(n1, resulttwoscomplement, difference);
}

char *toBin(int num, char *a)
{
    int rem = 0, i = 0;
    char bin[N + 1];
    while (num != 0)
    {
        rem = num % 2;
        bin[i] = (rem == 0) ? '0' : '1';
        i++;
        num = num / 2;
    }
    bin[i] = '\0';
    strcpy(a, bin);
}

int toDec(char *a)
{
    int len = strlen(a) - 1, num, sum = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        num = a[i] == '1' ? 1 : 0;
        sum = sum + num * pow(2, len);
        len--;
    }
    return sum;
}

void LeftShift(char *A, char *Q)
{
    int i;
    for (i = 0; i < strlen(A) - 1; i++)
        A[i] = A[i + 1];
    A[i] = Q[0];
    for (i = 0; i < strlen(Q) - 1; i++)
        Q[i] = Q[i + 1];
    Q[i] = '_';
}

int main()
{
    int divisor, dividend;
    char Q[N], M[N + 1], A[N + 1] = {0}, sub[N + 1], sum[N + 1];
    printf("Enter the Dividend : ");
    scanf("%d", &dividend);
    printf("Enter the divisor : ");
    scanf("%d", &divisor);
    toBin(dividend,Q);
    toBin(divisor,M);
    printf("THis is Q %s\n",Q);
    padding(strrev(Q), N-1);
    padding(strrev(M), N);
    padding(A, N);
    printf("\nA\tQ\tCount\tRemark\n");
    printf("\n%s\t%s\t0\tInitial\n", A, Q);
    for (int i = 0; i < N-1; i++)
    {
        LeftShift(A, Q);
        printf("\n%s\t%s\t-\tLeft Shift A,Q\n", A, Q);
        nbitsubtractor(A, M, sub);
        strcpy(A, sub);
        printf("%s\t%s\t-\tA<-A-M\n", A, Q);
        if (A[0] == '1')
        {
            Q[N - 2] = '0';
            nbitadder(A, M, sum);
            strcpy(A, sum);
            printf("%s\t%s\t%d\tQ0<-0, A<-A+M\n", A, Q, i+1);
        }
        else
        {
            Q[N - 2] = '1';
            printf("%s\t%s\t%d\tQ0<-1\n", A, Q, i+1);
        }
    }
    printf("\nResult : \n");
    printf("\tQuotient : %s(%d)",Q,toDec(Q));
    printf("\tRemainder : %s(%d)",A,toDec(A));
}