#include <bits/stdc++.h>
typedef long long ll;
#define LIMIT 1299800
using namespace std;
vector<ll> precompute_primes(){
  vector<ll> primes(LIMIT+1,1);
  ll n=LIMIT;
  for(ll i=2;i<=n;i++){
    if(i*i>=n) break;
    for(ll j=i*i;j<=n;j+=i)
      primes[j]=0;
  }
  vector<ll> prime_sums;
  for(ll i=2;i<=n;i++)
    if(primes[i])
      prime_sums.push_back(i);
  return prime_sums;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  vector<ll> prime_list=precompute_primes();
  for(int i=1;i<prime_list.size();i++)
    prime_list[i]+=prime_list[i-1];
  int Q,q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    cin>>q;
    cout<<prime_list[q-1]<<"\n";
  }
  return 0;
}
