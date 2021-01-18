/*File Information:-
Author: Kumarguru V

Read problems statements in Mandarin Chinese and Russian
Given an array A1,A2,...,ANA_1, A_2, ..., A_N, count the number of subarrays of array AA which are non-decreasing.
A subarray A[i,j]A[i, j], where 1≤i≤j≤N1 ≤ i ≤ j ≤ N is a sequence of integers Ai,Ai+1,...,AjA_i, A_i+1, ..., A_j.
A subarray A[i,j]A[i, j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤AjA_i ≤ A_i+1 ≤ A_i+2 ≤ ... ≤ A_j. You have to count the total number of such subarrays.
Link: https://www.codechef.com/problems/SUBINC
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    int N;
    cin>>N;
    if(N==0){ cout<<"0\n"; continue;}
    int arr[N];
    for(int i=0;i<N;i++)
      cin>>arr[i];
    vector<int> dp(N,1);
    long long count=1;
    for(int i=1;i<N;i++){
      if(arr[i]>=arr[i-1])
	dp[i]+=dp[i-1];
      count+=dp[i];
    }
    cout<<count<<"\n";
  }
  return 0;
}
