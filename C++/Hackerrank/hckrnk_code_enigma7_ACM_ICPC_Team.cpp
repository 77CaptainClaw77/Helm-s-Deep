#include <iostream>
#include <utility>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  int ans_count=0;
  cin>>n>>m;
  string temp;
  bool btset[n][m];
  int count[n]={};
  for(int i=0;i<n;i++){
    cin>>temp;
    for(int j=0;j<m;j++){
      if(temp[j]=='0')
	btset[i][j]=false;
      else{
	btset[i][j]=true;
	count[i]++;
      }
    }
  }
  int max_bt_cnt=0,bt_cnt=0;
  map<pair<int,int>,int> mp;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      for(int k=0;k<m;k++)
	if(btset[i][k]==true || btset[j][k]==true)
	  bt_cnt++;
      if(bt_cnt>max_bt_cnt)
	max_bt_cnt=bt_cnt;
      mp[make_pair(i,j)]=bt_cnt;
      bt_cnt=0;
    }
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(max_bt_cnt==mp[make_pair(i,j)])
	ans_count++;
    }
  }
  cout<<max_bt_cnt<<"\n"<<ans_count;
  return 0;
}
