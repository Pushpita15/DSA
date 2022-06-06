#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int power;
    int coeff;
}poly;
typedef struct st{
    int data;
    struct st*next;
    int power,coeff;
}node;
node* get_node(int coeff,int power);
void append(node**head,int coeff,int power);
void traverse(node*head);
node* padd(node*h1,node*h2);
node* psub(node*h1,node*h2);
node * pmult(node* h1,node* h2);
