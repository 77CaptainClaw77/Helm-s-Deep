#include <iostream>
bool check(int d,int k,int arr[],int N){
  int sess_cnt=0;
  for(int i=1;i<N;i++)
    sess_cnt+=(arr[i]-arr[i-1]-1)/d;
  if(sess_cnt<=k)
    return true;
  return false;
}
int b_search(int low,int high,int arr[],int N,int k){
  while(low<high){
    int mid=(low+high)/2;
    if(check(mid,k,arr,N))
      high=mid;
    else
      low=mid+1;
  }
  return low;
}
using namespace std;
int main(int argc, char *argv[])
{
  int T;
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>T;
  for(int c=0;c<T;c++){
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++)
      cin>>arr[i];
    int num=b_search(1,1e9,arr,N,K);
    cout<<"Case #"<<c+1<<": "<<num<<"\n";
  }
  return 0;
}
