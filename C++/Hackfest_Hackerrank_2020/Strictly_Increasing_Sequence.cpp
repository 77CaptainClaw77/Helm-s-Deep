#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t,n,temp;
  cin>>t;
  while(t--){
    cin>>n;
    int duplicates=0;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
      cin>>temp;
      if(s.find(temp)!=s.end())
	duplicates++;
      else
	s.insert(temp);
    }
    if(duplicates==0)
      cout<<"First\n";
    else
      cout<<((n-1)%2==0?"First\n":"Second\n");
  }
  return 0;
}
