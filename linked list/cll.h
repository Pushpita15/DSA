#include<stdio.h>

typedef struct st{
    int data;
    struct st*next;
}CNode;
CNode* create_node(int value);
void append(CNode**head,int value);
void make_circular(CNode**head);
void traverse(CNode*head);
