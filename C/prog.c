#include <stdio.h>
int max(int a,int b,int c){
  int m=a;
  if(b>m) m=b;
  if(c>m) m=c;
}
int main(){
  int size=9;
  char arr[]={'B','G','R','B','G','R','B','G','R'};
  //Bring all R's to front
  /* int end_ptr=size; */
  /* int r_exists=1,g_exists=1,b_exists=1; */
  int r_index=0,g_index=0,b_index=0;
  int j=0;
  int front_ptr=0,end_ptr=size-1;
  for(j=0;j<size;j++){
    printf("%s %d\n",arr,j);
    if(j>end_ptr) break;
    if(j<front_ptr)
      continue;
    if(arr[j]=='R'){
      //swap_with_front
      char temp=arr[j];
      if(arr[front_ptr]=='R'){
	front_ptr++;
	//j--;
	continue;
      }
      arr[j]=arr[front_ptr];
      arr[front_ptr]=temp;
      front_ptr++;
    }
    else if(arr[j]=='B'){
      //swap with end
      char temp=arr[j];
       if(arr[end_ptr]=='B'){
	end_ptr--;
	//j--;
	continue;
      }
       arr[j]=arr[end_ptr];
       arr[end_ptr]=temp;
       end_ptr--;
    }
  }
  printf("%s",arr);
}
