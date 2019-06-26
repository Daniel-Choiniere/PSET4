#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <assert.h>

// create our POP (returns the element removed, i.e. removeNode) and PUSH (i.e. addNode) for our que
// create length and peak if possible

typedef struct NODE
{
    int value;
    struct NODE *low;
    struct NODE *high;
} NODE;

typedef struct QNODE
{
    NODE *node;
    struct QNODE *next;
} QNODE;

NODE *rootNode;
QNODE *headNode;

// function declerations
NODE* pop();
void push();

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


    NODE *trav = rootNode;
    while (1)
    {
        if (trav->value == value)
        {
            // printf("Its here\n");
            return 1;
        }
        if (value < trav->value)
        {
            if (!trav->low)
            {
                return 0;
            }
            trav = trav->low;
            continue;
        }
        if (!trav->high)
        {
            return 0;
        }
        trav = trav->high;
        continue;
    }
}

void tests()
{
    assert(!doesContain(100));
    assert(doesContain(7));
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

    push(rootNode);
    push(rootNode->low);
    push(rootNode->high);

    printf("%i\n", pop()->value);
    printf("%i\n", pop()->value);
    tests();

    // displayTreeOnEnter(rootNode);
    printf("\n");
}

void push(NODE* address)
{
    QNODE *newQNode = malloc(sizeof(QNODE));
    newQNode->node = address;
    newQNode->next = NULL;
    if (headNode == NULL)
    {
        headNode = newQNode;
        return;
    }
    QNODE *trav = headNode;
    while(trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = newQNode;
}

// temp storage for the headNode
// reassign the headNode
// return the address of a bi-NODE
NODE* pop()
{
    NODE *temp = headNode->node;
    QNODE *qTemp = headNode;
    headNode = qTemp->next;
    free(qTemp);
    return temp->node;
}

