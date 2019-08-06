#include <stdio.h>
#include <stdlib.h>
int bin(int n){
    if(n<=1)
        return 1;
    else
        return ((n%2)+(10*bin(n/2)));
}
int main(){
    int n;
    printf("Enter a number to be converted to binary format");
    scanf("%d",&n);
    int b=bin(n);
    printf("%d",b);
}
