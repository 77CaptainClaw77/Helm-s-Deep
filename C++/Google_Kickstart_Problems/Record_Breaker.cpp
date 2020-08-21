#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int j=0;j<t;j++){
    int n;
    int rb=0;
    cin>>n;
    vector<int> arr(n+1,-1);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int mx=-1;
    for(int i=0;i<n;i++){
      if(arr[i]>mx && arr[i]>arr[i+1]){
	//cout<<arr[i];
	mx=max(arr[i],mx);
	i++;
	rb++;
      }
      else
	mx=max(arr[i],mx);
    }
    //cout<<"\n";
    cout<<"Case #"<<j+1<<": "<<rb<<"\n";
  }
  return 0;
}
