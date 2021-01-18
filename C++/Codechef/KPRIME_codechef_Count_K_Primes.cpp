/*File Information:-
Author: Kumarguru V

Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.
The game is called Count K-Primes. A number is a KKK-prime if it has exactly KKK distinct prime factors. The game is quite simple. Alice will give three numbers AAA, BBB & KKK to Bob. Bob needs to tell Alice the number of KKK-prime numbers between AAA & BBB (both inclusive). If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game TTT times.
Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.
Link: https://www.codechef.com/problems/S
*/
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
