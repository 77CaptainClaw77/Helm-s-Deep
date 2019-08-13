#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int comp=0;
void Merge(int A[],int l_lim,int u_lim,int mid)
{
  int i=0,l=0,m=0,k=l_lim;
  int B[mid-l_lim+1];//there are mid-l_lim+1 elements including both the bounds.
  int C[u_lim-mid];//same as u_lim-(mid+1)+1
  for(i=0;i<mid-l_lim+1;i++)
    B[i]=A[i+l_lim];
  for(i=0;i<u_lim-mid;i++)
    C[i]=A[i+mid+1];
  while(l<(mid-l_lim+1) && m<(u_lim-mid))
    {
      comp++;
      if(B[l]<C[m])
	A[k++]=B[l++];
      else
	A[k++]=C[m++];
    }
  while(l<(mid-l_lim+1))
    A[k++]=B[l++];
  while(m<(u_lim-mid))
    A[k++]=C[m++];  
}
void MergeSort(int A[],int l_lim,int u_lim)
{
  int mid=(l_lim+u_lim)/2;
  if(l_lim<u_lim)
    {
      MergeSort(A,l_lim,mid);
      MergeSort(A,mid+1,u_lim);
      Merge(A,l_lim,u_lim,mid);//Merging is only required as long as there are atleast 2 elements to be sorted
    }
}
int main()
{
  int n,i;
  printf("Enter the number of elements to be generated:  ");
  scanf("%d",&n);
  int arr[n];
  srand(time(NULL));
  for(i=0;i<n;i++)
    arr[i]=rand()%(n*100)-(n*50);
  printf("The unsorted array is:-\n ");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
  MergeSort(arr,0,n-1);
  printf("\nThe sorted array is:-\n ");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
  printf("\nThe number of comparisions is:- %d",comp);
  printf("\nThe expected number of comparisions is:- %d\n",(int)(n*log((double)n)));
  return 0;
}
