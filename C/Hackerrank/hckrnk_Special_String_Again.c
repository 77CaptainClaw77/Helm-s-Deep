#include <stdio.h>
#include <string.h>
int min(int a,int b){
  return a<b?a:b;
}
int main(){
  char s[1000001];
  int len,i,j,k;
  int count=0;
  scanf("%d", &len);
  scanf("%c",&s[0]);
  for(i=0;i<len;i++)
    scanf("%c",&s[i]);
  char occurrence[1000001];
  int rep[1000001]={0};
  int sz=1;
  occurrence[0]=s[0];
  rep[0]++;
  for(i=1;i<len;i++){
    if(s[i]==occurrence[sz-1])
      rep[sz-1]++;
    else{
      occurrence[sz]=s[i];
      rep[sz]++;
      sz++;
    }
  }
  for(i=0;i<sz;i++)
    count+=(rep[i]*(rep[i]+1))/2; //Type 1
  for(i=0;i<sz-2;i++){
    if(occurrence[i]==occurrence[i+2] && rep[i+1]==1)
      count+=min(rep[i],rep[i+2]);
  }
  printf("%d",count);
}
