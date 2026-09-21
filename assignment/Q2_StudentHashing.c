#include<stdio.h>
#define SIZE 10
int main(){
    int keys[]={23,43,13,27,37,53},n=6,i,j,h;
    int chain[SIZE][SIZE],count[SIZE]={0};
    int table[SIZE],used[SIZE]={0};

    for(i=0;i<SIZE;i++) table[i]=-1;

    printf("STUDENT RECORD HASH TABLE\n");
    printf("Hash function: h(k) = k %% 10\n");
    printf("Student Roll Numbers: 23 43 13 27 37 53\n\n");

    for(i=0;i<n;i++){
        h=keys[i]%SIZE;
        if(count[h]>0) printf("Collision: Roll No. %d at index %d\n",keys[i],h);
        chain[h][count[h]++]=keys[i];
    }

    printf("\nOPEN HASHING - Student Records\n");
    for(i=0;i<SIZE;i++){
        printf("Index %d: ",i);
        for(j=0;j<count[i];j++) printf("%d ",chain[i][j]);
        printf("\n");
    }

    for(i=0;i<n;i++){
        h=keys[i]%SIZE;
        j=h;
        while(used[j]) j=(j+1)%SIZE;
        table[j]=keys[i];
        used[j]=1;
    }

    printf("\nCLOSED HASHING - Linear Probing\n");
    for(i=0;i<SIZE;i++)
        if(table[i]!=-1) printf("Index %d: Roll No. %d\n",i,table[i]);
        else printf("Index %d: Empty\n",i);

    printf("\nOpen hashing is more flexible when student records increase.\n");
    return 0;
}