/*1. Function to delete nth node
2. Function to add a node before nth position
3. Function to add a node after nth position*/




/*1. Print the values of Linked_List in reverse order.
2. Print the values of Linked_List in reverse order using recursion.
3. Reverse the Linked_List.
4. Implement Circular Linked_List.
5. Design a menu including all the functions of Linked_List.*/




#include <stdio.h>

typedef struct st
{
    int data;
    struct st* next;
}Node;
typedef struct 
{
    int mid1,mid2,mid0;

}mid;

Node* create_node(int value);
void append(Node** head, int value);
void traverse(Node* head);
void delete(Node** head,int n);
void addbefore(Node** head,int value,int n);
void addafter(Node**head,int value,int n);
void addatn(Node**current,int value,int n);
void reverse(Node*head);
void reversen(Node**head);
mid retmid(Node**head);
void make_circular(Node**head);