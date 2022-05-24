#include "stackll.h"

void init(node**head)
{
    *head=NULL;
    printf("created\n");
}

int isempty(node*head)
{
    if(head==NULL)
        return 1;
    else
        return 0;
}

void push(node**head,int value)
{
    node * new_Node=(node*)malloc(sizeof(node));
    new_Node->data=value;
    new_Node->next=NULL;
    node *curr=*head;
    
    if(*head==NULL)
    {
        *head=new_Node;
        return;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;

    }
    curr->next=new_Node;
}

/*void traverse(node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}*/  //checking whether the list is created


int  pop(node**tail)
{
    node* curr=*tail;
    node* temp=curr;
    if(isempty(*tail)==1)
        return 0;
    else 
    {
        while(curr->next!=NULL)
        {
            temp=curr;
            curr=curr->next;
        }
        temp->next=NULL;
        return curr->data;
        free(curr);
        
    }

}

