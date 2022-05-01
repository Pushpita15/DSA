#include "ll.h"
#include <stdlib.h>

Node* create_node(int value)
{
    Node* temp;

    temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}


void append(Node** head, int value)
{
    Node* temp = create_node(value);
    Node* current = *head;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
    //printf("appended");
}
void traverse(Node* head)
{
   
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void delete(Node **head,int n)
{
    Node* current=*head;
    int i=1;
    if(n==1)
    {
        *head=(*head)->next;
    }
    while(i==n-1 && head!=NULL)
    {
        current->next=current->next->next;
        i++;
    }
    current=current->next;

}
void addbefore(Node** current,int value,int n)
{
   

    if(n==1)
    {
        Node *new=create_node(value);
        
        new->next=(*current);
        (*current)=new->next;
    }
    while(n--)
    {
        
        if(n==0){
            
            Node *new=create_node(value);
            new->next=*current;
            
            *current=new;
        }
        else
        {
            current=&(*current)->next;

        }
        
    }
   
}
void addafter(Node**current,int value,int n)
{
    
    
    while(n--)
    {
        if(n==0)
        {
            Node *new=create_node(value);
            
            

            new->next=(*current);

            

            
            *current=new;
            


        }
        else{
            current=&(*current)->next;
        }

    }
    

}
void addatn(Node**current,int value,int n)
{
    
    while(n--)
    {
        if(n==0)
        {
            Node *new=create_node(value);
            
            

            new->next=(*current)->next;

            

            
            *current=new;
            


        }
        else{
            current=&(*current)->next;
        }

    }
    

}