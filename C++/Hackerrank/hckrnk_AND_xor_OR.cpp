#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  int n;
  long max_xor=0;
  cin>>n;
  stack<int> s;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  s.push(arr[0]);
  for(int i=1;i<n;i++){
    while(!s.empty()){
      long new_xor=arr[i]^s.top();
      if(new_xor>max_xor)
	max_xor=new_xor;
      if(arr[i]<s.top())
	s.pop();
      else
	break;
    }
    s.push(arr[i]);
  }
  cout<<max_xor;
  return 0;
}
