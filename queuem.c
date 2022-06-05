#include "queue.h"

int main()
{

    queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    printf("%d ",dequeue(&q));
    printf("%d ",dequeue(&q));
    printf("%d ",dequeue(&q));
    printf("%d ",dequeue(&q));
    //dequeue(&q);
    
    //display(&q);
    return 0;

    
}