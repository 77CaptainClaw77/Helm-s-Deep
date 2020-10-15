#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  vector<int> considered(n);
  sort(v.begin(),v.end());
  unordered_set<int> cntr;
  for(int i=v.size()-1;i>=0;i--){
    if(considered[i])
      break;
    considered[i]=1;
    cntr.insert(i);
    for(int j=i-1;j>=0;j--){
      if(considered[j])
	break;
      if(v[i]+v[j]<=k){
	for(int l=j;l>=0;l--)
	  considered[l]=1;
      }
    }
  }
  cout<<cntr.size();
}
