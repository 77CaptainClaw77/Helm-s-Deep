#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++)
      cin>>arr[j];
    int ans=2,streak=0,diff=INT_MIN;
    for(int j=1;j<n;j++){
      ans=max(ans,streak+2);
      if(arr[j]-arr[j-1]==diff)
	streak++;
      else{
	diff=arr[j]-arr[j-1];
	streak=0;
      }
    }
    ans=max(ans,streak+2);
    cout<<"Case #"<<i+1<<": "<<ans<<"\n";
  }
  return 0;
}
