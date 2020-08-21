#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vector<vector<int>> mat(2*n,vector<int>(2*n));
    vector<vector<int>> maxes(n,vector<int>(n));
    for(int i=0;i<2*n;i++)
      for(int j=0;j<2*n;j++)
	cin>>mat[i][j];
    long long ans=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	int e1=mat[i][j],e2=mat[i][2*n-1-j],e3=mat[2*n-1-i][j],e4=mat[2*n-1-i][2*n-1-j];
	ans+=max(e1,max(e2,max(e3,e4)));
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
