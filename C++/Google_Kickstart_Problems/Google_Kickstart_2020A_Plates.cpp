//This problem is esssentially the same as 0/1 knapsack problem.
//Here value is the sum of beauty value of a plate and all above it
//Weight is essentially the position of the plate on the stack
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print2d(vector<vector<int>> v,int R,int C){
  for(int i=0;i<=R;i++){
    for(int j=0;j<=C;j++){
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N,K,P;
    cin>>N>>K>>P;
    vector<vector<int>> pre_calc_sum(N+1,vector<int>(K+1)); //Stores actual weight and value of each plate
    for(int i=1;i<=N;i++){
      for(int j=1;j<=K;j++){
	cin>>pre_calc_sum[i][j];
	pre_calc_sum[i][j]+=pre_calc_sum[i][j-1];
      }
    }
    vector<vector<int>> dp(N+1,vector<int>(P+1));
    for(int i=1;i<=N;i++){
      for(int j=1;j<=P;j++){
	dp[i][j]=0;
	for(int x=0;x<=min(j,K);x++)
	  dp[i][j]=max(dp[i][j],pre_calc_sum[i][x]+dp[i-1][j-x]);
      }
    }
    cout<<"Case #"<<i+1<<": "<<dp[N][P]<<"\n";
  }
  return 0;
}
