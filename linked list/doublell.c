#include "doublell.h"
#include<stdlib.h>

dNode * create(int value)
{
    
    dNode * head=(dNode*)malloc(sizeof(dNode));
    head->data=value;
    head->next=NULL;
    head->prev=NULL;
    
    return head;

}
void addend(dNode**head,dNode**tail,int value)
{
    dNode*new=create(value);
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return;
    }
    (*tail)->next=new;
    new->prev=*tail;
    *tail=new;

}
void addbegin(dNode**head,int value)
{
    dNode*newnode=create(value);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else if((*head)->prev==NULL)
    {
        (*head)->prev=newnode;
    }
    newnode->next=*head;
    *head=newnode;
}
void traversenext(dNode*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void traverseprev(dNode*tail)
{

    while(tail!=NULL)
    {
        printf("%d ",tail->data);
        tail=tail->prev;
    }
    printf("\n");

}
