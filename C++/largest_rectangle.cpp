#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int m,n;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<m;i++)
      cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    bool lset=false,rset=false;
    int lval=0,rval=0;
    while(i<n && j<m){
      if(a[i]==b[j]){
	if(!lset){
	  lval=a[i];
	  lset=true;
	}
	else{
	  rval=a[i];
	  rset=true;
	}
	i++;
	j++;
      }
      else if(a[i]<b[j])
	i++;
      else
	j++;
    }
    if(!lset || !rset)
      cout<<"0\n";
    else
      cout<<rval-lval<<"\n";
  }
  return 0;
}
