/*File Information:-
Author: Kumarguru V

BILLIARDS is a really interesting game. It is played on a green baize with 3 balls-red, white and yellow.
Sheldon and Leonard are playing a game of billiards. Sheldon is playing the game for the first time and is not familiar with the rules. So he asks Leonard to explain the rules to him. Leonard explains the rules to Sheldon in the following way:  
“A Cannon shot gives 222 points and an In-Off Shot gives 333 points.” 
Sheldon is curious, and wants to figure out that given a score X, in how many ways can he get that score by hitting a combination of Cannon and In-Off shots? 
Leonard is baffled when he is asked this question.  
Your task is to help Leonard in writing a program to compute the total number of ways one can score a total of XXX points by hitting any combination of Cannon and In-Off shots. The order in which the shots are hit have importance.  
For example, 555 can be scored in two ways, by hitting an In-Off Shot followed by a Cannon shot or a Cannon Shot followed by an In-Off shot. A score of 777 can be achieved in three ways – Cannon,In-Off,Cannon Cannon,Cannon,In-Off and In-Off,Cannon,Cannon.
Link: https://www.codechef.com/problems/CDQU5
*/
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
