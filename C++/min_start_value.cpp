#include <iostream>
using namespace std;
int main(){
  int n,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
  int min_val=arr[0];
  int s=arr[0];
  for(i=1;i<n;i++){
    s+=arr[i];
    if(s<min_val)
      min_val=s;
  }
  cout<<1-min_val;
}
