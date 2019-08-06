#include <stdio.h>
#include <stdlib.h>
#define N 1
int lcm(int a,int b,int mul){
    if(mul%a==0 && mul%b==0)
        return mul;
    return lcm(a,b,mul+1);
}
void  main(){
	int a,b;
	printf("Enter 2 numbers");
	scanf("%d %d",&a,&b);
	int max=a>b?a:b;
	printf("The lcm of %d and %d is %d",a,b,lcm(a,b,max));
}
