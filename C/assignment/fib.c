#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n){
if(n==1||n==2)
    return 1;
else
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n,i;
    printf("\nEnter a number");
    scanf("%d",&n);
    printf("0\t");
    for(i=1;i<n;i++)
        printf("%d\t",fibonacci(i));
}

