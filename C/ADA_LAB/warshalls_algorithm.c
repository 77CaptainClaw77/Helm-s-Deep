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
int main(int argc, char *argv[])
{
  int** G;
  int** T_closure;
  int n,i,j,k;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  G=malloc(sizeof(int*) * n);
  T_closure=malloc(sizeof(int*) * n);
  for (i = 0; i < n; ++i) {
    G[i]=malloc(sizeof(int)*n);
    T_closure[i]=malloc(sizeof(int) * n);
  }
  printf("Enter the adjacency matrix of the graph:-\n");
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      scanf("%d",&G[i][j]);
      T_closure[i][j]=G[i][j];
    }
  }
  for (k = 0; k < n; ++k) {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
	T_closure[i][j]=T_closure[i][j] || (T_closure[i][k] && T_closure[k][j]);
      }
    }
  }
  printf("The adjacency matrix of the graph is\n");
  dispgraph(G,n);
  printf("The transitive closure of the graph is\n");
  dispgraph(T_closure,n);
  return 0;
}
