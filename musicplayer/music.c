#include<stdio.h>
#include "doublell.h"
#include<string.h>
int main()
{
    dNode*head=NULL;
    dNode*tail=NULL;
    dNode * first=head;
    dNode * savepos;
    char  name[50],ch,buff;
    char aft[20],dummy[20],bef[20];
    int i=0,n,pos1,pos,pos2,pos3;
    int * ptr;
    FILE * fp;
    fp=fopen("player.txt","r");
    while(( fgets(name,50,fp) ))
    {
        addend(&head,&tail,name);
    }

    //start the player func
    void start(dNode*sptr)
    {
        if(sptr==NULL)
            return;
        printf("%s",sptr->data);
    }
    //jump to a track func
    dNode* jump(int n)
    {
        dNode*track;
        track=search_by_pos(head,n);
        if(track==NULL)
            printf("\noops!no more songs\n");
        printf("\nyour track is %s",track->data);
        return track;
    }
    //play next track
    void next(dNode * current)
    {
        if(current->next==NULL)
            printf("oops!no more songs\n");
        current=current->next;
        printf("\nnext song %s",current->data);
    }
    //play previous track
    void previous(dNode * curr)
    {
        if(curr==NULL)
            printf("oops!no more songs\n");
        curr=curr->prev;
        printf("\nprevious song %s",curr->data);
    }
    //play first track
    void play_first(dNode * ptr)
    {
        do
        {
            ptr=ptr->prev;
        }while(ptr->prev!=NULL);
        printf("\nyour first song %s ",ptr->data);
    }
    //play last track
    void play_last(dNode * ptrhead)
    {
        do{
            ptrhead=ptrhead->next;

        }while(ptrhead->next!=NULL);
        printf("\nyour last song %s\n",ptrhead->data);
    }

    /* the menu */
    
    
    do{

        printf("Press 'S' to start the player:\n");
        printf("Press 'J' to jump to a specific track:\n");
        printf("Press 'N' to go to next track:\n");
        printf("Press 'M' to go to the track next to current track\n");
        printf("Press 'P' to go to previous track\n");
        printf("Press 'F' to go to first track\n");
        printf("Press 'L' to go to last track\n");
        printf("Press 'A' to add a track after an existing track\n");
        printf("Press 'B' to add a track before an existing track\n");
        printf("Press 'R' to to remove a specific track\n");
        printf("Press 'O' to sort the tracks\n");
        printf("Press 'T' to show:\n");
        printf("\npress n to stop:");
        printf("\npress y to continue");
        printf("\nenter your choice:");
        scanf("%c%c",&ch,&buff);
        switch(ch)
        {
            case 'S' : 
                start(head);
                break;
            case 'J' :
                printf("enter the position of the track to jump:");
                scanf("%d",&pos1);
                savepos=jump(pos1);
                jump(pos1);
                break;

            case 'N': 
                next(head);
                break;

            case 'P': 
                previous(savepos);
                break;

            case 'F': play_first(tail);
                      break;


            case 'L': play_last(head);
                      break;
            case 'A':
                printf("enter the position of the track after which you want to add\n");
                fgets(dummy,sizeof(dummy),stdin);
                sscanf(dummy,"%d",&pos2);
                printf("enter the track name\n");
                fgets(aft,sizeof(aft),stdin);
                add_in_between_after(head,pos2,aft);
                break;
            case 'B':
                printf("enter the position of the track before which you want to add\n");
                fgets(dummy,sizeof(dummy),stdin);
                sscanf(dummy,"%d",&pos3);
                printf("enter the track name\n");
                fgets(bef,sizeof(bef),stdin);
                add_in_between_before(head,pos2,bef);
                break;
            case 'R':
                printf("enter the position of the track  which you want to delete\n");
                fgets(dummy,sizeof(dummy),stdin);
                sscanf(dummy,"%d",&pos);
                deln(head,pos);
                break;
            case 'O':
                sort(&head,&tail);
                break;
            case 'T':
                    traversenext(head);
                    break;
            case 'n':
                return 0;
            case 'y':
                continue;
                break;
            default:
                break;


        }

    }while(ch!='n');






    
    /*traversenext(head);
    start(head);
    dNode * current=jump(2);
    next(current);
    previous(current);
    play_first(tail);
    play_last(head);
    printf("\n");
    //add a track after a given track
    add_in_between_after(head,2,"vande mataram\n");
    traversenext(head);
    printf("\n");
    //add a track before a given track
    add_in_between_before(head,2,"ae watan\n");
    traversenext(head);
    printf("\n");
    //remove a specific track
    deln(head,2);
    traversenext(head);
    printf("\n");*/


    fclose(fp);


    return 0;
}