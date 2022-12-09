#include<stdio.h>
int len(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int isAnagram(char *s1, char *s2)
{
    int H[52] = {0};    //0-25 for lowecase and 26-51 for uppercase
    char ch;
    if(len(s1)!=len(s2))
        return 0;
    for(int i=0;s1[i]!='\0';i++)
    {
        ch = s1[i];
        if(ch>=97 && ch<=122)
            H[ch-97]++;  //for lowecase
        else
            H[ch-65+26]++;  //for uppercase
    }
    for(int i=0;s2[i]!='\0';i++)
    {
        ch = s2[i];
        if(ch>=97 && ch<=122)
        {
            if(--H[ch-97]==-1)
                return 0;
        }
        else
        {
            if(--H[ch-65+26]==-1)
                return 0;
        }
    }
    return 1;
}
int main()
{
    if(isAnagram("verbose","observe"))
        printf("Anagram!\n");
    else
        printf("Not Anagram!\n");
}