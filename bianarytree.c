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


    if (!rootNode)
    {
        rootNode = newNode;
        return;
    }

    NODE *trav = rootNode;
    while (true)
    {
        if (newNode->value < trav->value)
        {
            // checks to see if there is a trav->low value
            if (!trav->low)
            {
                trav->low = newNode;
                return;
            }
            // if there is already a value at trav->low than we need to go down a level and restart the loop
            trav = trav->low;
            continue;
        }
        else
        {
            if (!trav->high)
            {
                trav->high = newNode;
                return;
            }
            trav = trav->high;
            continue;
        }
    }
}

void displayTreeOnEnter(NODE *curNode)
{
    printf("%i, ", curNode->value);

    if (curNode->low)
    {
        displayTreeOnEnter(curNode->low);
    }
    if (curNode->high)
    {
        displayTreeOnEnter(curNode->high);
    }
}

void displayTreeOnDeparture(NODE *curNode)
{
    // 4 7 6 5 9 8 13 18 20 17 15 10

    if (curNode->low)
    {
        displayTreeOnDeparture(curNode->low);
    }
    if (curNode->high)
    {
        displayTreeOnDeparture(curNode->high);
    }
    printf("%i, ", curNode->value);
}


int doesContain(int value)
{
    // can use the global rootNode
    // search the tree
    // return 0 if the value is not in the tree, return 1 if the value does exist in the tree
    if (rootNode)
    {
        if (value == rootNode->value)
        {
            printf("It's here!\n");
            return 1;
        }
        else if (value == rootNode->high->value)
        {
            printf("It's here!\n");
            return 1;
        }
        else if (value == rootNode->low->value)
        {
            printf("It's here!\n");
            return 1;
        }
    }
    printf("It's not here!\n");
    return 0;
}




int main(void)
{
    // printf("Hello World\n");
    addNode(10);
    addNode(8);
    addNode(15);
    addNode(17);
    addNode(20);
    addNode(18);
    addNode(5);
    addNode(6);
    addNode(9);
    addNode(4);
    addNode(13);
    addNode(7);

    // displayTreeOnEnter(rootNode);
    // displayTreeOnDeparture(rootNode);

    doesContain(10);
    doesContain(8);
    doesContain(15);
    doesContain(29);
    doesContain(33);
    doesContain(12);
    printf("\n");
}


// display node values on departure
