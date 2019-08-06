#include <stdio.h>
#include <stdlib.h>
#define def 1
#include <math.h>
int isprime(int n){
    int k=sqrt(n);
    int i,truth;
    truth=1;
    for(i=2;i<=k;i++){
        if(n%i==0)
            truth=0;
    }
    return truth;
}
int main()
{
    int n;
    printf("Enter a positive non zero number");
    scanf("%d",&n);
    if(isprime(n))
        printf("Prime");
    else
        printf("Composite");
	return 0;
}

