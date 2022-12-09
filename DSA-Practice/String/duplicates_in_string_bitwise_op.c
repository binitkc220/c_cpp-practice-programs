#include<stdio.h>

void findDpulicatBitwise(char *s)
{
    int H=0,x=0;
    for(int i=0;s[i]!='\0';i++)
    {
        x=1;
        x = x << (s[i]-97);
        if((x & H)>0)
            printf("%c is duplicate.\n",s[i]);
        else
            H = x | H;
    }
}
int main()
{
    char *s;
    printf("Enter your string : ");
    scanf("%[^\n]s",s);
    findDpulicatBitwise(s);
    return 0;
}
