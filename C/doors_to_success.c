#include <stdio.h>
#include <stdlib.h>
int get_next_k_sum(int index,int arr[],int n,int k){
  int s=0,c=0;
  int i=(index+1)%n;
  while(c<k){
    s+=arr[i];
    i=(i+1)%n;
    c++;
  }
  return s;
}
int get_prev_k_sum(int index,int arr[],int n,int k){
  int s=0,c=0;
  int i=index-1<0?n-1:index-1;
  while(c<k){
    s+=arr[i];
    i=i-1<0?n-1:i-1;
    c++;
  }
  return s;
}
int main(){
  int n,k,i;
  scanf("%d %d",&n,&k);
  int arr[n];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int sum[n];
  for(i=0;i<n;i++){
    int s=get_next_k_sum(i,arr,n,k);
    if(s<0)
      sum[i]=get_prev_k_sum(i,arr,n,k);
    else
      sum[i]=get_next_k_sum(i,arr,n,k);
  }
  for(i=0;i<n;i++)
    printf("%d ",sum[i]);
}
