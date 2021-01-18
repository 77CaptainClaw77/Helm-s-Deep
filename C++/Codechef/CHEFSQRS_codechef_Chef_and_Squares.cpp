/*File Information:-
Author: Kumarguru V

Chef started solving a lot of mathematics problems during the lockdown period.
He was recently trying a problem related to square numbers but couldn't solve it, so needs your help.
He has a positive number NNN, he wants to find out the smallest perfect square XXX which when added to NNN yields another perfect square number.
Link: https://www.codechef.com/problems/CHEFSQRS
*/
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
