#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) { //O(n^2) time and O(n^2) space DP
  if(s.size()<=1) return s;
  int n=s.size();
  vector<vector<int>> dp(n,vector<int>(n,0));
  int max_len=1,start_pos=0; // only single character
  // the below loop does not find only single character substrings
  for(int i=n-1;i>=0;i--){ // here i is the start
    dp[i][i]=1;
    for(int j=i+1;j<n;j++){ //j is the end index
      if(j==i+1 && s[i]==s[j])
	dp[i][j]=1;
      else if(dp[i+1][j-1]==1 && s[i]==s[j])
	dp[i][j]=1;             
      if(max_len<j-i+1 && dp[i][j]){
	max_len=max(max_len,j-i+1);
	start_pos=i;
      }
    }
  }
  //cout<<start_pos<<" "<<max_len<<"\n";
  return s.substr(start_pos,max_len);
}
int main(){
  string s;
  cin>>s;
  cout<<longestPalindrome(s);
}
