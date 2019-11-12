#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp_count=0;
int asc_comparator(const void* a,const void* b){
  return (*(const int*)a)>(*(const int*)b);
}
int desc_comparator(const void* a,const void* b){
  return (*(const int*)a)<(*(const int*)b);
}
void insort(int* arr,int n,int order){
  int i,j;
  for(i=1;i<n;i++){
    int key=arr[i];
    j=i-1;
    while(j>=0 && ((arr[j]>key && !order) ||(arr[j]<key && order))){
      arr[j+1]=arr[j];
      j--;
      comp_count++;
    }
    arr[j+1]=key;
  }
}
int main(int argc, char *argv[]){
  int* arr;
  int n,i;
  char ch;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  arr=malloc(sizeof(int)*n);
  printf("Enter \'y\' to generate random elements and anything else to input: ");
  scanf("%*c%c",&ch);
  if (ch=='y') {
    printf("Press \'y\' for ascending, \'n\' for descending order and anything else for random order: ");
    scanf("%*c%c", &ch);
    srand(time(NULL));
    for (i = 0; i < n; ++i)    
      arr[i]=rand()%100000;
    if(ch=='y'){
      qsort(arr,n,sizeof(int),asc_comparator);
    }
    if(ch=='n'){
      qsort(arr,n,sizeof(int),desc_comparator); 
    }
  }
  else {
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
      scanf("%d", &arr[i]);
  }
  printf("The elements to be sorted are:-\n");
  for (i = 0; i < n; i++) {
    printf("%d\t",arr[i]);
  }
  printf("\nEnter \'y\' for ascending order sort and anything else for descending order sort: ");
  scanf("%*c%c", &ch);
  int order=ch=='y'?0:1;
  insort(arr,n,order);
  printf("\nThe sorted array is:-\n");
  for (i = 0; i < n; i++) {
    printf("%d\t",arr[i]);
  }
  printf("\nTotal number of comparisions performed: %d",comp_count);
  return 0;
}
