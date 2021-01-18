/*File Information:-
Author: Kumarguru V

"I'm a fan of anything that tries to replace actual human contact." - Sheldon.
After years of hard work, Sheldon was finally able to develop a formula which would diminish the real human contact.  
He found kk integers n1,n2...nkn_1,n_2...n_k . Also he found that if he could minimize the value of mm such that  ∑ki=1\sum_{i=1}^knniiCCmmii is even, where mm = ∑ki=1\sum_{i=1}^kmim_i, he would finish the real human contact.  
Since Sheldon is busy choosing between PS-4 and XBOX-ONE, he want you to help him to calculate the minimum value of mm. 
Link: https://www.codechef.com/problems/SUMNCR
*/
#include <iostream>
#include <climits>
using namespace std;
long long lowest_div(long long n){
  long long x=2;
  long long z=n-1;
  while(1){
    x=x*2;
    if(z%x==0)
      return x/2;
    z=n-x+1;
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin>>k;
    long long nums[k];
    for(int i=0;i<k;i++) cin>>nums[i];
    if(k%2==0)
      cout<<"0\n";
    else{
      bool cont_even=false;
      for(int i=0;i<k;i++){
	if(nums[i]%2==0){
	  cont_even=true;
	  break;
	}
      }
      if(cont_even)
	cout<<"1\n";
      else{
	long long low_div=1e18;
	for(int i=0;i<k;i++){
	  long long val=lowest_div(nums[i]);
	  if(val<=nums[i])
	    low_div=min(low_div,val);
	}
	if(low_div==1e18)
	  cout<<"-1\n";
	else
	  cout <<low_div<<"\n";
      }
    }
  }
  return 0;
}
