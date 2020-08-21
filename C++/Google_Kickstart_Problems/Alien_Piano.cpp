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
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    vector<int> changes(n);
    changes[0]=0;
    for(int i=1;i<n;i++){
      if(arr[i]>arr[i-1])
	changes[i]=1;
      else if(arr[i+1]<arr[i])
	changes[i]=-1;
      else
	changes[i]=0;
    }
    if(n>1)
      changes[0]=arr[0]<arr[1]?1:(arr[0]>arr[1]?-1:0);
    vector<int> pref_sum(n);;
    for(int i=1;i<n;i++)
      pref_sum[i]+=pref_sum[i-1]+arr[i];
    int total_change=0;
    int sq_break=0;
    for(int i=1;i<n;i++){
      total_change+=changes[i];
      if(total_change>4){
	sq_break++;
	total_change-=4;
      }
      if(total_change<-4){
	sq_break++;
	total_change+=4;
      }
    }
    cout<<"Case #"<<j+1<<": "<<sq_break<<"\n";
  }
  return 0;
}
