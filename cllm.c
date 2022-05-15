#include "cll.h"

int main()
{
    CNode*head=NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    make_circular(&head);
    traverse(head);
}
