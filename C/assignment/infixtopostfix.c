#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct STACK{
    char st[100];
    int top;
}stack;
char infix[30];
char postfix[30];
void push(char symbol){
    stack.st[++stack.top]=symbol;
}
char pop(){
return (stack.st[stack.top--]);
}
int OperatorPre(char sym)
{

    switch(sym){
        case '@': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':return 3;
        case '^':return 4;
        default:printf("INVALID EXPRESSION");
        exit(1);
    }
}
void infixtopostfix(){
    int top;
    int len,i,j;
    i=0;
    j=0;
    char sym,ch;
    len=strlen(infix);
    i=0;
    while(i<len)
    {
        sym=infix[i++];
        if(sym=='(')
            push(sym);
        else if(sym==')')
        {
            ch=pop();
            while(ch!='('){
                    postfix[j++]=ch;
                    ch=pop();
                  }
        }
            else if(isdigit(sym) || isalpha(sym))
                postfix[j++]=sym;
            else{
                while(OperatorPre(stack.st[stack.top])>OperatorPre(sym))
                    postfix[j++]=pop();
                push(sym);
            }


    }
    while((ch=pop())!='@')
        postfix[j++]=ch;
    postfix[j]='\0';
}
int main(){
    printf("Enter infix expression");
    scanf("%s",infix);
    stack.top=-1;
    push('@');
    infixtopostfix();
    printf("%s=%s\n",infix,postfix);
    return 0;
}
