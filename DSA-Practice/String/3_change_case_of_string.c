#include<stdio.h>
void changeCase(char *s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>=97)
            s[i]-=32;
        else
            s[i]+=32;
        i++;
    }
}
int main()
{
    char *s;
    printf("Enter your string : ");
    scanf("%[^\n]s",s);
    printf("Original String : %s\n",s);
    changeCase(s);
    printf("String after changing case : %s\n",s);
    return 0;
}