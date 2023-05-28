#include <iostream>
using namespace std;

// Question 5

int helper_vowel(char* str,int length,int itteration )
{
    if ( itteration==length)
    {
        return 0;
    }
    else if (str[itteration]=='a'|| str[itteration]=='e'||str[itteration]=='i'||str[itteration]=='o'||str[itteration]=='u'||str[itteration]=='A'||str[itteration]=='E'|| str[itteration]=='I'||str[itteration]=='O'||str[itteration]=='U')
    {
        itteration++;
        return 1+ helper_vowel(str, length, itteration);
    }
    else
    {
        itteration++;
        return  helper_vowel(str, length, itteration);
    }
}

int findVowels(char* str)
{
    int length=0, vowels=0, itteration=0;
    for (int i=0; str[i]; i++ )
    {
        length++;
    }
    vowels=helper_vowel(str, length, itteration);
    
return vowels;}

int main()
{
    char* ptr= new char[] {"abcdefghijklmnopqrstuvwxyz"};
    cout<<findVowels(ptr);
}

// Question 6