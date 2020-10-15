#include <bits/stdc++.h>
using namespace std;
bool is_good_day(vector<long long>& arr,long long d,long long D){
  for(int i=0;i<arr.size();i++)
    d=ceil(d/(long double)arr[i])*arr[i];
  return d<=D;
}
long long bin_search_approach(vector<long long>& arr,long long D){
  long long l=1,h=D;
  while(l<h){
    long long m=(l+h+1)/2;
    if(is_good_day(arr,m,D))
      l=m;
    else
      h=m-1;
  }
  return l;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int n;
    long long D;
    cin>>n>>D;
    vector<long long> arr(n);
    for(int j=0;j<n;j++)
      cin>>arr[j];
    //optimal approach
    // long long ans=D;
    // for(int j=n-1;j>=0;j--)
    //   ans=ans-(ans%arr[j]);
    cout<<"Case #"<<i+1<<": "<<bin_search_approach(arr,D)<<"\n";
  }
  return 0;
}
