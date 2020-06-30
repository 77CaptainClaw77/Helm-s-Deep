#include <iostream>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    if(n<2)
      cout<<"-1\n";
    else{
      int sm=INT_MAX,s_sm=INT_MAX;
      for(int i=0;i<n;i++){
	if(arr[i]<sm){
	  s_sm=sm;
	  sm=arr[i];
	}
	if(arr[i]<s_sm && arr[i]>sm)
	  s_sm=arr[i];
      }
      // below is a solution using 2 loops instead of one loop
      // for(int i=0;i<n;i++){
      // 	if(arr[i]<sm)
      // 	  sm=arr[i];
      // }
      // for(int i=0;i<n;i++){
      // 	if(arr[i]<s_sm && arr[i]>sm)
      // 	  s_sm=arr[i];
      // }
      if(s_sm==INT_MAX)
	cout<<"-1\n";
      else
	cout<<sm<<" "<<s_sm<<"\n";
    }
  }
  return 0;
}
