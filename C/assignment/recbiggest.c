#include <stdio.h>
#include <stdlib.h>
#define def 1
int largest(int max,int a[],int n){
    if(max>a[n])
        max=a[n];
    if(n==0)
        return max;
}
int main()
{
    printf("Enter the number of values");
    int n,i;
    scanf("%d",&n);
    int a[n];
    printf("Enter the values");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int max=largest(a[0],a,n-1);
    printf("\nThe largest number is %d",max);
	return 0;
}
