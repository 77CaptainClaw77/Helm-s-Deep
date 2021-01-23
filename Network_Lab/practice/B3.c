#include <stdio.h>
#define MAX_NODES 100
typedef struct{
  int distances[MAX_NODES];
  int through[MAX_NODES];
}node;
int main(int argc, char *argv[])
{
  int n,i,j,k;
  printf("Enter the number of nodes: ");
  scanf("%d",&n);
  printf("Enter the cost matrix: (Enter 100000 if no path exists)\n");
  node node_list[n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      int inp;
      scanf("%d",&inp);
      node_list[i].distances[j]=inp;
      node_list[i].through[j]=i;
      if(i==j)
	node_list[i].distances[j]=0;
    }
  }
  int updation_count=0;
  do{
    updation_count=0;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(k=0;k<n;k++){
	  if(node_list[i].distances[k]>node_list[i].distances[j]+node_list[j].distances[k]){
	    updation_count++;
	    node_list[i].distances[k]=node_list[i].distances[j]+node_list[j].distances[k];
	    node_list[i].through[k]=j;
	  }
	}
      }
    }
  }while(updation_count>0);
  for(i=0;i<n;i++){
    printf("%c's table\n",'a'+i);
    for(j=0;j<n;j++)
      printf("%c -> %c through %c : %d\n",'a'+i,'a'+j,'a'+node_list[i].through[j],node_list[i].distances[j]);
  }
  return 0;
}
