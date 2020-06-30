#include <iostream>
#include <cstdlib>
using namespace std;
void forest_fire(char** grid,int pos_x,int pos_y,int t,int& max_t,int m,int n){
  if(pos_x<0 || pos_x==n || pos_y<0 || pos_y==m)
    return;
  if(grid[pos_x][pos_y]=='T'){
    grid[pos_x][pos_y]='F';
    t++;
    if(t>max_t) max_t=t;
    forest_fire(grid,pos_x+1,pos_y,t,max_t,m,n);
    forest_fire(grid,pos_x-1,pos_y,t,max_t,m,n);
    forest_fire(grid,pos_x,pos_y+1,t,max_t,m,n);
    forest_fire(grid,pos_x,pos_y-1,t,max_t,m,n);
    forest_fire(grid,pos_x+1,pos_y+1,t,max_t,m,n);
    forest_fire(grid,pos_x+1,pos_y-1,t,max_t,m,n);
    forest_fire(grid,pos_x-1,pos_y+1,t,max_t,m,n);
    forest_fire(grid,pos_x-1,pos_y-1,t,max_t,m,n);
  }
  return;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    char** grid=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
      grid[i]=(char*)malloc(sizeof(char)*m);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
	cin>>grid[i][j];
    int x,y;
    cin>>x>>y;
    int time_taken=0;
    forest_fire(grid,x-1,y-1,0,time_taken,m,n);
    cout<<"Time taken: "<<time_taken<<endl;
  }
  return 0;
}
