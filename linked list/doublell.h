#include<stdio.h>

typedef struct st{
    int data;
    struct st*prev;
    struct st*next;

}dNode;

dNode * create(int value);
void addbegin(dNode**head,int value);
void addend(dNode**head,dNode**tail,int value);
void traversenext(dNode*head);
void traverseprev(dNode*tail);