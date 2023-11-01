// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Node{
    int _data;
    struct Node* next;
};

void insertStart(struct Node** head, int _data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->_data = _data;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node** tail, int _data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *tail;

    newNode->_data = _data;
    newNode->next = NULL;

    // If the list is empty then add the new node as the head
    if(*tail == NULL)
    {
        *tail = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

void insertAfter(struct Node* prevNode, int _data)
{
    if(prevNode == NULL)
    {
        printf("The previous node cannot be empty!");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->_data = _data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

}

void displayLinkedList(struct Node* linkedList)
{
    while(linkedList != NULL)
    {
        printf("%d ", linkedList->_data);
        linkedList = linkedList->next;
    }
}

int main() {
    struct Node *newNode = NULL;
    
    printf("\nInitialize nodes:\n");
    insertStart(&newNode, 50);
    insertStart(&newNode, 100);
    insertStart(&newNode, 80);
    displayLinkedList(newNode);

    printf("\n\nNew nodes added:\n");
    insertAfter(newNode, 20);
    displayLinkedList(newNode);

    printf("\n\nNew nodes added at the end:\n");
    insertEnd(&newNode, 10);
    displayLinkedList(newNode);

    return 0;
}