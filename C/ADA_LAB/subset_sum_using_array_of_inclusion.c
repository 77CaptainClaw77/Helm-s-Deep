#include <stdio.h>
#include <stdlib.h>
int subset_count=0;
void printallsubsets(int* arr,int cur_sum,int desired_sum,int* included,int n,int index){
  int i;
  if(cur_sum>desired_sum)
    return;
  if(cur_sum==desired_sum){
    subset_count++;
    printf("\nSubset %d: ",subset_count);
    for(i=0;i<n;i++)
      if(included[i])
	printf("%d\t",arr[i]);
  }
  else{
    if(index==n)
      return;
    included[index]=1;
    printallsubsets(arr,cur_sum+arr[index],desired_sum,included,n,index+1);
    included[index]=0;
    printallsubsets(arr,cur_sum,desired_sum,included,n,index+1);  
  }
}
int main(int argc, char *argv[]){
  int n,i,sum;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int* arr=malloc(sizeof(int)*n);
  printf("Enter the elements:-\n");
  for (i = 0; i < n; i++)   
    scanf("%d",&arr[i]);
  printf("Enter the desired sum:-");
  scanf("%d",&sum);
  int* included=calloc(n,sizeof(int));
  printallsubsets(arr,0,sum,included,n,0);
  if(subset_count==0)
    printf("\nNo subsets that satisfy the condition exist!");      
  return 0;
}
