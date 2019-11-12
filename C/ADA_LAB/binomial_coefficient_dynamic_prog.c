#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
  return a<b?a:b;
}
int BinomialCoeff(int n,int k){
  int i,j;
  int** C=malloc(sizeof(int*)*(n+1));
  for(i=0;i<=n;i++)
    C[i]=malloc(sizeof(int)*(k+1));
  for(i=0;i<=n;i++){
    for(j=0;j<=min(i,k);j++){
      if(j==0 || j==i)
	C[i][j]=1;
      else
	C[i][j]=C[i-1][j-1]+C[i-1][j];
    }      
  }
  return C[n][k];
}
int main(int argc, char *argv[]){
  int n,k;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  printf("Enter the value of k: ");
  scanf("%d", &k);
  printf("The binomial coefficient %dC%d = %d",n,k,BinomialCoeff(n,k));
  return 0;
}
