#include<stdio.h>
#define ITEM char*
typedef struct st{
    ITEM data;
    struct st*prev;
    struct st*next;

}dNode;

dNode * create(ITEM value);
void addbegin(dNode**head,ITEM value);
void addend(dNode**head,dNode**tail,ITEM value);
void traversenext(dNode*head);
void traverseprev(dNode*tail);
dNode* search_by_pos(dNode*ptrhead,int pos);
dNode*search_by_value(dNode*ptrhead,ITEM value);
void add_in_between_after(dNode*ptrhead,int posval,ITEM value);
void add_in_between_before(dNode*ptrhead,int pos,ITEM value);
void delete_in_between_after(dNode*ptrhead,int pos);
void delete_in_between_before(dNode*ptrhead,int pos);
void delbeg(dNode**head,dNode**tail);
void deln(dNode*head,int pos);
void sort(dNode**head,dNode**tail);
void init(dNode**pthead,dNode**ptrear);
void enqueue(dNode**ptrear,ITEM value);
ITEM dequeue(dNode**ptrear);
void qtraversenext(dNode*tail);
void qtraverseprev(dNode*tail);