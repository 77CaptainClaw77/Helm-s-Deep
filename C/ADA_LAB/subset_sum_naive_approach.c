#include <stdio.h>
#include <stdlib.h>
int subset_exists=0;
void print_subset(int* subset,int n)
{
  int i=0;
  printf("\nSubset: ");
  for(i=0;i<n;i++)
    printf("%d\t",subset[i]);
}
void generate_subsets(int* arr,int n,int* subset,int m,int sum,int target,int iter)
{
  
  if(target==sum)
    {
      subset_exists=1;
      print_subset(subset,m);
      // if(iter==n)
      //	return;
      //      generate_subsets(arr,n,subset,m-1,sum-arr[iter],target,iter+1);
      return;
    }
  else
    {
      int k;
      for(k=iter;k<n;k++)
	{
	   subset[m]=arr[k];
	   generate_subsets(arr,n,subset,m+1,sum+arr[k],target,k+1);
	}
    }		       
}
int main()
{
  int n,i,sum;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  int* arr=malloc(sizeof(int)*n);
  int* subset=malloc(sizeof(int)*n);
  printf("Enter the elements:-\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter the target sum:");
  scanf("%d",&sum);
  generate_subsets(arr,n,subset,0,0,sum,0);
  if(!subset_exists)
    printf("No Subsets Found.");
  return 0;
}
