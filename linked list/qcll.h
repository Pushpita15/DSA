#include<stdio.h>
#include<stdlib.h>

typedef struct st{

    int data;
    struct st * next;
}node;

void init(node**ptrear);
void enqueue(node**ptrear,int value);
int dequeue(node**ptrear);
