#include "doublell.h"

int main()
{
    
    
    dNode*head=NULL;
    dNode*tail=NULL;
    
    addend(&head,&tail,2);
    addend(&head,&tail,4);
    addend(&head,&tail,6);
    addend(&head,&tail,8);
    addbegin(&head,0);
    dNode * position=search_by_pos(head,2);
    add_in_between_after(head,2,5);
    add_in_between_before(head,2,3);
    delete_in_between_before(head,3);
    traversenext(head);
    //traverseprev(tail);
    
}