#include <stdio.h>

void rotateArrLeft(int *arr, int arrLength, int step)
{
    int buff;
    for(int move=0; move<step; move++)
    {
        buff = arr[0];
        for(int index=0; index<arrLength-1; index++)
            arr[index] = arr[index+1];
        arr[arrLength-1] = buff;
    }
}

void rotateArrRight(int *arr, int arrLength, int step)
{
    int buff;
    for(int move=0; move<step; move++)
    {
        buff = arr[arrLength-1];
        for(int index=arrLength; index>0; index--)
            arr[index] = arr[index-1];
        arr[0] = buff;
    }
}

void printArr(int *arr, int arrLength)
{
    for(int i=0; i<arrLength; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    int step;

    printf("Original Array: "); printArr(arr, arrLength);
    printf("\nEnter step number to rotate to the left: ");
    scanf("%d", &step);
    printf("\nRotated Array to the left: "); rotateArrLeft(arr, arrLength, step); printArr(arr, arrLength);
    printf("\nEnter step number to rotate to the right: ");
    scanf("%d", &step);
    printf("\nRotated Array to the right: "); rotateArrRight(arr, arrLength, step); printArr(arr, arrLength);
    return 0;
}