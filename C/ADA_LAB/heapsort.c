#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
int comp=0;
void bottom_up_heapify(int* heap,int n)
{
  //n is the last index not the size
  int i=n/2;
  for(;i>0;i--)
    {
      int k=i,v=heap[i],is_heap=0;
      while(!is_heap && 2*k<=n)
	{
	  comp++;
	  int j=2*k;
	  if(j<n)
	    if(heap[j+1]>heap[j])
	      j=j+1;
	  if(v>heap[j])
	    is_heap=1;
	  else
	    {
	      heap[k]=heap[j];
	      k=j;
	    }
	}
      heap[k]=v;      
    }
}
void heapsort(int* heap,int n)
{
  while(n>1)
    {
      printf("%d\t",heap[1]);
      heap[1]+=heap[n];
      heap[n]=heap[1]-heap[n];
      heap[1]=heap[1]-heap[n];
      n=n-1;
      bottom_up_heapify(heap,n);
      // comp++;
    }
  printf("%d",heap[1]);
}
int main()
{
  srand(time(NULL));
  int *heap,n,i;
  printf("Enter the number of elements to be randomly generated: ");
  scanf("%d",&n);
  //clock_t begin=clock();
  heap=(int*)malloc(sizeof(int)*(n+1));
  *heap=INT_MAX;//sentinel value
  for(i=1;i<=n;i++)
    heap[i]=rand();
  printf("\nThe unsorted array is:-\n");
  for(i=1;i<=n;i++)
   printf("%d\t",heap[i]);
  bottom_up_heapify(heap,n);
  //for(i=0;i<=n;i++)
  // printf("%d\t",heap[i]);
  printf("\nThe sorted array is:- \n");
  heapsort(heap,n);
  // clock_t end=clock();
  //printf("\nTime taken for execution=%f seconds \n",((double)(end-begin)/CLOCKS_PER_SEC));
  printf("\nNumber of comparisons (heapification included): %d",comp);
  return 0;
}
