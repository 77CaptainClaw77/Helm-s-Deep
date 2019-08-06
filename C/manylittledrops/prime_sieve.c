#include <stdio.h>
#include <stdlib.h>
#define def 1
int main()
{
    int arr[100];
    int ll,ul,i,j;
    printf("Enter the lower limit");
    scanf("%d",&ll);
    printf("Enter the upper limit");
    scanf("%d",&ul);
    for(i=ll;i<=ul;i++)
        arr[i-ll]=i;
    for(i=2;i<=ul;i++)
    {
        for(j=ll;j<=ul;j++)
        {
            if(arr[j-ll]==0)
               continue;
            if(arr[j-ll]<=i)
                break;
            if(arr[j-ll]%i==0)
                arr[j-ll]=0;
        }
    }
    for(i=ll;i<=ul;i++){
        if(arr[i-ll]!=0)
            printf("%d\t",arr[i-ll]);
    }
	return 0;
}
