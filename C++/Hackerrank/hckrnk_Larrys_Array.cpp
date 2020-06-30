#include <iostream>
using namespace std;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int inv_count=0;
  int t,n;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++)
      cin>>arr[j];
    for(int j=0;j<n-1;j++){
      for(int k=j+1;k<n;k++){
	if(arr[j]>arr[k])
	  inv_count++;
      }
    }
    if(inv_count%2==0)
      cout<<"YES\n";
    else
      cout<<"NO\n";
    inv_count=0;
  }
  return 0;
}
