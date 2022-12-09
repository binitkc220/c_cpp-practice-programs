#include<stdio.h>
int validateString(char *s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=65 && s[i]<=90) && !(s[i]>=48 && s[i]<=57))
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    char *s;
    printf("Enter your string : ");
    scanf("%s",s);
    if(validateString(s))
        printf("Valid String!");
    else
        printf("Not a Valid String!");
    return 0;
}