#include "cll.h"
#include<stdlib.h>
//function to create a node
CNode* create_node(int value)
{
    CNode*new;
    new=(CNode*)malloc(sizeof(CNode));
    new->data=value;
    new->next=NULL;
    return new;
}
//function to add nodes to a existing node
void append(CNode**head,int value)
{
    CNode*new_node=create_node(value);
    CNode*current=*head;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    else if(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=new_node;

}
//function to make the created linear linked list to a circular linked list


void make_circular(CNode**head)
{
    CNode*current=*head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=*head;

}
//function to print the elements

void traverse(CNode*head)
{
    CNode*current=head;
    while(current->next!=head)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("%d",current->data);
    
}