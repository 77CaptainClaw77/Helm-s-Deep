#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string words[n];
    int weights[n];
    for(int i=0;i<n;i++){
      cin>>words[i];
      int w=0;
      for(char c:words[i])
	w+=(c-'a');
      weights[i]=w;
    }
    float t=0.0;
    int min_val=INT_MAX,min_ind=0;
    for(int i=0;i<n;i++)
      t+=weights[i];
    for(int i=0;i<n;i++){
      int avg=ceil((t-weights[i])/(n-1));
      int v=0;
      for(int j=0;j<n;j++){
	if(i==j)
	  continue;
	v+=abs(avg-weights[j]);
      }
      if(v<min_val){
	min_val=v;
	min_ind=i;
      }
    }
    cout<<words[min_ind];
  }
}
