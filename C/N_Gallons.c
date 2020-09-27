#include <stdio.h>
int main(){
  int N;
  scanf("%d",&N);
  int min_no=0;
  min_no+=N/10;
  N=N%10;
  min_no+=N/7;
  N=N%7;
  min_no+=N/5;
  N=N%5;
  min_no+=N;
  printf("%d",min_no);
  return 0;
}
