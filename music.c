#include<stdio.h>
#include<string.h>
#include "doublell.h"
int main()
{
    dNode*head;
    dNode*tail;
    dNode*temp=head;
    dNode**current=&head;
    char name[50];
    char dummy[20];
    char jump[50];
    char buffer[20];
    int position;
    int n,i=0,j,p=0;
    //start of the player
    printf("enter the number of songs you want to add:");
    fgets(dummy,sizeof(dummy),stdin);
    sscanf(dummy,"%d",&n);
    while(i<n)
    {
        printf("enter the name of the song that you want to add to your playlist\n");
        fgets(name,sizeof(name),stdin);
        //enqueue(&tail,name);
        addend(&head,&tail,name);
        i++;
    }
    traversenext(head);
    //jumping to a track
        printf("enter the number of the track to which you want to jump:");
        //fgets(jump,sizeof(jump),stdin);
        scanf("%d",&j);
        dNode*song=search_by_pos(head,j);
        *current=song;
        printf("your song %s",song->data);
    //going to next track
        if(*current!=NULL)
            *current=(*current)->next;
        printf("your next song is %s\n",(*current)->data);
    //going to previous track
        if(*current!=NULL)
            *current=(*current)->prev;
        printf("your next song is %s\n",(*current)->data);
    //going to first track
        printf("your first song %s",head->data);
    //going to last track
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    printf("%s",temp->data);
    //add a track after existing track
    printf("enter the position after which you want to add:");
    scanf("%d",&position);
    printf("enter the track:");
    fgets(buffer,sizeof(buffer),stdin);
    add_in_between_after(head,position,buffer);
    //add a track before existing track
    printf("enter the position before which you want to add:");
    scanf("%d",&position);
    printf("enter the track:");
    fgets(buffer,sizeof(buffer),stdin);
    add_in_between_before(head,position,buffer);
    //delete a specific track
    printf("enter the which number of track you want to delete:");
    scanf("%d",&position);
    deln(head,position);

    
    
    return 0;
}