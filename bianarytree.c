#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// create NODE for bianary tree

typedef struct NODE
{
    int value;
    struct NODE *low;
    struct NODE *high;
} NODE;

NODE *rootNode;

void addNode(int value)
{
    NODE *newNode =  malloc(sizeof(NODE));
    newNode->value = value;
    newNode->high = NULL;
    newNode->low = NULL;

    // challange is to add node to tree

    if (!rootNode)
    {
        rootNode = newNode;
        return;
    }

    if (newNode->value < rootNode->value)
    {
        rootNode->low = newNode;
    }
    rootNode->high = newNode;
}



int main(void)
{
    // printf("Hello World\n");
    addNode(10);
    addNode(8);
    addNode(15);
}
