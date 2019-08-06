#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct STACK{
    char ele[100];
    int top;
}stack;

void push(char sym){
  stack.ele[++stack.top]=sym;
}
char pop(){
    return stack.ele[stack.top--];
}
int OperPre(char sym){
    //printf("\n%c",sym);
    switch(sym){
    case '@':return 0;
    break;
    case '(':return 1;
    break;
    case '+':
    case '-':return 2;
    break;
    case '*':
    case '/':return 3;
    break;
    case '^':return 4;
    break;
    default:printf("Invalid expression");
    exit(0);
    }
}
int main()
{
    stack.top=-1;
    push('@');
    char infix[100],postfix[100];
    printf("Enter a valid infix expression");
    scanf("%s",infix);
    int i=0;
    char sym,ch;
    int j=0;
    while((sym=infix[i++])!='\0'){
        if(sym=='(')
            push(sym);
        else if(sym==')'){
                ch=pop();
            while(ch!='(')
            {
                postfix[j++]=ch;
                ch=pop();
            }
        }
        else if(isalnum(sym))
        {
            postfix[j++]=sym;
        }
        else{
            while(OperPre(sym)<=OperPre(stack.ele[stack.top])){
                postfix[j++]=pop();
            }
            push(sym);

        }
    }
    while((sym=pop())!='@')
        postfix[j++]=sym;
    postfix[j]='\0';
    printf("%s",postfix);
    return 0;
}
