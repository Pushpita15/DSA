#include<stdio.h>
#define ITEM int
#define S 4
typedef struct{
    ITEM f,r;
    ITEM arr[S];
}queue;
void init(queue * q);
ITEM isempty(queue * q);
ITEM isfull(queue*q);
void enqueue(queue*q,ITEM value);
ITEM dequeue(queue*q);

