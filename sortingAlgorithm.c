#include <stdio.h>
#include <math.h>

void printArr(int* inputArr, int lengthOfArr);
void bubbleSort(int* inputArr, int lengthOfArr);
void insertionSort(int* inputArr, int lengthOfArr);

int main()
{
    int inputArr[] = {12, 11, 3, 5, 1};
    int lengthOfArr = sizeof(inputArr) / sizeof(inputArr[0]);
    
    // bubbleSort(inputArr, lengthOfArr);
    insertionSort(inputArr, lengthOfArr);
    return 0;
}

void printArr(int* inputArr, int lengthOfArr)
{
    for (int i = 0; i < lengthOfArr; i++)
        printf("%d ", inputArr[i]);
}

void bubbleSort(int* inputArr, int lengthOfArr)
{
    int buff = NULL;
    for(int i=0; i<lengthOfArr; i++)
    {
        for (int j=i+1; j<lengthOfArr; j++)
        {
            if (inputArr[i] > inputArr[j])
            {
                buff = inputArr[i];
                inputArr[i] = inputArr[j];
                inputArr[j] = buff;
            }
        }
    }
    printArr(inputArr, lengthOfArr);
}

void insertionSort(int* inputArr, int lengthOfArr)
{
    int _key, j;

    for(int i=1; i<lengthOfArr; i++)
    {
        _key = inputArr[i];
        j = i-1; 
        while(_key < inputArr[j] && j>=0)
        {
            inputArr[j+1] = inputArr[j];    // Replace the current element with previous element
            j--;
        }
        inputArr[j+1] = _key;               // Replace the previous element with the key
    }
    // printArr(inputArr, lengthOfArr);
}
