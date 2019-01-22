#include <stdio.h>
#include <stdlib.h>

typedef struct node_v
{
    char *Nachname;
    int MatNr;
    struct node_v *prev;
    struct node_v *next;
} Node_v;

typedef Node_v *Node;

void print(Node node)
{
    while (node->prev != NULL)
        node = node->prev;

    printf("   [%s]", node->Nachname);

    while (node->next != NULL)
    {
        node = node->next;
        printf("-[%s]", node->Nachname);
    }

    printf("\n");
}

void connect(Node first, Node second)
{
    first->next = second;
    second->prev = first;
}

Node createNode(char *last_name, int MatNr)
{
    Node node = (Node)malloc(sizeof(Node_v));
    node->MatNr = MatNr;
    node->Nachname = last_name;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int areTheyNeighbours(Node A, Node B)
{
    return (A->next == B && B->prev == A) || (A->prev == B && B->next == A);
}

void refreshOuterPointers(Node A)
{
    if (A->prev != NULL)
        A->prev->next = A;

    if (A->next != NULL)
        A->next->prev = A;
}

void swap(Node A, Node B)
{
    Node swapperVector[4];
    Node temp;

    if (A == B)
        return;

    if (B->next == A)
    {
        temp = A;
        A = B;
        B = temp;
    }

    swapperVector[0] = A->prev;
    swapperVector[1] = B->prev;
    swapperVector[2] = A->next;
    swapperVector[3] = B->next;

    if (areTheyNeighbours(A, B))
    {
        A->prev = swapperVector[2];
        B->prev = swapperVector[0];
        A->next = swapperVector[3];
        B->next = swapperVector[1];
    }
    else
    {
        A->prev = swapperVector[1];
        B->prev = swapperVector[0];
        A->next = swapperVector[3];
        B->next = swapperVector[2];
    }

    refreshOuterPointers(A);
    refreshOuterPointers(B);
}

void bubble_sort(Node a)
{
    Node ptr = a;
    while (ptr != NULL)
    {
        if (ptr->next != NULL)
        {
            if (ptr->Nachname[0] > ptr->next->Nachname[0])
            {
                swap(ptr->next, ptr);
            }
        }
        ptr = ptr->next;
    }
}

int main()
{
    Node n1 = createNode("Musterfrau", 1);
    Node n2 = createNode("Lustig", 2);
    Node n3 = createNode("Test", 3);
    Node n4 = createNode("Peter", 4);

    connect(n1, n2);
    connect(n2, n3);
    connect(n3, n4);

    printf("INPUT:\n");
    print(n2);

    printf("SORTING...\n");
    bubble_sort(n1);
    print(n1);
    return 0;
}
