#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
if(n==1||n==0)
    return 1;
else
    return n*factorial(n-1);
}
int main(){
    int n;
    printf("\nEnter a number");
    scanf("%d",&n);
    printf("%d",factorial(n));
}

