#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int ele;
}STACK;
int overflow(int top,STACK *s,int n);
int underflow(int top,STACK *s,int n);
int push(int top,STACK *s,int n);
int pop(int top,STACK *s,int n);
void display(int top,STACK *s,int n);
int main(){
    printf("\nEnter the maximum size of the stack you want to assign");
    int n;
    int choice;
    scanf("%d",&n);
    STACK *s=(STACK*)malloc(n*sizeof(STACK));
    int top=-1;
    int i=0;
    do{
        fflush(stdin);
        printf("\nEnter the operation you want to perform.Press anything else to exit.");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY");
        scanf("%d",&choice);
        switch(choice){
        case 1:top=push(top,s,n);
        break;
        case 2:top=pop(top,s,n);
        break;
        case 3:display(top,s,n);
        break;
        default:i=1;
        break;
        }

    }while(i==0);
    return 0;
}
int overflow(int top,STACK *s,int n){
    if(top>=(n-1)){
        printf("\nStack Overflow!");
        return 0;
    }
    else{overflow
        return 1;
    }
}
int underflow(int top,STACK *s,int n){
    if(top==-1){
        printf("\nStack is now empty!");
        return 0;
    }
    else{
        return 1;
    }
}
int push(int top,STACK *s,int n){
    int flag;
    flag=overflow(top,s,n);
    char ch;
    if(flag==0)
        return top;
    else{
        printf("\nEnter the elements to push");
        for(;;){
            fflush(stdin);
            top++;
            scanf("%d",&(s+top)->ele);
            flag=overflow(top,s,n);
            if(!flag)
                return top;
            display(top,s,n);
            fflush(stdin);
            printf("\nDo you want to push more, press y else press any other key");
            scanf("%c",&ch);
            if(!(ch=='y'||ch=='Y'))
                return top;
        }
    }
}
int pop(int top,STACK *s,int n){
     int flag;
    flag=underflow(top,s,n);
    char ch;
    if(flag==0)
        return top;
    else{
        printf("\nPopping elements now");
        for(;;){
            fflush(stdin);
            top--;
            flag=underflow(top,s,n);
            if(!flag)
                return top;
            display(top,s,n);
            printf("\nDo you want to pop more, press y else press any other key");
            scanf("%c",&ch);
            if(!(ch=='y'||ch=='Y'))
                return top;
        }
    }

}
void display(int top,STACK *s,int n){
    int i;
    if(!(underflow(top,s,n)))
            printf("\nEmpty Stack");
    else{
    for(i=top;i>=0;i--)
        printf("\n%d",(s+i)->ele);
    }
}

