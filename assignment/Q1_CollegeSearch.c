#include<stdio.h>
#define MAX 10000
int main(){
    int roll[MAX],n,key,i,low,high,mid,seq=-1,bin=-1;
    printf("COLLEGE EXAMINATION REGISTRATION\n");
    printf("Enter number of student records: ");
    scanf("%d",&n);
    printf("Enter roll numbers in sorted order:\n");
    for(i=0;i<n;i++) scanf("%d",&roll[i]);
    printf("Enter roll number to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++){
        if(roll[i]==key){seq=i;break;}
    }

    low=0;high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(roll[mid]==key){bin=mid;break;}
        if(roll[mid]<key) low=mid+1;
        else high=mid-1;
    }

    printf("\nRegistration Search Result\n");
    if(seq!=-1) printf("Student Roll No. %d found by Sequential Search.\n",key);
    else printf("Student Roll No. %d not found by Sequential Search.\n",key);
    if(bin!=-1) printf("Student Roll No. %d found by Binary Search.\n",key);
    else printf("Student Roll No. %d not found by Binary Search.\n",key);
    printf("Binary Search is suitable for repeatedly searching sorted records.\n");
    return 0;
}