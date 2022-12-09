#include<stdio.h>
void findDuplicate(char *s)
{
    int count;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=-1)
        {
            count = 1;
            for(int j=i+1;s[j]!='\0';j++)
            {
                if(s[i]==s[j])
                {
                    count++;
                    s[j]=-1;
                }
            }
            if(count>1)
                printf("%c is apperaing %d times.\n",s[i],count);
        }
    }
}
void findDuplicatesHash(char *s)
{
    int H[52]={0};  //0-25 for lowercase and 26-51 for uppercase
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=97 && s[i]<=122)
            H[s[i]-97]++;
        else if(s[i]>=65 && s[i]<=90)
            H[s[i]-65+26]++;    //+26 for uppercase
    }
    for(int i=0;i<52;i++)
    {
        if(H[i]>1 && i<=25)
            printf("%c is appearing %d times.\n",i+97,H[i]);
        else if(H[i]>1 && i>=26)
            printf("%c is appearing %d times.\n",i+65-26,H[i]);
    }
}
int main()
{
    char *s;   //char s[]="findingFINNDING";
    printf("Enter your string : ");
    scanf("%[^\n]s",s);
    findDuplicatesHash(s);
    // findDuplicate(s);
    return 0;
}