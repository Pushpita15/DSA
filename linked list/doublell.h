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
dNode* search_by_pos(dNode*ptrhead,int pos);
void add_in_between_after(dNode*ptrhead,int pos,int value);
void add_in_between_before(dNode*ptrhead,int pos,int value);
void delete_in_between_after(dNode*ptrhead,int pos);
void delete_in_between_before(dNode*ptrhead,int pos);