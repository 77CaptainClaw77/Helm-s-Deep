#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long L,R;
    cin>>L>>R;
    if(L>R)
      swap(L,R);
    long ans=R-L+1-(floor(sqrt(R))-ceil(sqrt(L))+1);
    cout<<ans<<"\n";
  }
  return 0;
}
