#include<stdio.h>
#include<ctype.h>
int priority(char c){
    if(c=='+'||c=='-') 
        return 1;
    if(c=='*'||c=='/') 
        return 2;
    return 0;
}
int main(){
    char infix[]="A+B*(C-D)/E",stack[30];
    int top=-1,i;
    printf("EXPRESSION PROCESSING USING STACK\n");
    printf("Infix Expression : %s\n",infix);
    printf("\nOperator processing:\n");
    printf("1. Parenthesized expression (C-D)\n");
    printf("2. Multiplication B*(C-D)\n");
    printf("3. Division B*(C-D)/E\n");
    printf("4. Addition A+B*(C-D)/E\n");

    printf("\nPostfix Expression: ");
    for(i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isalnum(c)) 
            printf("%c ",c);
        else if(c=='(') 
            stack[++top]=c;
        else if(c==')'){
            while(top>=0&&stack[top]!='(') printf("%c ",stack[top--]);
            top--;
        }else{
            while(top>=0&&priority(stack[top])>=priority(c))
                printf("%c ",stack[top--]);
            stack[++top]=c;
        }
    }
    while(top>=0) printf("%c ",stack[top--]);
    printf("\n");
    printf("Stack handles operator precedence and parentheses correctly.\n");
    return 0;
}
