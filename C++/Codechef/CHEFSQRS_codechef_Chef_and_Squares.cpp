#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long long N,ans;
    cin>>N;
    ans=-1;
    for(int i=1;i<sqrt(N);i++){
      if(N%i==0){
	long long va=i;
	long long vb=N/i;
	long long x=vb-va;
	if(x%2==0){
	  ans=x/2;
	}
      }
    }
    if(ans!=-1)
      cout<<ans*ans<<"\n";
    else
      cout<<"-1\n";
  }
  return 0;
}
