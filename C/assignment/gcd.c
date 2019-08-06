#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b,int i,int g){
    if(i>a || i>b)
        return g;
    if(a%i==0 && b%i==0)
        return gcd(a,b,i+1,i);
    return gcd(a,b,i+1,g);
}
int main(){
    int n1,n2;
    printf("Enter the two numbers");
    scanf("%d %d",&n1,&n2);
    printf("The gcd of %d and %d is %d",n1,n2,gcd(n1,n2,1,1));
}
