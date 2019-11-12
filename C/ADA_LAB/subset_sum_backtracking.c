#include <stdio.h>
#include <stdlib.h>
int subset_exists=0;
int comparator(const void* arg1,const void* arg2)
{ return *((int*)arg1)>*((int*)arg2);}
void print_subset(int *subset,int n)
{
  int i;
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
      if(iter==n) return;
      //      if(sum-subset[iter]+subset[iter+1]<=target)
      ///	generate_subsets(arr,n,subset,m-1,sum-arr[iter],target,iter+1);
    }
  else
    {
      if(sum+arr[iter]<=target)
	{
      int k;
      for(k=iter;k<n;k++)
	{
	  subset[m]=arr[k];
	  if(sum+arr[k]<=target)
	    generate_subsets(arr,n,subset,m+1,sum+arr[k],target,k+1);
	}
	}
    }
}
int main()
{
  int n,i,target;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  int *arr=malloc(sizeof(int)*n);
  int *subset=malloc(sizeof(int)*n);
  printf("Enter the elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  qsort(arr,n,sizeof(int),&comparator);
  printf("Enter the target sum");
  scanf("%d",&target);
  generate_subsets(arr,n,subset,0,0,target,0);
  if(!subset_exists)
    printf("No subsets!");
  return 0;
}
