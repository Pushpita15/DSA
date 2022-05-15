#include "doublell.h"

int main()
{
    dNode*head=NULL;
    dNode*tail=NULL;
    addend(&head,&tail,1);
    addend(&head,&tail,2);
    addend(&head,&tail,3);
    addend(&head,&tail,4);
    addbegin(&head,0);
    traversenext(head);
    traverseprev(tail);
}