#include "ll.h"

int main()
{
    Node* head = NULL;

    append(&head, 2);
    append(&head, 3);
    append(&head, 5);
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);
    traverse(head);
    addbefore(&head,1,1);
    traverse(head);
    addafter(&head,4,4);
    traverse(head);
    addatn(&head,4,5);
    traverse(head);

    return 0;
}