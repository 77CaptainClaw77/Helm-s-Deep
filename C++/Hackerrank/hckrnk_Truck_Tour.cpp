#include <iostream>
typedef long long ll;
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,dist,fuel,ans;
  ll distance=0;
  ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>fuel>>dist;
    distance+=fuel-dist;
    if(distance<0){
      ans=i+1;
      distance=0;
    }
  }
  cout<<ans;
  return 0;
}
