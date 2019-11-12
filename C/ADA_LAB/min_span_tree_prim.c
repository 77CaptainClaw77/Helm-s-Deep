#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void Prim(int** G,int n){
  int visit_count=0;
 
}
int main(int argc, char *argv[]){
  int **G,n,i,j;
  printf("Enter the number of vertices");
  scanf("%d", &n);
  G=malloc(sizeof(int*)*n);
  for (i = 0; i < n; ++i) {
    G[i]=malloc(sizeof(int)*n);
  }
  printf("Enter the adjacency matrix (Enter \'-1\' if there is no edge):-\n");
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      scanf("%d",&G[i][j]);
    }
  }
  Prim(G,n);
  return 0;
}
