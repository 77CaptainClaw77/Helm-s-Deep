#include <iostream>
#include <vector>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
  vector<int> prefix(nums.size()+1);
  for(int i=1;i<nums.size()+1;i++)
    prefix[i]+=nums[i-1]+prefix[i-1];
  int eq_count=0;
  for(int i=1;i<prefix.size();i++){
    for(int j=i;j<prefix.size();j++){
      if(prefix[j]-prefix[i-1]==k)
	eq_count++;
    }
  }
  return eq_count;
}
int main(int argc,char* argv[]){
  vector<int> vals={1,1,1};
  cout<<subarraySum(vals,2);
  return 0;
}
