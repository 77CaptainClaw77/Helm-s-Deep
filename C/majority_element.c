#include <stdio.h>
#include <stdlib.h>
int MajorityElement(int arr[],int n){
  if(n==0) return -2;
  int majority=arr[0];
  int cnt=1;
  int i;
  for(i=1;i<n;i++){
    if(arr[i]==majority)
      cnt++;
    else{
      cnt--;
      if(cnt==0){
	majority=arr[i];
	cnt=1;
      }
    }
  }
  cnt=0;
  for(i=0;i<n;i++)
    if(arr[i]==majority)
      cnt++;
  if(cnt>(n/2))
    return majority;
  return -1;
}
int main(){
  int n,i;
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("%d",MajorityElement(arr,n));
  return 0;
}
