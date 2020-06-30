#include <iostream>
#include <vector>
using namespace std;
int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    long long q_sum=0;
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int j=0;j<n;j++)
      cin>>arr[j];
    for(int j=0;j<q;j++){
      char ch;
      cin>>ch;
      int v1,v2;
      cin>>v1>>v2;
      if(ch=='Q'){
	int fact=1,alt=1;
	for(int k=v1-1;k<v2;k++){
	  q_sum=q_sum+(arr[k]*fact*alt);
	  fact++;
	  alt=-alt;
	}
      }
      else{
	arr[v1-1]=v2;
      }
    }
    cout<<"Case "<<i+1<<": "<<q_sum<<endl;
  }
  return 0;
}
