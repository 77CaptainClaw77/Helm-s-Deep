#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)
      cout<<i<<" ";
    cout<<"\n";
  }
  return 0;
}
