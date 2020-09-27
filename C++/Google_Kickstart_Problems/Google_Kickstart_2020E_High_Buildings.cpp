#include <bits/stdc++.h>
using namespace std;
void print_ans(vector<int> arr){
  for(int i:arr)
    cout<<i<<" ";
  cout<<"\n";
}
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int k=0;k<T;k++){
    int N,A,B,C;
    cin>>N>>A>>B>>C;
    vector<int> arr(N),ans(N);
    int n1=A-C,n2=B-C;
    if(n1<0 || n2<0 || (A+B)-N>C || A>N || B>N){
      cout<<"Case #"<<k+1<<": "<<"IMPOSSIBLE\n";
      continue;
    }
    int low=1,high=N-1;
    for(int i=0;i<n1;i++)
      arr[i]=low++;
    for(int i=n1;i<n1+C;i++)
      arr[i]=N;
    for(int i=N-1;i>=N-n2;i--)
      arr[i]=low++;
    low=1;
    for(int i=N-n2-1;i>=n1+C;i--)
      arr[i]=low;
    cout<<"Case #"<<k+1<<": ";
    print_ans(arr);
  }
  return 0;
}
