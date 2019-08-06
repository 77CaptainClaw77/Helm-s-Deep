#include <stdio.h>
#include <stdlib.h>
int fibber(int n){
    if(n==1 || n==2){
        return 1;
    }
    return fibber(n-1)+fibber(n-2);
}
int main()
{
    int n;
    printf("enter the number of terms");
    scanf("%d",&n);
    printf("%d",fibber(n-1));
    return 0;
}
