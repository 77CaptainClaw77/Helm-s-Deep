#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  unordered_set<int> marks;
  int s=0;
  for(int i=0;i<n;i++){
    if(marks.find(arr[i])==marks.end()){
      marks.insert(arr[i]);
      s+=arr[i];
    }
    else{
      int x=arr[i]+1;
      while(marks.find(x)!=marks.end())
	x++;
      marks.insert(x);
      s+=x;
    }
  }
  cout<<s;
  return 0;
}
