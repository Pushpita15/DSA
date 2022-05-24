#include "stackll.h"

int main()
{
    node * head;
    init(&head);
    push(&head,2);
    push(&head,4);
    push(&head,6);
    push(&head,8);
    //traverse(head);
    printf("%d ",pop(&head));
    printf("%d ",pop(&head));
    printf("%d ",pop(&head));
    

    
}