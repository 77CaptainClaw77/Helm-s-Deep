#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#define MAX_LIM 200
using namespace std;
int is_semi_prime(int val){ //solution 1: hardcoding
  set<int> prms={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
  int cnt=0;
  int lim=sqrt(val);
  for(int i:prms){
    if(i>lim)
      break;
    if(val%i==0 && val/i!=i){
      if(prms.find(val/i)!=prms.end()){
	//cout<<val<<":"<<i<<" "<<val/i<<"\n";
	return 1;
      }
    }
  }
  return 0;
}
vector<int> precalculate_all(int lim){ //solution 2: precomputation
  vector<int> sieve(lim-1); //precalc all semiprimes till lim
  for(int i=2;i<=lim/2;i++){
    int x=i;
    while(1){
      if(x*i>lim) break;
      sieve[x*i-2]=1;
      x++;
    }
  }
  vector<int> prms;
  for(int i=0;i<lim-1;i++){
    if(sieve[i]==0){
      // cout<<i+2<<" , ";		
      prms.push_back(i+2);
    }
  }
  vector<int> smprms(lim);
  for(int i=0;i<prms.size()-1;i++){
    if(prms[i]>=lim/2)
      break;
    for(int j=i+1;j<prms.size();j++){
      int prod=prms[i]*prms[j];
      if(prod>lim)
	break;
      smprms[prod-1]=1;
    }
  }
  return smprms;
}
int main(int argc, char *argv[])
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,N;
  cin>>T;
  vector<int> smprms=precalculate_all(MAX_LIM);
  cout<<"\n";
  // for(int i=0;i<smprms.size();i++){
  //   if(smprms[i])
  //     cout<<i+1<<" , ";
  // }
  while(T--){
    cin>>N;
    bool is_sum=false;
    for(int i=1;i<=N/2;i++){
      if(smprms[i-1] && smprms[N-i-1]){
	is_sum=true;
	break;
      }
    }
    if(is_sum)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  /*  while(T--){
    cin>>N;
    bool issmp=false;
    for(int i=1;i<=N/2;i++){
      if(smprms[i]==-1)
	smprms[i]=is_semi_prime(i);
      if(smprms[N-i]==-1)
	smprms[N-i]=is_semi_prime(N-i);
      if(smprms[i]==1 && smprms[N-i]==1){
	issmp=true;
	//cout<<i<<" "<<N-i<<"\n";
	break;
      }
    }
    if(issmp)
      cout<<"YES\n";
    else
      cout<<"NO\n";
      }*/
  return 0;
}
