#include<stdio.h>
int len(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int compareString(char *s1, char *s2)
{
    int i,j;
    for(i=0,j=0;s1[i]!='\0' && s2[j]!='\0'; i++,j++)
    {
        if(s1[i]!=s2[j])
            break;
    }
    if(s1[i]==s2[j])
        return -1;         //equal
    else if(s1[i]<s2[j])
        return 0;          //smaller
    else
        return 1;          //greater
}
int main()
{
    char a[]="Paint",b[]="Paint";
    if(compareString(a,b)==-1)
        printf("Both string are equal!");
    else
    {
        if(compareString(a,b))
            printf("String A is greater");
        else
            printf("String A is smaller");
    }  
    return 0;  
}