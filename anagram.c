#include <stdio.h>
#include <string.h>

#define NO_OF_CHAR 256

void checkAnagram(char* _text1, char* _text2)
{
    int countT1[NO_OF_CHAR] = {};
    int countT2[NO_OF_CHAR] = {};
    int i;
    
    for(i=0; _text1[i] && _text2[i]; i++)
    {
        countT1[_text1[i]]++;
        countT2[_text2[i]]++;
    }

    if(_text1[i] || _text2[i])
    {
        printf("%s and %s aren't anagram!\n", _text1, _text2);
        return;
    }

    for (int j = 0; j < NO_OF_CHAR; j++)
    {
        if(countT1[j] != countT2[j])
        {
            printf("%s and %s aren't anagram!\n", _text1, _text2);
            return;
        }
    }
    printf("%s and %s are anagram!\n", _text1, _text2);
    
}

int main()
{
    char _text1[NO_OF_CHAR], _text2[NO_OF_CHAR];

    printf("Enter the first word: ");
    scanf("%s", _text1);
    printf("Enter the second word: ");
    scanf("%s", _text2);
    checkAnagram(_text1, _text2);
    return 0;
}