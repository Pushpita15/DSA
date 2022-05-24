#include "qcll.h"

int main()
{
    node * rear;

    init(&rear);
    enqueue(&rear,2);
    enqueue(&rear,4);
    enqueue(&rear,6);
    enqueue(&rear,8);

    printf("%d ",dequeue(&rear));
    printf("%d ",dequeue(&rear));
    printf("%d ",dequeue(&rear));
    printf("%d ",dequeue(&rear));
    printf("%d ",dequeue(&rear));

}