#include <iostream>
using namespace std;
int get_p_of_two(long long n){
  int p=1;
  while(n>0){
    if(n&1)
      break;
    p++;
    n=n>>1;
  }
  return p;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long long TS;
    cin>>TS;
    int p=get_p_of_two(TS);
    long long div=1<<p;
    long long ans=TS/div;
    cout<<ans<<"\n";
  }
  return 0;
}
