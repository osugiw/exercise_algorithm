#include <stdio.h>

void fibonacci(int n)
{
    int fibArr[n];

    fibArr[0] = 0;
    fibArr[1] = 1;

    for(int i=2; i<n; i++)
        fibArr[i] =  fibArr[i-2] + fibArr[i-1];

    for(int j=0; j<n; j++)
        printf("%d ", fibArr[j]);
}

int main()
{
    int n;

    printf("Enter how many fibonacci length: ");
    scanf("%d", &n);
    fibonacci(n);

    return 0;
}