#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool present_at(int x,int y,vector<string> grid,vector<string> pattern){
  for(int i=0;i<pattern.size();i++){
    for(int j=0;j<pattern[0].size();j++){
      if(grid[x+i][y+j]!=pattern[i][j])
	return false;
    }
  }
  return true;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int r,c;
    string temp;
    cin>>r>>c;
    vector<string> grid,pattern;
    for(int i=0;i<r;i++){
      cin>>temp;
      grid.push_back(temp);
    }
    cin>>r>>c;
    for(int i=0;i<r;i++){
      cin>>temp;
      pattern.push_back(temp);
    }
    bool done=false;
    for(int i=0;i<grid.size()-pattern.size()+1;i++){
      int pos=0,start=0;
      while(1){
	pos=grid[i].find(pattern[0],start);
	if(pos>grid[0].size()-pattern[0].size())
	  break;
	if(pos==string::npos){
	  break;
	}
	else{
	  if(present_at(i,pos,grid,pattern)){
	    done=true;
	    break;
	  }
	  start=grid[i].find(pattern[0],start+1);
	  if(start==-1)
	    break;
	}
      }
      if(done) break;
    }
    if(done)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
