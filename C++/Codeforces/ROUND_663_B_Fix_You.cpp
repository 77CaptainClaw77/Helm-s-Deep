#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int r,c;
  int t;
  cin>>t;
  while(t--){
    cin>>r>>c;
    string grid[r];
    //int dp[r][c]={};
    for(int i=0;i<r;i++)
      cin>>grid[i];
    // this is dp for fastest reachable from start at 0 0
    // for(int i=0;i<r;i++){
    //   int x;
    //   for(int j=0;j<c;j++){
    // 	if(i==0 && j==0) continue;
    // 	int left_cost=INT_MAX,top_cost=INT_MAX;
    // 	if(i>0)
    // 	  top_cost=grid[i-1][j]=='D'?dp[i-1][j]:dp[i-1][j]+1;
    // 	if(j>0)
    // 	  left_cost=grid[i][j-1]=='R'?dp[i][j-1]:dp[i][j-1]+1;
    // 	dp[i][j]=min(left_cost,top_cost);
    //   }
    // }
    // cout<<dp[r-1][c-1]<<"\n";	
    //}
    int min_change_cnt=0;
    for(int i=0;i<c-1;i++)
      min_change_cnt+=grid[r-1][i]=='D';
    for(int i=0;i<r-1;i++)
      min_change_cnt+=grid[i][c-1]=='R';
    cout<<min_change_cnt<<"\n";
  }
  return 0;
}
