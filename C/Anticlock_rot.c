#include <stdio.h>
int main(){
  int N,M,i,j,k;
  scanf("%d %d",&M,&N);
  int matrix[M][M];
  for(i=0;i<M;i++)
    for(j=0;j<M;j++)
      scanf("%d",&matrix[i][j]);
  int rotated_matrix[M][M];
  for(k=0;k<N%4;k++){
    for(i=0;i<M;i++)
      for(j=0;j<M;j++)
	rotated_matrix[M-1-j][i]=matrix[i][j];
    for(i=0;i<M;i++)
      for(j=0;j<M;j++)
	matrix[i][j]=rotated_matrix[i][j];
  }
  for(i=0;i<M;i++)
    for(j=0;j<M;j++)
      printf("%d ",matrix[i][j]);
  return 0;
}
