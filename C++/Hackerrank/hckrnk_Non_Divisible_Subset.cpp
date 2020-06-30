#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,k,temp;
  cin>>n>>k;
  map<int,int> m;
  for (int i=0; i<n; i++) {
    cin>>temp;
    m[temp%k]++;
  }
  int cnt=0;
  if(m[0]>0)
    cnt=1;
  for(int i=1;i<=k/2;i++){
    if(i!=k-i)
      cnt=cnt+max(m[i],m[k-i]);
  }
  if(k%2==0 && m[k/2]>0)
    cnt++;
  cout<<cnt;
}
