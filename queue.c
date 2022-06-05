#include "queue.h"

//initialisation function for queue
void init(queue * q)
{
    q->f=-1;
    q->r=-1;
}
// function checking if the queue is empty
int isempty(queue * q)
{
    if((q->f==-1) )
    {
        return 1;

    }
        
    else
    {
        return 0;
    }

}

//function checking if the queue is full
int isfull(queue*q)
{
    if( (q->r==S-1 && q->f==0) || (q->f==q->r+1) )
    {
        return 1;

    }

    else
        return 0;
        

}

//function to insert element in a queue
void enqueue(queue*q,ITEM value)
{
    if(isfull(q))
    {
        return;
    }
    else
    {
        if(q->f==-1)
        {
            q->f=0;
            q->arr[q->f]=value;
            q->r++;
        }
        else if(q->r==S-1)
            q->r=0;
        else
            q->r++;
        q->arr[q->r]=value;
        
        
    }
    
    
    
}
//function to delete element in a queue
ITEM dequeue(queue*q)
{
    ITEM temp;
    
    if(isempty(q)==1)
    {
        return 0;
    }
    else
    {
        temp=q->arr[q->f];
        if(q->r==q->f)
            q->r=q->f=-1;
        else if(q->f==S-1)
            q->f=0;
        else
            q->f++;
        
    }
    
    return temp;
}

void display(queue * q)
{
    int i;

    for(i=q->f;i<S;i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n%d %d ",q->r,q->f);
}