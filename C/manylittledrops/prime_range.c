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
    int ll,ul,i;
    printf("Enter the lower limit");
    scanf("%d",&ll);
    printf("Enter the upper limit");
    scanf("%d",&ul);
    int pcount=0;
    for(i=ll;i<=ul;i++)
    {
        if(isprime(i)){
            printf("%d\t",i);
            pcount=1;
        }
    }
    if(!pcount)
        printf("No prime numbers in the given range");
	return 0;
}
