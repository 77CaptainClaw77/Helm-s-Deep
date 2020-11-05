#include <stdio.h>
#include <stdlib.h>
int check_lim(int x){
  return x>0 && x<=10?1:0; //check condition
}
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c); //input
  if(check_lim(a) && check_lim(b) && check_lim(c)){
    if(a<b+c && b<a+c && c<a+b){ //check if triangle
      if(a==b && a==c)
	printf("Equilateral "); //check if equilateral
      else if(a==b || a==c)
	printf("Isoscles "); //check if isoscles
      else
	printf("Scalene "); //check if scalene
      printf("Triangle\n");
    }
    else
      printf("Not a Triangle\n");
  }
  else
    printf("Invalid input!\n");
  return 0;
}
