#include<stdio.h>
int len(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int main()
{
    char *s = "Welcome";
    printf("Length = %d",len(s));
    return 0;
}