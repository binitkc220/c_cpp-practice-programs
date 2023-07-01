#include<stdio.h>
#include<string.h>
#define N 4    //no. of bits

char* strrev(char *str)  
{  
    int i, len, temp;  
    len = strlen(str);
    for (i = 0; i < len/2; i++)  
    {  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }
    return str;
}

int power(int a, int b) {
    int result=1;
    for(int i=0;i<b;i++)
        result *= a;
    return result;
}
  

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

void padding(char* num) {
    int len = strlen(num);
    int paddingZeros = N - len;
    for (int i = len; i >= 0; i--){
        num[i + paddingZeros] = num[i];
    }
    for (int i = 0; i < paddingZeros; i++){
        num[i] = '0';
    }
}

char nbitadder(char* n1, char* n2, char*sum, char c) {
    char a, b;
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
    strrev(sum);
    return c;
}

void toBin(int n, char*a){
    int rem=0,i=0;
    char bin[N+1];
    while(n!=0){
        rem = n % 2;
        bin[i] = (rem==0)?'0':'1';
        i++;
        n = n /2;
    }
    bin[i]='\0';
    padding(strrev(bin));
    strcpy(a,bin);
}

int toDec(char*a){
    int len=strlen(a)-1,num,sum=0;
    for(int i=0;i<strlen(a);i++) {
        num = a[i]=='1'?1:0;
        sum = sum + num*power(2,len);
        len--;
    }
    return sum;
}

void RightShift(char C, char *A, char *Q) {
    int i;
    for(i=strlen(Q)-1;i>0;i--)
        Q[i] = Q[i-1];
    Q[0] = A[strlen(A)-1];
    for(i=strlen(A)-1;i>0;i--)
        A[i] = A[i-1];
    A[0] = C;
    C = '0';
}

int main()
{
    int multiplicand,multiplier;
    char M[N+1],Q[N+1], C='0', A[N+1]="0", temp_M[N+1];
    printf("Enter the Multiplicand : ");
    scanf("%d",&multiplicand);
    printf("Enter the Multiplier : ");
    scanf("%d",&multiplier);
    toBin(multiplicand,M);
    toBin(multiplier,Q);
    padding(A);
    printf("\nMultiplier(M) = %s\nMultiplier(Q) = %s\tA=%s\n",M,Q,A);
    printf("\nC\t A\t Q\tCount\t Remark\n");
    printf("\n%c\t%s\t%s\t  0\tInitial\n\n",C,A,Q);
    for(int i=0;i<N;i++) {
        char sum[N+1]="";
        strcpy(temp_M,M);
        if(Q[N-1]=='1'){
            C = nbitadder(A,temp_M,sum,C);
            strcpy(A,sum);
            printf("%c\t%s\t%s\t  %d\tA<-A+M\n",C,A,Q,i+1);
        }
        RightShift(C,A,Q);
        C='0';
        printf("%c\t%s\t%s\t  %d\tRight Shift\n\n",C,A,Q,i+1);
    }
    strcat(A,Q);
    printf("Result = %s i.e, %d",A,toDec(A));
     
}