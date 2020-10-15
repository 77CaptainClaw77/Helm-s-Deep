#include <bits/stdc++.h>
using namespace std;
#define LIM 1000001
/* The below method precomputes top down in aprrox O(n^2) and is too slow
int get_min_prod_step_count(int x,int dp[]){
  int mstp_cnt=INT_MAX;
  for(int i=2;i<=(int)sqrt(x);i++)
    if(x%i==0)
      mstp_cnt=min(mstp_cnt,dp[x/i]);
  return mstp_cnt;
}
int compute_steps(int x,int dp[]){
  return 1+min(dp[x-1],get_min_prod_step_count(x,dp));
}
*/
void pre_compute(int dp[]){
  dp[1]=1;dp[2]=2;dp[3]=3;
  for(int i=1;i<LIM;i++){
    if(dp[i]==0 || dp[i]>dp[i-1]+1)
      dp[i]=dp[i-1]+1;
    for(int j=2;j<=i && j*i<LIM;j++){
      if(dp[i*j]==0 || dp[i]+1<dp[i*j])
	dp[i*j]=1+dp[i];
    }
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int dp[LIM]={0};
  // dp[1]=1;
  // for(int i=2;i<LIM;i++)
  //   dp[i]=compute_steps(i,dp);
  pre_compute(dp);
  int q,t;
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>t;
    cout<<dp[t]<<"\n";
  }
  return 0;
}
