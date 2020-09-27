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
