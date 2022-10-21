#include <stdio.h>

typedef int ElementType;

struct Node
{
    /* data */
    ElementType Data;
    /* 다음 Node */
    struct Node *NextNode
};

typedef struct tagNode
{
    /* data */
    ElementType Data;
    struct tagNode *NextNode
} Node;

Node MyNode;

Node *SLL_CreateNOde(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
}