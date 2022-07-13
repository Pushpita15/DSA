#include<stdio.h>
#include<stdlib.h>
typedef struct str{
    int data;
    struct str * left;
    struct str * right;
}Tnode;
#define ITEM Tnode *
#define S 4
typedef struct{
    int f,r;
    ITEM * arr;
    int size;
}queue;

void init(queue * q,int size);
int isempty(queue * q);
int isfull(queue*q);
void enqueue(queue*q,ITEM value);
ITEM dequeue(queue*q);
void display(queue * q);
