#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b)
{
    return (*(int*)a<*(int*)b);
}
int main(){
   int a[]={23,41,12,32,42,1};
    qsort(a,6,sizeof(int),compare);
    int i;
    for(i=0;i<6;i++)
        printf("%d\t",a[i]);
    return 0;
}
