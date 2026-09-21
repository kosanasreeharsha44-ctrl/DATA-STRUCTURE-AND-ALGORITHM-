#include<stdio.h>
#define SIZE 5
int queue[SIZE],front=-1,rear=-1;
void printQueue(){
    int i;
    if(front==-1){printf("Printer Queue: Empty\n");return;}
    printf("Printer Queue: ");
    i=front;
    while(1){
        printf("Request%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%SIZE;
    }
    printf("\n");
}
void addRequest(int x){
    if((rear+1)%SIZE==front){
        printf("Printer Queue Full - Request%d cannot be added.\n",x);
        return;
    }
    if(front==-1) front=0;
    rear=(rear+1)%SIZE;
    queue[rear]=x;
    printf("Print Request%d added.\n",x);
}
void completeRequest(){
    if(front==-1){printf("Printer Queue Empty.\n");return;}
    printf("Print Request%d completed.\n",queue[front]);
    if(front==rear) front=rear=-1;
    else front=(front+1)%SIZE;
}
int main(){
    printf("COLLEGE PRINTER REQUEST SYSTEM\n\n");
    addRequest(101);
    addRequest(102);
    addRequest(103);
    addRequest(104);
    addRequest(105);
    printQueue();

    completeRequest();
    completeRequest();
    printQueue();

    addRequest(106);
    addRequest(107);
    printQueue();

    printf("\nCircular queue reuses the positions freed at the beginning.\n");
    return 0;
}