#include <stdio.h>

typedef struct st
{
    int data;
    struct st* next;
}Node;

Node* create_node(int value);
void append(Node** head, int value);
void traverse(Node* head);
void delete(Node** head,int n);
void addbefore(Node** head,int value,int n);
void addafter(Node**head,int value,int n);
void addatn(Node**current,int value,int n);