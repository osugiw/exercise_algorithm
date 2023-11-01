#include <stdio.h>
#include <stdlib.h>

int sumAddOverflow(int* result, int a, int b)
{
    *result = a + b;
    if((a > 0 && b > 0 && *result < 0) || (a < 0  && b < 0 && *result > 0))
        return -1;
    return 0;
}

int main()
{
    int a, b;
    int *result = (int*)malloc(sizeof(int));
    int flagOverflow = 0;

    printf("Program to check overflow (num1,num2): \n");
    scanf("%d,%d", &a, &b);
    flagOverflow = sumAddOverflow(result, a, b);
    if(flagOverflow != 0)
        printf("%d + %d is overflow! (%d)", a, b, *result);
    else
        printf("Sum of two numbers are %d", *result);

    return 0;
}