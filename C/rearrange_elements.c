#include <stdio.h>
#include <stdlib.h>
int* ReArrangeArrayElements(int* arr,int length){
  int even_index=0,odd_index=1;
  while(even_index<length && odd_index<length){
    while(even_index<length && arr[even_index]%2==0)
      even_index+=2;
    while(odd_index<length && arr[odd_index]%2!=0)
      odd_index+=2;
    if(even_index<length && odd_index<length){
      int temp=arr[even_index];
      arr[even_index]=arr[odd_index];
      arr[odd_index]=temp;
    }
  }
  return arr;
}
int main(){
  int n,i;
  scanf("%d",&n);
  int* arr=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  arr=ReArrangeArrayElements(arr,n);
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
