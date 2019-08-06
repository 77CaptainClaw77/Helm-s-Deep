#include<stdio.h>
#include <stdlib.h>
int fib(int n){
    if(n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
int summer(int a,int sum,int i){
    if(i<a)
        return summer(a,sum+fib(i),i+1);
    return sum+fib(a);
}
int main()
{
    int n;
    printf("Enter the number of terms");
    scanf("%d",&n);
    printf("%d",summer(n-1,0,1));
    return 0;
}
