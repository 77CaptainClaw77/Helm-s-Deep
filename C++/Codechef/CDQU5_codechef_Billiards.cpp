#include <bits/stdc++.h>
#define MOD_VAL 1000000009
using namespace std;
//top down dp (caching)
int find_number_of_combinations(vector<int>& dp,int X){
  if(X==2 || X==3)
    return 1;
  if(X<2)
    return 0;
  if(dp[X]!=-1)
    return dp[X];
  long long value_a=find_number_of_combinations(dp,X-2);
  long long value_b=find_number_of_combinations(dp,X-3);
  dp[X]=(value_a+value_b)%MOD_VAL;
  return dp[X];
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  int bottom_up_dp[1000001]={0,0,1,1};
  for(int i=4;i<=1000000;i++){
    long long sum=bottom_up_dp[i-2]+bottom_up_dp[i-3];
    bottom_up_dp[i]=sum%MOD_VAL;
  }
  vector<int> dp(1000001,-1);
  while(T--){
    int X;
    cin>>X;
    //cout<<find_number_of_combinations(dp,X)<<"\n";
    cout<<bottom_up_dp[X]<<"\n";
  }
  return 0;
}
