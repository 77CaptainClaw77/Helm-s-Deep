#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main(int argc, char *argv[])
{
  int m,n;
  cin>>n>>m;
  vector<ll> arr(n);
  int a,b,k;
  ll peak=0,cur=0;
  for(int i=0;i<m;i++){
    cin>>a>>b>>k;
    arr[a-1]+=k;
    arr[b]-=k;
  }
  for(int i=0;i<n;i++){
    cur+=arr[i];
    peak=cur>peak?cur:peak;
  }
  cout<<peak;
  return 0;
}
