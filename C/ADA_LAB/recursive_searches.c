#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int comp=0;
void gen_rand_num(int *arr,int n)
{
  srand(time(NULL));
  int i;
  for(i=0;i<n;i++)
    arr[i]=rand()%10000;
}
void sort_arr(int arr[],int n,bool order)//if order is true, then ascending else desscending 
{
  int i=0,j=0;
  for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
	{
	  if((order?arr[j]>arr[j+1]:arr[j]<arr[j+1]))
	    {
	      arr[j]=arr[j]+arr[j+1];
	      arr[j+1]=arr[j]-arr[j+1];
	      arr[j]=arr[j]-arr[j+1];
	    }
	  comp++;
	}
    }
}
int rec_binsearch(int *arr,int n,int key,bool order,int low,int high)
{
  if(low<=high)
   {
     comp++;
     int mid=(low+high)/2;
     if(arr[mid]<key)
      {
	if(order)
	  return rec_binsearch(arr,n,key,order,mid+1,high);
	return rec_binsearch(arr,n,key,order,low,mid-1);
      }
     else if(arr[mid]>key)
      {
	if(order)
	  return rec_binsearch(arr,n,key,order,low,mid-1);
	return rec_binsearch(arr,n,key,order,mid+1,high);
      }
     else
       return mid+1;
   }
  return -1;
}
int rec_linsearch(int *arr,int n,int key,int cur)
{
  if(cur<n)
    {
      comp++;
      if(arr[cur]==key)
	return cur+1;
      return rec_linsearch(arr,n,key,cur+1);
    }
  return -1;
}
int main()
{
  int n=0,i=0,ch=0,key=0,pos=0;
  bool order=false;
  char c;
  while(true)
  {
    printf("\nSelect the desired option:-\n1.Binary Search\n2.Linear Search\n3.Exit\n");
    scanf("%d",&ch);
    if(ch==3) break;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    int* arr=malloc(sizeof(int)*n);
    printf("Press \'y\' for user input and anything else for random input");
    scanf("%*c%c",&c);
    if(c=='y' || c=='Y')
      {
	printf("Enter the elements:-\n");
	for(i=0;i<n;i++)
	  scanf("%d",(arr+i));
	scanf("%*c");
      }
    else
	gen_rand_num(arr,n);
    
    printf("Press \'y\' sort the input in ascending order, \'Y\' to sort in descending order ");
    if(ch!=1)
    printf("and anything else to use an unsorted array ");
    scanf("%c",&c);
    order=c=='y'?true:false;
    if(c=='y')
      sort_arr(arr,n,true);
    if(c=='Y')
      sort_arr(arr,n,false);
    printf("The array is:-\n");
    for(i=0;i<n;i++)
      printf("%d\t",*(arr+i));
    printf("\nEnter the key element ");
    scanf("%d",&key);
    if(ch==1)
      pos=rec_binsearch(arr,n,key,order,0,n-1);
    else
      pos=rec_linsearch(arr,n,key,0);
    if(pos==-1)
      printf("Element %d not found in the array.",key);
    else
      printf("Element %d found at position %d in the array.",key,pos);
    printf("\nNumber of comparisions(with sorting included): %d",comp);
    comp=0;
  }
  return 0;
}
