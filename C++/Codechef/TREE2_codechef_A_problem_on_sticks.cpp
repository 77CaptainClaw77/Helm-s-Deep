#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int n,temp;
    cin>>n;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
      cin>>temp;
      if(temp!=0)
	s.insert(temp);
    }
    cout<<s.size()<<"\n";
  }
  return 0;
}
