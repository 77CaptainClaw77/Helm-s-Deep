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
void dfs(int** G,int n,int* visited,int v){
  visited[v]=1;
  printf("%d\t",v+1);
  int j;
  for(j=0;j<n;j++){
    if(G[v][j] && !visited[j])
      dfs(G,n,visited,j);
  }
}
void DFS(int** G,int n){
  int* visited=calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++)
    if(!visited[i])
      dfs(G,n,visited,i);
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
  printf("The DFS traversal is :\n");
  DFS(G,n);
  return 0;
}
