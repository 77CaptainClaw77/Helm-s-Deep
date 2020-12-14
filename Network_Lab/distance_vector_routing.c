#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER_OF_NODES 100
typedef struct{
  int distances[MAX_NUMBER_OF_NODES];
}node;
int main(int argc, char *argv[])
{
  printf("Enter the number of nodes: ");
  int n,i,j,k;
  scanf("%d", &n);
  printf("Enter the cost matrix:\n");
  int cost[n][n];
  node* nodeset=(node*)malloc(sizeof(node)*n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&cost[i][j]);
      nodeset[i].distances[j]=cost[i][j];
      if(i==j)
	nodeset[i].distances[j]=0;
    }
  }
  int updation_count;
  do{
    updation_count=0;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(k=0;k<n;k++){
	  if(nodeset[i].distances[j]>nodeset[i].distances[k]+nodeset[k].distances[j]){
	    updation_count++;
	    nodeset[i].distances[j]=nodeset[i].distances[k]+nodeset[k].distances[j];
	  }
	}
      }
    }
  }while(updation_count>0);
  for(i=0;i<n;i++){
    printf("%c's table\n",'a'+i);
    for(j=0;j<n;j++){
      printf("%c->%c: %d\n",'a'+i,'a'+j,nodeset[i].distances[j]);
    }
  }
  return 0;
}
