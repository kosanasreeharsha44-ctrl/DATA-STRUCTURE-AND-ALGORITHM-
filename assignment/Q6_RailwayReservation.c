#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Passenger{
    int id;
    char name[40];
    struct Passenger*prev,*next;
};
void addPassenger(struct Passenger**head,int id,char name[]){
    struct Passenger*n=malloc(sizeof(struct Passenger)),*last;
    n->id=id;
    strcpy(n->name,name);
    if(!*head){
        n->next=n;
        n->prev=n;
        *head=n;
        return;
    }
    last=(*head)->prev;
    n->next=*head;
    n->prev=last;
    last->next=n;
    (*head)->prev=n;
}
void deletePassenger(struct Passenger**head,int id){
    struct Passenger*p=*head;
    if(!p)return;
    do{
        if(p->id==id){
            if(p->next==p){
                free(p);
                *head=NULL;
                return;
            }
            p->prev->next=p->next;
            p->next->prev=p->prev;
            if(p==*head)
                *head=p->next;
            free(p);
            return;
        }
        p=p->next;
    }while(p!=*head);
}
void forward(struct Passenger*head){
    struct Passenger*p=head;
    printf("Forward Passenger List:\n");
    if(!p)
        return;
    do{
        printf("%d - %s\n",p->id,p->name);
        p=p->next;
    }while(p!=head);
}
void backward(struct Passenger*head){
    struct Passenger*p;
    printf("Backward Passenger List:\n");
    if(!head)
        return;
    p=head->prev;
    do{
        printf("%d - %s\n",p->id,p->name);
        p=p->prev;
    }while(p!=head->prev);
}
int main(){
    struct Passenger*list=NULL;
    printf("RAILWAY RESERVATION PASSENGER SYSTEM\n\n");

    addPassenger(&list,101,"Rahul");
    addPassenger(&list,102,"Priya");
    addPassenger(&list,103,"Arjun");

    forward(list);
    printf("\n");
    backward(list);

    printf("\nNew passenger inserted: 104 - Sneha\n");
    addPassenger(&list,104,"Sneha");
    forward(list);

    printf("\nPassenger 102 cancelled.\n");
    deletePassenger(&list,102);
    forward(list);

    printf("\nCircular doubly linked list supports forward and backward movement.\n");
    return 0;
}
