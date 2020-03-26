#include <stdio.h>
int main(){
  int n,i,j,c,val;
  scanf("%d",&n);
  c=0;
  val=n;
  for(i=0;i<n*2-1;i++){
    for(j=0;j<c;j++)
      printf("%d ",val--);
    for(j=0;j<((n-c)*2)-1;j++)
      printf("%d ",val);
    for(j=0;j<c;j++)
      printf("%d ",++val);
    printf("\n");
    c=i<n-1?c+1:c-1;
  }
  return 0;
}
