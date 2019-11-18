//implement for forest
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
void BFS(int** G,int n){
  int* visited=calloc(n,sizeof(int));
  int* order=calloc(n,sizeof(int));
  visited[0]=1;
  order[0]=1;
  int i=0,ind=1,cur=0,j=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(G[cur][j] && visited[j]==0){
	order[ind++]=j+1;
	visited[j]=1;
      }
    }
    cur=order[i]-1;
  }
  for(i=0;i<n;i++)
    printf("%d\t",order[i]);
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
  printf("The BFS traversal is :\n");
  BFS(G,n);
  return 0;
}
