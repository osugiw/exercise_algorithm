#include <stdio.h>
#include <string.h>

void reverseString(char* inputText)
{
    char buffer;
    int textLength = strlen(inputText);
    char reversedString[textLength];

    for(int i = textLength - 1; i>=0; --i)
        reversedString[textLength-1-i] = inputText[i]; 

    // printf("\nReversed text: ");
    // for(int j=0; j<textLength; j++)
    //     putchar(reversedString[j]);

    printf("\n- Check by comparing the original and reversed string said %s ", inputText);
    if(strcmp(inputText, reversedString) == 0)
        printf("is palindrome!");
    else
        printf("is not palindrome!");
}

void checkPalindrome(char* _inputStr)
{
    int textLength;
    textLength = strlen(_inputStr);
    
    printf("- Check each characters method said %s ", _inputStr);
    for(int i=0; i<textLength; i++)
    {
        if(_inputStr[i] != _inputStr[textLength-i-1])
        {
            printf("is not palindrome!");
            return;
        }
    }
    printf("is palindrome!");
}

int main()
{
    char inputText[255];

    printf("Input the text to check palindrome: ");
    scanf("%s", inputText);

    // Check palindrome by its characters
    checkPalindrome(inputText);

    // Check palindrome by comparing original and reversed
    reverseString(inputText);
    return 0;
}