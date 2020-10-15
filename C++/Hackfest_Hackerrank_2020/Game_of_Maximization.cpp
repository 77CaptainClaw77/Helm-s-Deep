#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long ans=0,s=0;
  int n,temp;
  bool f=true;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    ans+=f?temp:-temp;
    f=!f;
    s+=temp;
  }
  cout<<s-abs(ans);
  return 0;
}
