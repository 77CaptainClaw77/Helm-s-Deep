#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  int n,m;
  cin>>n>>m;
  int matrix[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>matrix[i][j];
  int dp[m][n];
  dp[0][0]=matrix[0][0];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int top_best=INT_MAX,left_best=INT_MAX;
      if(i==0 && j==0) continue;
      if(i>0)
	top_best=dp[i-1][j];
      if(j>0)
	left_best=dp[i][j-1];
      dp[i][j]=min(left_best,top_best)+matrix[i][j];
    }
  }
  cout<<"Optimal Cost: "<<dp[n-1][m-1]<<"\n";
  cout<<"Optimal Path:-\n";
  int st_x=n-1,st_y=m-1;
  while(st_x>0 || st_y>0){
    int top_best=INT_MAX,left_best=INT_MAX;
    if(st_x>0)
      top_best=dp[st_x-1][st_y];
    if(st_y>0)
      left_best=dp[st_x][st_y-1];
    cout<<matrix[st_x][st_y]<<" ";
    if(left_best<top_best)
      st_y--;
    else
      st_x--;
  }
  cout<<matrix[0][0];
  return 0;
}
