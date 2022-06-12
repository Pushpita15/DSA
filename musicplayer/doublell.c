#include "doublell.h"
#include<stdlib.h>
#include<string.h>

dNode * create(ITEM value)
{
    
    dNode * head=(dNode*)malloc(sizeof(dNode));
    head->data=strdup(value);
    head->next=NULL;
    head->prev=NULL;
    
    return head;

}
void addend(dNode**head,dNode**tail,ITEM value)
{
    dNode*new=create(value);
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return;
    }
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;

}
void addbegin(dNode**head,ITEM value)
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
        printf("%s ",head->data);
        head=head->next;
    }
    
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
    dNode*head=ptrhead;
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
    while(ptrhead->next!=NULL)
    {
        c++;
        ptrhead=ptrhead->next;
        
    }
    if(pos>c)
    {
        printf("invalid position");
        return NULL;
    }
    
    
    for(i=1;i<pos;i++)
    {
        head=head->next;
    }

    return head;
}
dNode*search_by_value(dNode*ptrhead,ITEM value)
{
    if(ptrhead==NULL)
        return NULL;
    else
    {
        while(ptrhead!=NULL)
        {
            if(ptrhead->data==value)
                return ptrhead;
            else
                ptrhead=ptrhead->next;
        }
    }
}
void add_in_between_after(dNode*ptrhead,int pos,ITEM value)
{
    dNode*nodeptr;
    if(ptrhead==NULL)
        return;
    else{
        nodeptr=search_by_pos(ptrhead,pos);
        dNode*new=create(value);
        new->prev=nodeptr;
        new->next=nodeptr->next;
        nodeptr->next->prev=new;
        nodeptr->next=new;
    }

}
void add_in_between_before(dNode*ptrhead,int pos,ITEM value)
{
    dNode*nodeptr;
    if(ptrhead==NULL)
        return;
    else{
        nodeptr=search_by_pos(ptrhead,pos);
        dNode*temp=create(value);
        temp->prev=nodeptr->prev;
        temp->next=nodeptr;
        nodeptr->prev->next=temp;
        nodeptr->prev=temp;
    }
}

void delete_in_between_after(dNode*ptrhead,int pos)
{
    dNode * ptr=search_by_pos(ptrhead,pos);
    dNode * temp=ptr->next;
    temp->next->prev=ptr;
    ptr->next=temp->next;
    free(temp);
    
    
}

void delete_in_between_before(dNode*ptrhead,int pos)
{
    dNode * ptr=search_by_pos(ptrhead,pos);
    dNode * temp=ptr->prev;
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
    free(temp);
}
void delbeg(dNode**head,dNode**tail)
{
    dNode * temp=*head;
    *head=(*head)->next;
    if(*head==NULL)
        *tail=NULL;
    else
    {
        (*head)->prev=NULL;
    }
    free(temp);
}
void deln(dNode*head,int pos)
{   
    dNode * ptr=search_by_pos(head,pos);
    dNode * temp=ptr->next;
    temp->prev=ptr->prev;
    ptr->prev->next=temp;
    free(ptr);
    
}
void sort(dNode**head,dNode**tail)
{
    dNode*p;
    dNode * q;
    dNode * curr;
    dNode * pre=*head;
    curr=(*head)->next;
    if(*head==NULL)
        return;
    while(curr!=NULL)
    {
        p=NULL;
        q=*head;
        while(strcmp(q->data,curr->data)<0 && q!=curr)
        {
            p=q;
            q=q->next;
        }
        if(strcmp(q->data,curr->data)>0 && q!=curr)
        {
            pre->next=curr->next;
            pre->prev=curr;
            curr->next=q;
            curr->prev=p;
            if(p==NULL)
            {
                *head=curr;
            }
            else
            {
                p->next=curr;
            }
            curr=pre->next;

        }
        else
        {
            pre=curr;
            curr=curr->next;

        }
    }

}
//doubly circular linked list
void init(dNode**pthead,dNode**ptrear)
{
    *pthead=NULL;
    *ptrear=NULL;
}
void enqueue(dNode**ptrear,ITEM value)
{
    dNode * new=create(value);
    if(*ptrear==NULL)
    {
        new->next=new;
        new->prev=new;
    }
    else
    {
        new->next=(*ptrear)->next;
        new->prev=(*ptrear);
        (*ptrear)->next->prev=new;
        (*ptrear)->next=new;
    }
    *ptrear=new;
}

ITEM dequeue(dNode**ptrear)
{
    dNode * temp;
    ITEM val;
    if(*ptrear==NULL)
    {
        printf("its null");
        return 0;
    }
    else
    {
        val = (*ptrear)->next->data;
        temp=(*ptrear)->next;
        if(temp==*ptrear)
            *ptrear=NULL;
        else
        {
            (*ptrear)->next=temp->next;
            temp->next->prev=*ptrear;
        }
    }
    free(temp);
    return val;
}

void qtraversenext(dNode*tail)
{
    dNode * temp=tail->next;
    if(tail==NULL)
        printf("its null");
    do
    {
        printf("%s \n",temp->data);
        temp=temp->next;

    }while(temp!=tail->next);

}
void qtraverseprev(dNode*tail)
{
    dNode * temp=tail;
    if(tail==NULL)
        printf("its null");
    do
    {
        printf("%s ",temp->data);
        temp=temp->prev;
    }while(temp!=tail);

}