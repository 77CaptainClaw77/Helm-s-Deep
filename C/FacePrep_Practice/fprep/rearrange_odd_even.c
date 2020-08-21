#include <stdio.h>
#include <stdlib.h>
void swap(int* l,int* r){
    int temp=*l;
    *l=*r;
    *r=temp;
}
int main(){
    int n,i;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    int j=-1;
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            j++;
            swap(arr+i,arr+j);
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
