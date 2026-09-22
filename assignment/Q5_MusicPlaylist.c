#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Song{
    char name[50];
    struct Song*next;
};
void addSong(struct Song**head,char name[],int pos){
    struct Song*n=malloc(sizeof(struct Song)),*p=*head;
    strcpy(n->name,name);
    n->next=NULL;
    if(pos==1||!*head){
        n->next=*head;
        *head=n;
        return;
    }
    while(p->next&&pos>2){p=p->next;pos--;}
    n->next=p->next;
    p->next=n;
}
void deleteSong(struct Song**head,int pos){
    struct Song*p=*head,*t;
    if(!p)return;
    if(pos==1){
        *head=p->next;
        free(p);
        return;
    }
    while(p->next&&pos>2){p=p->next;pos--;}
    if(p->next){
        t=p->next;
        p->next=t->next;
        free(t);
    }
}
void display(struct Song*p){
    int i=1;
    printf("Current Music Playlist:\n");
    while(p){
        printf("%d. %s\n",i++,p->name);
        p=p->next;
    }
}
int main(){
    struct Song*playlist=NULL;
    printf("MUSIC PLAYLIST MANAGEMENT\n\n");

    addSong(&playlist,"Kesariya",1);
    addSong(&playlist,"Perfect",2);
    addSong(&playlist,"Believer",3);
    display(playlist);

    printf("\nAdding a song at position 2...\n");
    addSong(&playlist,"Shape of You",2);
    display(playlist);

    printf("\nDeleting a song from position 3...\n");
    deleteSong(&playlist,3);
    display(playlist);

    printf("\nSingly linked list avoids shifting songs during insertion/deletion.\n");
    return 0;
}