#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  for(int i=n-2;i>=0;i--)
    arr[i]+=arr[i+1];
  long long half=arr[0]/2;
  int min=0;
  for(int i=n-1;i>=0;i--){
    if(arr[i]>half){
      min=n-i;
      break;
    }
  }
  cout<<min;
}
