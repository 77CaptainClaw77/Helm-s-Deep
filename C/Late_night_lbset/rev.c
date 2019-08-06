#include <stdio.h>
#include <stdlib.h>
rec(char c){
    c=
    printf("\b\b%c",c);
    printf("Enter 1 to stop");
    int i;
    scanf("%d",&i);
    if(i==1)
        return;
    rec(c);
}

main(){
    printf("Enter the string");
    char c='a';
    rec(c);
}
