#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int is_perfect_square(int n){
  if(n<0)
    return 0;
  if(sqrt(n)-floor(sqrt(n))==0)
    return 1;
  return 0;
}
int main(){
  int t;
  cin>>t;
  for(int k=0;k<t;k++){
    int n;
    cin>>n;
    int perf_sq_count=0;
    vector<int> arr(n+1),pref(n+1);
    for(int i=1;i<=n;i++){
      cin>>arr[i];
      pref[i]=pref[i-1]+arr[i];
      perf_sq_count+=is_perfect_square(pref[i]);
    }
    for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
	perf_sq_count+=is_perfect_square(pref[j]-pref[i]);
      }
    }
    cout<<"Case #"<<k+1<<": "<<perf_sq_count<<endl;
  }
}
