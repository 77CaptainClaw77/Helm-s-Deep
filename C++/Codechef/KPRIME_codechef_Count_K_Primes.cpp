#include <bits/stdc++.h>
using namespace std;
void precompute_arr(vector<int>& dp){
  int n=100000;
  for(int i=2;i<=n;i++){
    if(dp[i]==0){
      dp[i]=1;
      for(int j=i*2;j<=n;j+=i)
	dp[j]++;
    }
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  vector<int> dp(100001,0);
  precompute_arr(dp);
  while(T--){
    int A,B,K;
    cin>>A>>B>>K;
    int cnt=0;
    for(int i=A;i<=B;i++)
      if(dp[i]==K)
	cnt++;
    cout<<cnt<<"\n";
  }
  return 0;
}
