#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int n,p;
    cin>>n>>p;
    int arr[n];
    for(int j=0;j<n;j++)
      cin>>arr[j];
    sort(arr,arr+n);
    long long prefix_sums[n+1];
    prefix_sums[0]=0;
    for(int j=0;j<n;j++)
      prefix_sums[j+1]=arr[j]+prefix_sums[j];
    long long ans=INT_MAX;
    for(int j=p-1;j<n;j++)
      ans=min(ans,(p*arr[j]-(prefix_sums[j+1]-prefix_sums[j-p+1])));
    cout<<"Case #"<<i+1<<": "<<ans<<"\n";
  }
  return 0;
}
