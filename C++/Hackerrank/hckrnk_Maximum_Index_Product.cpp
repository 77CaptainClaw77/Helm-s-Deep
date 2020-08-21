#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// void print_arr(long long arr[],int n){
//   for(int i=0;i<n;i++)
//     cout<<arr[i]<<" ";
//   cout<<endl;
// }
int main(int argc, char *argv[])
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  stack<int> s;
  long long left[n]={};
  long long right[n]={};
  for(int i=0;i<n;i++){ 
    while(!s.empty() && arr[s.top()-1]<=arr[i])
      s.pop();
    if(s.empty()){
      s.push(i+1);
      left[i]=0;
    }
    else{
      left[i]=s.top();
      s.push(i+1);
    }
  }
  while(!s.empty()) s.pop(); //clearing the stack
  for(int i=n-1;i>=0;i--){ 
    while(!s.empty() && arr[s.top()-1]<=arr[i])
      s.pop();
    if(s.empty()){
      s.push(i+1);
      right[i]=0;
    }
    else{
      right[i]=s.top();
      s.push(i+1);
    }
  }
  //print_arr(left,n);
  //print_arr(right,n);
  long long mx=0;
  for(int i=0;i<n;i++)
    mx=max(mx,left[i]*right[i]);
  cout<<mx;
  return 0;
}
