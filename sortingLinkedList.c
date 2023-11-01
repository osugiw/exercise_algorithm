#include <stdio.h>
#include <math.h>

struct Node
{
    int data;
    struct Node* next;
};

void SLL_insertStart(struct Node** head, int data);
void SLL_insertEnd(struct Node** tail, int data);

void printLL(struct Node* inputList, int lengthOfNodes);
int countLL(struct Node* head);
void bubbleSort(struct Node* inputList, int lengthOfNodes);
void insertionSort(struct Node* inputList, int lengthOfNodes);


int main()
{
    int inputArr[] = {3, 11, 6, 5, 10};
    int lengthOfNodes = sizeof(inputArr) / sizeof(inputArr[0]);
    struct Node* SLL = NULL;

    // Create linked list first
    printf("Creating single linked list: ");
    for(int i=0; i<lengthOfNodes; i++)
        SLL_insertStart(&SLL, inputArr[i]);
    printLL(SLL, countLL(SLL));

    printf("\nLength of the linked list is %d\n", countLL(SLL));
    bubbleSort(SLL, lengthOfNodes);
    // insertionSort(SLL, lengthOfNodes);
    return 0;
}

void printLL(struct Node* inputList, int lengthOfNodes)
{
    struct Node* _list = inputList;
    for (int i = 0; i < lengthOfNodes; i++)
    {
        printf("%d ", _list->data);
        _list  = _list->next; 
    }
}

int countLL(struct Node* head)
{
    struct Node* _list = head;
    int _count = 0;

    while(_list != NULL){
        _count += 1;
        _list = _list->next;
    }
    return _count;
}

void bubbleSort(struct Node* inputList, int lengthOfNodes)
{
    int buff, swapped;
    struct Node* sortedList;
    struct Node* leftPtr = NULL;

    do
    {
        sortedList = inputList;
        swapped = 0;
        while (sortedList->next != leftPtr)
        {
            if(sortedList->data > sortedList->next->data)
            {
                buff = sortedList->data;
                sortedList->data = sortedList->next->data;
                sortedList->next->data = buff;
                swapped = 1;
            }
            sortedList = sortedList->next;
        }
        leftPtr = sortedList;
    } while (swapped);
    
    
    
    printf("Sorted Linked List: ");
    printLL(inputList, lengthOfNodes);
}

// void insertionSort(int* inputArr, int lengthOfNodes)
// {
//     int _key, j;

//     for(int i=1; i<lengthOfNodes; i++)
//     {
//         _key = inputArr[i];
//         j = i-1; 
//         while(_key < inputArr[j] && j>=0)
//         {
//             inputArr[j+1] = inputArr[j];    // Replace the current element with previous element
//             j--;
//         }
//         inputArr[j+1] = _key;               // Replace the previous element with the key
//     }
//     // printLL(inputArr, lengthOfNodes);
// }


void SLL_insertStart(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void SLL_insertEnd(struct Node** tail, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *tail;

    newNode->data = data;
    newNode->next = NULL;

    if(*tail == NULL)
    {
        *tail = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next =  newNode;
    return;
    
}
