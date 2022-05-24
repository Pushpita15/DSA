#include "qcll.h"

void init(node**ptrear)
{
    *ptrear=NULL;
}
void enqueue(node**ptrear,int value)
{
    node * temp=(node*)malloc(sizeof(node));
    temp->data=value;
    if(*ptrear==NULL)
    {
        temp->next=temp;
        
    }
    else
    {
        temp->next=(*ptrear)->next;
        (*ptrear)->next=temp;
    }
    *ptrear=temp;

}

int dequeue(node**ptrear)
{
    node*ptfront=*ptrear;
    if(*ptrear==NULL)
        return 0;
    else
    {

       int val=(*ptrear)->next->data;
       ptfront=(*ptrear)->next;
       if( (*ptrear)->next==*ptrear )
            *ptrear=NULL;
       else
       {
          (*ptrear)->next=ptfront->next;
       } 
       free(ptfront);
       return val;


    }
}