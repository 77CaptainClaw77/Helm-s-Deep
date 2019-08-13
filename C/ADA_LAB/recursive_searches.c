#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int key=0,arr_size=0;
void sort_arr(int A[],int arr_size)
{
  int i,j;
  for(i=0;i<arr_size-1;i++)
    {
      for(j=i+1;j<arr_size;j++)
	{
	  if(A[j]<A[j-1])
	    {
	      A[j]+=A[j-1];
	      A[j-1]=A[j]-A[j-1];
	      A[j]-=A[j-1];
	    }
	}
    }
  printf("\n");
  for(i=0;i<arr_size;i++)
    printf("%d\t",A[i]);
}
int r_bin_search(int A[],int l,int u)
{
  int m=(l+u)/2;
  if(l<=u)
    {
      printf("%d\n",m);
      if(A[m]==key)
	return m;
      else
	{
	  if(A[m]<key)
	    r_bin_search(A,m+1,u);
	  else
	    r_bin_search(A,l,m-1);
	}
    }
  else
    return -1;
    
}
int r_lin_search(int A[],int i,int arr_size)
{
  if(i<(sizeof(A)/sizeof(A[0])))
    {
      if(A[i]==key)
	return i;
      //return r_lin_search(A,i+1);
    }
  else
    return -1;
}
int main()
{
  int n,i,choice,fpos;
  printf("Enter the number of elements to be generated: ");
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
    {  arr[i]=rand()%(n*100)-n%50;
      printf("%d\t",arr[i]);
    }
  sort_arr(arr,n);
  printf("Enter the key element: ");
  scanf("%d",&key);
  printf("\n1.Linear Search\n2.Binary Search\nYour Choice: ");
  scanf("%d",&choice);
  if(choice==1)
    fpos=r_lin_search(arr,0,n);
  else
    {  fpos=r_bin_search(arr,0,n-1);
      
    }
  printf("%d",fpos);
}
