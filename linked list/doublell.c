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
dNode* search_by_pos(dNode*ptrhead,int pos)
{
    int i,c=1;
    if(ptrhead==NULL)
    {
        printf("its null");
        return NULL;
    }
        
    if(pos<=0)
    {
        printf("invalid position");
        return NULL;
    }
    
    
    for(i=1;i<pos;i++)
    {
        ptrhead=ptrhead->next;
    }

    /*while(ptrhead->next!=NULL)
    {
        ptrhead=ptrhead->next;
        c++;
    }
    if(pos>c)
    {
        printf("invalid position");
        return NULL;
    }*/
    return ptrhead;
}

void add_in_between_after(dNode*ptrhead,int pos,int value)
{
    dNode*nodeptr;
    nodeptr=search_by_pos(ptrhead,pos);
    dNode*new=create(value);
    new->prev=nodeptr;
    new->next=nodeptr->next;
    nodeptr->next->prev=new;
    nodeptr->next=new;

}
void add_in_between_before(dNode*ptrhead,int pos,int value)
{
    dNode*nodeptr;
    nodeptr=search_by_pos(ptrhead,pos);
    dNode*temp=create(value);
    temp->prev=nodeptr->prev;
    temp->next=nodeptr;
    nodeptr->prev->next=temp;
    nodeptr->prev=temp;
}

void delete_in_between_after(dNode*ptrhead,int pos)
{
    dNode * ptr=search_by_pos(ptrhead,pos);
    dNode * temp=ptr->next;
    temp->next->prev=ptr;
    ptr->next=temp->next;
    
    
}

void delete_in_between_before(dNode*ptrhead,int pos)
{
    dNode * ptr=search_by_pos(ptrhead,pos);
    dNode * temp=ptr->prev;
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
}
