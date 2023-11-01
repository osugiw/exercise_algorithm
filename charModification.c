#include <stdio.h>
#include <ctype.h>

void reverseString(char* inputText, int textLength)
{
    char buffer;
    for (int i = 0; i < textLength/2; i++)
    {
        buffer = inputText[i];
        inputText[i] = inputText[textLength - 1 - i];
        inputText[textLength - 1 - i] = buffer;
    }

    printf("Reversed text: \n");
    for(int j=0; j<textLength; j++)
        putchar(inputText[j]);
}

void capitalizeString(char* inputText, int textLength)
{
    for(int i=0; i<textLength; i++)
    {
        if(isspace(inputText[i-1]) || i == 0)
            inputText[i] = toupper(inputText[i]);
    }

    printf("Capitalized String: ");
    puts(inputText);
}

int main()
{
    char inputText[255] = {};
    int textLength;

    printf("Enter the original string: ");
    fgets(inputText, sizeof(inputText), stdin);

    textLength = sizeof(inputText) / sizeof(inputText[0]);
    
    // Optional String
    // capitalizeString(inputText, textLength);
    reverseString(inputText, textLength);

    return 0;
}