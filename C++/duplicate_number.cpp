#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_dup_bin_search(vector<int>& vec){
  int l=1,h=vec.size()-1;
  while(l<h){
    int cnt=0;
    int mid=l+(h-1)/2;
    for(int i=0;i<vec.size();i++)
      cnt=vec[i]<=mid?cnt+1:cnt;
    if(cnt<=mid)
      l=mid+1;
    else
      h=mid;//not mid-1 since mid can also be duplicate nummber here
  }
  return l;
}
int find_dup_sorted_dup_algo(vector<int>& vec){
  sort(vec.begin(),vec.end());
  int ans;
  for(int i=0;i<vec.size()-1;i++){
    if(vec[i]==vec[i+1]){
      ans=vec[i];
      break;
    }
  }
  return ans;
}
int find_dup_floyds_algo(vector<int>& vec){
  int t=arr[0],h=arr[arr[0]];
  while(t!=h){
    t=arr[t];
    h=arr[arr[h]];
  }
  t=0;
  while(t!=h){
    t=arr[t];
    h=arr[h];
  }
  return t;
}
int main(int argc, char *argv[])
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  cout<<find_dup_floyds_algo(vec);
  return 0;
}

