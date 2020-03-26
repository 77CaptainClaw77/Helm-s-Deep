#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
  int** queries;
  int** seq_list;
  int* seq_sizes;
  int n,q,i,j,special_index;
  int lastAnswer=0;
  scanf("%d %d",&n,&q);
  queries=(int**)malloc(sizeof(int*)*q);
  for(i=0;i<q;i++){
    queries[i]=(int*)malloc(sizeof(int)*3);
    scanf("%d %d %d",&queries[i][0],&queries[i][1],&queries[i][2]);
  }
  seq_list=(int**)malloc(sizeof(int*)*n);
  seq_sizes=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    seq_list[i]=(int*)malloc(sizeof(int)*q);
    seq_sizes[i]=0;
  }
  for(i=0;i<q;i++){
    int x=queries[i][1],y=queries[i][2];
    special_index=((x^lastAnswer)%n);
    if(queries[i][0]==1){
      seq_list[special_index][seq_sizes[special_index]]=y;
      seq_sizes[special_index]+=1;
    }
    else{
      lastAnswer=seq_list[special_index][y%seq_sizes[special_index]];
      printf("%d\n",lastAnswer);
    }
  }
  return 0;
}
