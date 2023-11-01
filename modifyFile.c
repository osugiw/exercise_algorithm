#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WRITE_ACC   "w"
#define READ_ACC    "r"
#define APPEND_ACC  "a"
#define MODIFY_ACC  "r+"

FILE *fptr_out, *fptr_in;
char* fileName = "files\\test.txt";

void writeNumbersToFile(char* _mode)
{
    int numToSave;
    fptr_out = fopen(fileName, _mode);
    if(fptr_out == NULL)
    {
        printf("Error opening %s", fileName);
        exit(1);
    }

    printf("\nEnter num: ");
    fscanf(stdin, "%d", &numToSave);
    fprintf(fptr_out, "%d", numToSave);
    fclose(fptr_out);
}

void writeCharsToFile(char* _mode)
{
    char stringToSave[255];
    fptr_out = fopen(fileName, _mode);
    if(fptr_out == NULL)
    {
        printf("Error opening %s", fileName);
        exit(1);
    }

    printf("\nEnter chars: ");
    fgets(stringToSave, 255, stdin);

    fputs(stringToSave, fptr_out);
    fclose(fptr_out);

}

void readFile(char* _mode)
{
    char readBuffer[255];

    fptr_in = fopen(fileName, _mode);
    if(fptr_in == NULL)
    {
        printf("Error opening %s", fileName);
        exit(1);
    }

    printf("\nReading content from %s\nResults:\n", fileName);
    while(!feof(fptr_in))
    {
        fgets(readBuffer, 255, fptr_in);   
        printf("- %s", readBuffer);
    }
    fclose(fptr_out);
}

void modifyFileContent(char* _mode)
{
    char _character, find1 = 'a', find2 = '8', newChar = '4';
    fptr_in = fopen(fileName, _mode);
    if(fptr_in == NULL)
    {
        printf("Error opening %s", fileName);
        exit(1);
    }

    printf("\n\nReplacing characters %c, %c with %c:", find1, find2, newChar);
    while (_character != EOF)
    {
        _character = fgetc(fptr_in);
        if(_character == find1 || _character == find2)
        {
            printf("%c", _character);
            fseek(fptr_in, -1, SEEK_CUR);
            fputc(newChar, fptr_in);
            fseek(fptr_in, 0, SEEK_CUR);
        }
    }
    fclose(fptr_in);
}

int main()
{
    writeCharsToFile(WRITE_ACC);
    writeNumbersToFile(APPEND_ACC);
    readFile(READ_ACC);
    modifyFileContent(MODIFY_ACC);
    readFile(READ_ACC);
    return 0;
}