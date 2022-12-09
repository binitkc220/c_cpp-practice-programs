#include<stdio.h>
int len(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int isPalindrome(char *s)
{
    char t;
    for(int i=0,j=len(s)-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return 0;
    }
    return 1;
}
int main()
{
    char *s;
    printf("Enter your string : ");
    scanf("%[^\n]s",s);
    if(isPalindrome(s))
        printf("String is palindrome!\n");
    else
        printf("String is not palindrome!\n");
    return 0;
}