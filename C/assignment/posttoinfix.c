#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
float stack[100];
int top;
int main()
{
    char postfix[100];
    char ch;
    float op1,op2,res;
    int i,len;
    printf("Enter a valid postfix expression");
    scanf("%s",postfix);
    top=-1;
    i=0;
    len=strlen(postfix);
    while(i<len)
    {
        ch=postfix[i];
        if(isdigit(ch)){
            stack[++top]=ch-48;
        }
        else {
            op2=stack[top--];
            op1=stack[top--];
            switch(ch){
                case '+':res=op1+op2;
                break;
                case '-':res=op1-op2;
                break;
                case '*':res=op1*op2;
                break;
                case '/':res=op2==0 ? 0:(op1/op2);
                break;
                default: printf("Invalid Expression");
                exit(2);
            }
                        stack[++top]=res;


            }i++;
    }
    res=stack[top--];
    if(top==-1)
        printf("The value of the expression is %f",res);
    else
        printf("Invalid Expression");
    return 0;
    }


