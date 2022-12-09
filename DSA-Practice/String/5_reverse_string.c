#include<stdio.h>
int len(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void reverseString(char *s)
{
    char t;
    for(int i=0,j=len(s)-1;i<j;i++,j--)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}
int main()
{
    char *s;
    printf("Enter your string : ");
    scanf("%[^\n]s",s);
    printf("Original String : %s\n",s);
    reverseString(s);
    printf("Reversed String : %s\n",s);
    return 0;
}