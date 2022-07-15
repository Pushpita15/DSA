#include "heap_prac.h"

void init(heap * h,int size)
{
    h->arr=(item*)malloc(sizeof(item)*size);
    h->size=size;
    h->rear=-1;
}

void swap(item * a, item * b)
{
    item t=*a;
    *a=*b;
    *b=t;
}

void max_insert(heap * h,item val)
{
    if(h->rear==h->size-1)
        return;
    else
    {
        int c,p;
        h->rear++;
        h->arr[h->rear]=val;
        c=h->rear;
        while(c!=0)
        {
            p=(c-1)/2;
            if(h->arr[p]<h->arr[c])
            {
                swap(&h->arr[p],&h->arr[c]);
                c=p;
            }
            else
                break;

        }

    }
}

void min_insert(heap * h,item val)
{
    if(h->rear==h->size-1)
        return;
    else
    {
        int c,p;
        h->rear++;
        h->arr[h->rear]=val;
        c=h->rear;
        while(c!=0)
        {
            p=(c-1)/2;
            if(h->arr[p]>h->arr[c])
            {
                swap(&h->arr[p],&h->arr[c]);
                c=p;
            }
            else
                break;

        }

    }
}



item max_delete(heap * h)
{
    if(h->rear==-1)
        return 0;
    else
    {
        int c,p,tmp;
        tmp=h->arr[0];
        h->arr[0]=h->arr[h->rear];
        h->rear--;
        p=0;
        do
        {
            c=2*p+1;
            if(c>h->rear)
                break;
            if(c < h->rear && h->arr[c]< h->arr[c+1] )
                ++c;
            if(h->arr[p] < h->arr[c])
            {
                swap(&h->arr[p],&h->arr[c]);
                p=c;
            }
            else
                break;
        }while(c<=h->rear);
        return tmp;
    }
}

item min_delete(heap * h)
{
    if(h->rear==-1)
        return 0;
    else
    {
        int c,p,tmp;
        tmp=h->arr[0];
        h->arr[0]=h->arr[h->rear];
        h->rear--;
        p=0;
        do
        {
            c=2*p+1;
            if(c>h->rear)
                break;
            if(c < h->rear && h->arr[c]> h->arr[c+1] )
                ++c;
            if(h->arr[p] > h->arr[c])
            {
                swap(&h->arr[p],&h->arr[c]);
                p=c;
            }
            else
                break;
        }while(c<=h->rear);
        return tmp;
    }
}
void display(heap * h)
{
    int i;
    for(i=0; i < h->size;i++)
    {
        printf(" %d ",h->arr[i]);
    }
}