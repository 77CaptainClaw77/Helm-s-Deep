#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int get_max_grid_size(vector<string> vec,int i,int j,int n){
  int t_c=0,b_c=0,r_c=0,l_c=0;
  for(int k=i-1;k>=0;k--){
    if(vec[k][j]=='G') t_c++;
    else break;
  }
  for(int k=i+1;k<n;k++){
    if(vec[k][j]=='G') b_c++;
    else break;
  }
  for(int k=j-1;k>=0;k--){
    if(vec[i][k]=='G') l_c++;
    else break;
  }
  for(int k=j+1;k<vec[0].size();k++){
    if(vec[i][k]=='G') r_c++;
    else break;
  }
  return min(min(t_c,b_c),min(l_c,r_c));
}
void mark_bad(vector<string>& vec,int i,int j,int n,int sz){
  for(int k=1;k<=sz;k++){
    vec[i][j+k]='B';
    vec[i][j-k]='B';
    vec[i-k][j]='B';
    vec[i+k][j]='B';
  }
  vec[i][j]='B';
}
void mark_good(vector<string>& vec,int i,int j,int n,int sz){
  for(int k=1;k<=sz;k++){
    vec[i][j+k]='G';
    vec[i][j-k]='G';
    vec[i-k][j]='G';
    vec[i+k][j]='G';
  }
  vec[i][j]='G';
}
vector<int> find_largest(vector<string>& vec,int n,int m,vector<vector<int>> ign){
  int x=-1,y=-1,max_val=0;
  bool has_g=false;
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      int v=0;
      if(vec[i][j]=='G' && ign[i][j]!=1){
	has_g=true;
  	v=get_max_grid_size(vec,i,j,n);
  	if(v>=max_val){
  	  max_val=v;
	  x=i;
	  y=j;
	}
      }
    }
  }
  vector<int> ans={max_val,x,y};
  return ans;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<string> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  int max_val=0;
  int max_grid_pos[2]={};
  int m_prod,prod;
  vector<vector<int>> ign(n,vector<int>(m));
  while(1){
    vector<int> res=find_largest(vec,n,m,ign);
    if(res[1]==-1 || res[0]==0)
      break;
    int sz=res[0],x=res[1],y=res[2];
    while(sz>0){
      mark_bad(vec,x,y,n,sz);
      vector<int> new_res=find_largest(vec,n,m,ign);
      if(new_res[1]==-1)
    	break;
      int ans=((sz*4)+1)*((new_res[0]*4)+1);
      max_val=max(ans,max_val);
      if(ans==1)
    	break;
      mark_good(vec,x,y,n,sz);
      sz--;
    }
    ign[res[1]][res[2]]=1;
  }
  if(max_val>0)
    cout<<max_val;
  else{
    int g_c=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
	if(vec[i][j]=='G')
	  g_c++;
    if(g_c>=2)
      cout<<1;
    else
      cout<<0;
  }
  return 0;
}
