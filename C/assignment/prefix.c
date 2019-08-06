#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float stack[100];
int main()
{
    char exp[100];
    //char prexp[100];
    char ch;
    int i,j;
    i=0;
    j=-1;
    float res;
    int temp;
    printf("enter a valid prefix expression");
    scanf("%s",exp);
    int len=strlen(exp);
    strrev(exp);
    while(i<len){
        ch=exp[i++];
        if(isdigit(ch))
            stack[++j]=ch-48;
        else if(isalpha(ch)){
            printf("\nEnter the value of %c",ch);
            scanf("%d",&temp);
            stack[++j]=temp;
        }
        else{
            int op1=stack[j--];
            int op2=stack[j--];
            switch(ch){
            case '+': res=op1+op2;
            break;
            case '-': res=op1-op2;
            break;
            case '*':
                res=op1*op2;
            break;
            case '/':if(op2==0){
                printf("Invalid expression");
                exit(0);
                }
                res=op1/op2;
            break;
            default: printf("Invalid operator encountered");
            exit(1);
            }
            stack[++j]=res;
        }

    }
    if(j!=0)
        printf("Invalid expression");
    else
        printf("%s=%f",strrev(exp),res);
    return 0;
}
