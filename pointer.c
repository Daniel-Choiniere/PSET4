#include <stdio.h>
#include <stdlib.h>

// struct called node containing
//  an int identified as 'value',
//  a reference to another node identified as 'next'

#define true 1
#define false 0

typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

NODE *rootNode;

int add(int *x, int y)
{
    *x += 3;
    return *x + y;
}

// iterate through the linked list until you get to the end
// once at end print out last value
// once at the end add the new node to the list

void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    if (rootNode == NULL)
    {
        rootNode = newNode;
        return;
    }
    NODE *trav = rootNode;
    while(trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = newNode;
}

void removeNode(int value)
{
    //if empty list will crash
    NODE *trav = rootNode;
    if(rootNode->value == value)
    {
        rootNode = rootNode->next;
        free(trav);
        return;
    }

    while(trav->next->value != value)
    {
        trav = trav->next;
    }
    NODE *temp = trav->next;
    trav->next = temp->next;
    free(temp);
}

void displayList()
{
    NODE* trav = rootNode;
    //should display
    // 5, 10, 8, 17

    while(trav->next != NULL)
    {
        printf("%i, ", trav->value);
        trav = trav->next;
    }
    printf("%i\n", trav->value);
}

void freeListFunction()
{
    while (rootNode->next)
    {
        // set a traveler so we do not alter the value of rootNode
         NODE* trav = rootNode;

        // gets the last element of the list
        while(trav->next)
        {
            trav = trav->next;
        }
        // calls on removeNode to delete the node
        removeNode(trav->value);
    }
    // free the current "rootNode"
    free(rootNode);
}

void freeList()
{
    while (rootNode->next)
    {
        NODE* trav = rootNode;
        while (trav->next->next)
        {
            trav = trav->next;
        }
        // printf("%i\n", trav->value);
        free(trav->next);
        trav->next = NULL;
    }
    free(rootNode);
}

void freeListSelf(NODE *currentNode)
{
    if(currentNode->next)
    {
        freeListSelf(currentNode->next);
    }
    free(currentNode);
}


int main(void)
{
    // NODE rootNode;
    // rootNode.value = 5;
    // rootNode.next = NULL;
    addNode(5);
    addNode(10);
    addNode(8);
    addNode(17);
    displayList();
    // removeNode(17);
    // displayList();

    // freeListFunction();
    freeListSelf(rootNode);

    // printf("%i\n%i\n", rootNode.next->next->value, rootNode.next->next->next->value);

    // int a = 5;
    // int b = 10;
    // printf("the total is: %i\n", add(&a, b));
    // printf("the total is: %i\n", add(&a, b));
    // int* intPointer;
    // intPointer = &b;
    // printf("b is: %i\n", b);
    // *intPointer = 47;
    // printf("b is %i\n", b);
}
