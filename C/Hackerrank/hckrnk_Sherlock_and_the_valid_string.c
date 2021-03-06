
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 1000000
void print_arr(int arr[]){
  int i;
  for(i=0;i<26;i++)
    printf("%d ",arr[i]);
  printf("\n");
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main(int argc, char *argv[])
{
  char s[MAX_LEN+1];
  scanf("%s",s);
  int arr[26]={0};
  int i,j;
  for(i=0;i<strlen(s);i++)
    arr[s[i]-'a']++;
  qsort(arr,26,sizeof(int),compare);
  //print_arr(arr);
  for(i=0;arr[i]==0;i++);
  int inv=0,min_val=arr[i],max_val=arr[25];
  if(min_val==max_val)
    inv=0;
  else{
    if((max_val-min_val==1 && max_val>arr[24]) || (min_val==1 && arr[i+1]==max_val))
      inv=0;
    else
      inv=1;
  }
  if(inv)
    printf("NO");
  else
    printf("YES");
  return 0;
}
