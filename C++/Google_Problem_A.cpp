#include <bits/stdc++.h>
using namespace std;
int min_val=INT_MAX,max_val=INT_MIN;
void check_all_combinations(int& cur_pair_sum,int i,vector<pair<int,int>> arr,int n){
  if(i==n){
    min_val=min(min_val,cur_pair_sum);
    
    return;
  }
  if(arr[i].second)
    check_all_combinations(cur_pair_sum,i+1,arr,n);
  for(int j=i+1;j<n;j++){
    if(arr[j].second) continue;
    arr
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  vector<pair<int,int>> arr(n);
  vector<int> marked(n);
  
  return 0;
}
