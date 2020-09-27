#include <stdio.h>
int main(){
  int i,j;
  printf(" ");
  for(i=0;i<26;i++)
    printf("  %c",'a'+i);
  printf("\n");
  for(i=0;i<26;i++){
    printf("%c ",'a'+i);
    for(j=0;j<26;j++)
      printf("%2d ",(i*j)%26);
    printf("\n");
  }
  return 0;
}
