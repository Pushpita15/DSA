#include<stdio.h>
#include<stdlib.h>

typedef struct str{
    int data;
    struct str * next;
}node;

void init(node**head);
int isempty(node*head);
void push(node**head,int value);
void traverse(node*head);
int pop(node**head);