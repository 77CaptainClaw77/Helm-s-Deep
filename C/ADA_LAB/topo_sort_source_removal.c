//compute from source
#include <stdio.h>
#include <stdlib.h>
void dispgraph(int** G,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d\t",G[i][j]);
    }
    printf("\n");
  }
}
void toposort(int** G,int n){
  int *in_degree=calloc(n,sizeof(int));
  int *removed=calloc(n,sizeof(int));
  int i,found,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(G[j][i])
	in_degree[i]++;
    }
  }
  while(1){
    found=0;
    for(i=0;i<n;i++){
      if(in_degree[i]==0 && !removed[i]){
	printf("%d\t",i+1);
	removed[i]=1;
	for(j=0;j<n;j++){
	  if(G[i][j])
	    in_degree[j]--;
	}
      }
    }
    if(found==0){
      for(i=0;i<n;i++){
	if(!removed[i]){
	  printf("No Topological Ordering Exists!");
	  exit(0);
	}
      }
	  
    }
  }
}
int main(int argc, char *argv[])
{
  int** G;
  int n,i,j,k;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  G=malloc(sizeof(int*) * n);
  for (i = 0; i < n; ++i) 
    G[i]=malloc(sizeof(int)*n);
  printf("Enter the adjacency matrix of the graph:-\n");
  for (i = 0; i < n; ++i) 
    for (j = 0; j < n; ++j) 
      scanf("%d",&G[i][j]);
  printf("The adjacency matrix of the graph is\n");
  dispgraph(G,n);
  printf("The topological ordering is :\n");
  toposort(G,n);
  return 0;
}
