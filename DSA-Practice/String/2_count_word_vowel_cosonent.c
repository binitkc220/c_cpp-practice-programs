#include<stdio.h>
int main()
{
    char *s,ch;
    int i=0,vowel=0,consonent=0,word=0;
    printf("Enter a string ; ");
    scanf("%[^\n]s",s);
    while(s[i]!='\0')
    {
        ch = s[i];
        if(s[i]==' ')
            word++;
        else if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            vowel++;
        else
            consonent++;
        i++;
    }
    printf("No. of vowel characters = %d\n",vowel);
    printf("No. of consonent characters = %d\n",consonent);
    printf("No. of words = %d\n",word+1);
    return 0;
}