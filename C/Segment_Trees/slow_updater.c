#include <stdio.h>
#include <stdlib.h>
#include "range_functions.h'
void range_update_increment_slow(int a,int b,int delta,slow_updater* su){
  int i;
  for(i=a;i<b;i++)
    (su->arr[i])+=delta;
}
int range_query_slow(int a,int b,slow_updater* su){
  int min=su->arr[a];
  int i;
  for(i=a+1;i<b;i++)
    min=min<(su->arr[i])?(su->arr[i]):min;
  return min;
}
int main(int argc, char *argv[])
{
  
  return 0;
}
