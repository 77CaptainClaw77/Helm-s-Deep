#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,k;
        int k_cnt=0;
        cin>>n>>k;
        vector<int> arr(n);
	for(int i=0;i<n;i++)
	  cin>>arr[i];
        for(int i=0;i<n-1;i++){
            if(arr[i]==k){
                while(i<n-1){
		  if(arr[i+1]==arr[i]-1){
		    if(arr[i+1]==1){
		      k_cnt++;
		      break;
		    }
		    else
		      i++;
		  }
		  else
		    break;
                }
            }
        }
        cout<<"Case #"<<j+1<<": "<<k_cnt<<endl;
    }
}
