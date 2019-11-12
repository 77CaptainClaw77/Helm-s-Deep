#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int min(int a,int b){
  return a<b?a:b;
}
void dispgraph(int** G,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d\t",(G[i][j]==INF?-1:G[i][j]));
    }
    printf("\n");
  }
}
int main(int argc, char *argv[]){
  int** G;
  int** dist;
  int n,i,j,k;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  G=malloc(sizeof(int*)*n);
  dist=malloc(sizeof(int*)*n);
  for (i = 0; i < n; i++){ 
    G[i]=malloc(sizeof(int)*n);
    dist[i]=malloc(sizeof(int)*n);
  }
  printf("Enter the weight matrix of the graph(Enter -1 for infinity):-\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&G[i][j]);
      G[i][j]=G[i][j]==-1?INF:G[i][j];
      dist[i][j]=G[i][j];
    }
  }
  for(k=0;k<n;k++)
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)     
	dist[i][j]=min(dist[i][j],dist[k][j]+dist[i][k]);
  printf("\nThe weight matrix of the graph is :-\n");
  dispgraph(G,n);
  printf("\nThe shortest distances matrix of the graph is :-\n");
  dispgraph(dist,n);
  return 0;
}
