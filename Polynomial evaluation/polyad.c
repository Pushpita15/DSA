#include "polyad.h"


node* get_node(int coeff,int power)
{
    node * newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->coeff=coeff;
    newnode->power=power;
    newnode->next=NULL;

}

void append(node**head,int coeff,int power)
{
    node * newptr=get_node(coeff,power);
    node *current=*head;
    if(*head==NULL)
    {
        *head=newptr;
        return;
    }
    else
    {
        while(current->next!=NULL)
        {
            current=current->next;
        }
    }
    current->next=newptr;
}

void traverse(node*head)
{
    while(head!=NULL)
    {
        printf("%d %d ",head->coeff,head->power);
        head=head->next;
    }
    printf("\n");
}

node* padd(node*h1,node*h2)
{
    node * h3=NULL;
    while(h1!=NULL && h2!=NULL)
    {     
        if(h2->power>h1->power)
        {
            append(&h3,h2->coeff,h2->power);

            h2=h2->next;
        }
            
        else if(h1->power>h2->power)
        {  
            append(&h3,h1->coeff,h1->power);
            
            
            
            h1=h1->next;
        }


        else
        {
            append(&h3,h1->coeff+h2->coeff,h2->power);
            
            h1=h1->next;
            h2=h2->next;
        }


    }
    while(h1!=NULL)
    {
        append(&h3,h1->coeff,h1->power);
        
        
        h1=h1->next;

    }
    while(h2!=NULL)
    {
        append(&h3,h2->coeff,h2->power);
        
        h2=h2->next;
        
    }
    return h3;
}

node* psub(node*h1,node*h2)
{
    node * h3=NULL;
    while(h1!=NULL && h2!=NULL)
    {     
        if(h2->power>h1->power)
        {
            append(&h3,h2->coeff,h2->power);

            h2=h2->next;
        }
            
        else if(h1->power>h2->power)
        {  
            append(&h3,h1->coeff,h1->power);
            
            
            
            h1=h1->next;
        }


        else
        {
            if(h1->coeff>h2->coeff)
                append(&h3,h1->coeff-h2->coeff,h2->power);
            else
                append(&h3,h2->coeff-h1->coeff,h2->power);
            
            h1=h1->next;
            h2=h2->next;
        }


    }
    while(h1!=NULL)
    {
        append(&h3,h1->coeff,h1->power);
        
        
        h1=h1->next;

    }
    while(h2!=NULL)
    {
        append(&h3,h2->coeff,h2->power);
        
        h2=h2->next;
        
    }
    return h3;
}

void del(node**temp)
{
    while(*temp!=NULL)
    {
        *temp=NULL;
    }
    free(*temp);
}

node * pmult(node* h1,node* h2)
{
    node * h3=NULL;
    node *ptr,*temp=NULL;
    while(h2!=NULL)
    {
        ptr=h1;
        while(ptr!=NULL)
        {
            append(&temp,ptr->coeff*h2->coeff,ptr->power+h2->power);
            ptr=ptr->next;
        }
        h3=padd(h3,temp);
        h2=h2->next;
        del(&temp);
    }
    return h3;
}


