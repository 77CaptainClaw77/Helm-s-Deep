#include <stdlib.h>
#include <stdio.h>
typedef long long ll;
#define MOD_VAL 1000000007
int main(int argc, char *argv[])
{
  int n,k,i,j;
  int superbrushes[1001]={0};
  superbrushes[0]=1;
  scanf("%d %d",&n,&k);
  int brushes[k];
  for(i=0;i<k;i++){
    scanf("%d",&brushes[i]);
    for(j=brushes[i];j<=n;j++)
      superbrushes[j]=superbrushes[j]|superbrushes[j-brushes[i]];
  }
  ll dp_painted[1001]={0},dp_unpainted[1001]={0};
  dp_unpainted[0]=1;
  for(i=1;i<=n;i++){
    dp_unpainted[i]=(dp_painted[i-1]+dp_unpainted[i-1])%MOD_VAL;
    for(j=1;j<=i;j++){
      if(!superbrushes[j]) continue;
      dp_painted[i]=(dp_painted[i]+dp_unpainted[i-j])%MOD_VAL;
    }
  }
  printf("%ld",(dp_painted[n]+dp_unpainted[n])%MOD_VAL);
  return 0;
}
