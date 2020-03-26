#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
  int T,n,k,i,j;
  scanf("%d",&T);
  for(i=0;i<T;i++){
    scanf("%d %d",&n,&k);
    char* coins=(char*)malloc(sizeof(char)*n);
    scanf("%*c");
    for(j=0;j<n;j++)
      scanf("%c%*c",&coins[j]);
    int flip=0;
    for(j=n-1;j>n-k-1;j--){
      if(flip==1)
	coins[j]=(coins[j]=='H')?'T':'H';
      if(coins[j]=='H')
	flip=(flip==1)?0:1;
    }
    int hc=0;
    for(j=0;j<n-k;j++)
      if((flip==0 && coins[j]=='H') || (flip==1 && coins[j]=='T'))
	hc++;
    printf("%d\n",hc);
  }
  return 0;
}
