#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  int arr[n]={0};
  for(int i=0;i<n;i++){
    int parent;
    cin>>parent;
    if(parent==-1) continue;
    arr[parent]++;
  }
  int cnt=0;
  for(int i=0;i<n;i++)
    if(arr[i]>=x)
      cnt++;
  cout<<cnt;
  return 0;
}
