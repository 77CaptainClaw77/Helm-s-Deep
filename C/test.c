#include <stdio.h>
enum {ADD,SUB,DIV}op;
int main(){
    op=SUB;
    printf("%d",op);
    return 0;
}