#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX_SIZE 100
struct stack{
    int arr[STACK_MAX_SIZE];
    int top;
};
int overflow(struct stack* st){return st->top==STACK_MAX_SIZE-1?1:0;}
int underflow(struct stack* st){return st->top==-1?1:0;}
void push(struct stack* st,int ele){
    if(overflow(st))
        return;
    st->arr[++st->top]=ele;
}
void pop(struct stack* st){
    if(underflow(st))
        return;
    st->top--;
}
int main(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    char expression[STACK_MAX_SIZE];
    scanf("%s",expression);
    for(int i=0;i<strlen(expression);i++){
        if(expression[i]=='[' || expression[i]=='{' || expression[i]=='(')
            push(st,expression[i]);
        else if(expression[i]==']' || expression[i]=='}' || expression[i]==')'){
            if((expression[i]==']' && st->arr[st->top]=='[') || (expression[i]=='}' && st->arr[st->top]=='{') || (expression[i]==')' && st->arr[st->top]=='('))
                pop(st);
            else{
                printf("INVALID EXPRESSION!!!");
                exit(0);
            }
        }
    }
    if(!underflow(st))
        printf("INVALID EXPRESSION!!!");
    else
        printf("VALID");
    return 0;
}
