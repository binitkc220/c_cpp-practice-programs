#include<stdio.h>
#include<string>

int romanToInt(std::string s){
    int roman[90] = {0};
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int num = 0;
    for(int i=0;i<s.size();i++)
    {
        if (roman[s[i]]<roman[s[i+1]])
            num -= roman[s[i]];
        else
            num += roman[s[i]];
    }
    return num;
}
int main()
{
    printf("%d",romanToInt("LVIII"));
}