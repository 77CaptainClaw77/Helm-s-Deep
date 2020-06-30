#include <iostream>
using namespace std;
template<class T>
int find_upper_closest(T arr[],int n,T ele){ //find smallest element greater than or equal to current element
  int l=0,h=n-1;
  while(l<h){
    int m=l+(h-l)/2;
    if(arr[m]>=ele)
      h=m;
    else
      l=m+1; 
  }
  return l;
}
template<class T>
int find_lower_closest(T arr[],int n,T ele){ //find largest element smaller than or equal to current element
  int l=0,h=n-1;
  while(l<h){
    int m=l+(h-l+1)/2;
    if(arr[m]<=ele)
      l=m;
    else
      h=m-1;
  }
  return h;
}
int main(int argc, char *argv[])
{
  int arr[]={2,4,6,8,10};
  cout<<find_lower_closest(arr,5,5)<<"\t"<<find_upper_closest(arr,5,5);
  return 0;
}
