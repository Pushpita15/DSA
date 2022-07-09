
#include<stdio.h>
#include<stdlib.h>
#define item int

typedef struct str{
    item *arr;
    int rear,size;
}PQ;
void init(PQ* ptr,int size)
{
    ptr->rear=-1;
    ptr->size=size;
    ptr->arr=(item*)malloc(size*sizeof(item));
    printf("done\n");
}
int isempty(PQ* ptr)
{
    if(ptr->rear==-1)
        return 1;
    else
        return 0;
}
int isfull(PQ*ptr)
{
    if(ptr->rear==ptr->size-1)
        return 1;
    else 
        return 0;
}
void swap(item* a,item* b)
{
    item t;
    t=*a;
    *a=*b;
    *b=t;

}

void enq(PQ*ptr,item val)
{
    int child,parent;
    if(isfull(ptr))
        return;
    else
    {
        
        ptr->rear++;
        ptr->arr[ptr->rear]=val;
        child=ptr->rear;
        while(child!=0)
        {
            parent=(child-1)/2;
            if(ptr->arr[parent]<ptr->arr[child]){

                swap(&ptr->arr[parent],&ptr->arr[child]);
                child=parent;
            }
            else
                break;
        }
    }
    
}
item deq(PQ*ptr)
{
    item temp;
    int parent,child;
    if(isempty(ptr))
        return 0;
    temp=ptr->arr[0];
    ptr->arr[0]=ptr->arr[ptr->rear];
    ptr->rear--;
    parent=0;
    do{
        child=2*parent+1;
        if(child>ptr->rear)
            break;
        if(child<ptr->rear && ptr->arr[child]<ptr->arr[child+1] )
            child++;
        if(ptr->arr[parent]<ptr->arr[child])
        {
            swap(&ptr->arr[parent],&ptr->arr[child]);
            parent=child;
        }
        else
            break;
    }while(child<=ptr->rear);
    return temp;
}
int main()
{
    PQ queue;
    int size;
    printf("enter the size of the queue:");
    scanf("%d",&size);
    init(&queue,size);


    //A.
    //1.
    enq(&queue,22);
    enq(&queue,75);
    enq(&queue,96);
    enq(&queue,41);
    enq(&queue,23);
    enq(&queue,12);
    enq(&queue,1);
    enq(&queue,2);
    enq(&queue,56);

    
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));

    printf("\n\n");

    //2.
    
    enq(&queue,96);
    enq(&queue,45);
    enq(&queue,78);
    enq(&queue,93);
    enq(&queue,12);
    enq(&queue,98);
    enq(&queue,74);
    enq(&queue,56);
    enq(&queue,32);

    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));

    printf("\n\n");

    //3.

    enq(&queue,86);
    enq(&queue,92);
    enq(&queue,12);
    enq(&queue,45);
    enq(&queue,63);
    enq(&queue,7);
    enq(&queue,8);
    enq(&queue,41);
    enq(&queue,25);


    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));

    printf("\n\n");

    //4.

    enq(&queue,63);
    enq(&queue,45);
    enq(&queue,17);
    enq(&queue,86);
    enq(&queue,95);
    enq(&queue,42);
    enq(&queue,31);
    enq(&queue,20);

    
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));

    printf("\n\n");

    //5.

    enq(&queue,63);
    enq(&queue,52);
    enq(&queue,14);
    enq(&queue,78);
    enq(&queue,96);
    enq(&queue,5);
    enq(&queue,2);
    enq(&queue,3);
    enq(&queue,6);
    enq(&queue,42);

    
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));

    printf("\n\n");

    printf("---------------------------------------------");

    //B.

    enq(&queue,52);
    enq(&queue,41);
    enq(&queue,96);
    enq(&queue,36);
    enq(&queue,78);
    enq(&queue,96);
    enq(&queue,14);


    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));
    printf("\n\n");
    

    enq(&queue,52);
    enq(&queue,36);
    enq(&queue,74);
    enq(&queue,15);
    enq(&queue,96);
    
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));
    printf("%d is deleted\n",deq(&queue));



    printf("\n\n");

    
    return 0;


}