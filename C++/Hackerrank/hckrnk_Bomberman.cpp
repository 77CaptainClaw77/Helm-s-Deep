#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print_grid(vector<string> grid){
  for(int i=0;i<grid.size();i++)
    cout<<grid[i]<<"\n";
}
void place(vector<string>& grid,char bomb_type){ //place the bombs of specific type
  for(int i=0;i<grid.size();i++)
      for(int j=0;j<grid[i].size();j++)
	grid[i][j]=grid[i][j]=='.'?bomb_type:grid[i][j];
}
char detonate_square(char ch,char bt){
  return ch!=bt?'.':bt;
}
void detonate(vector<string>& grid,char bomb_type){ //detonate the bomb of specific type
  for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
      if(grid[i][j]==bomb_type){
	if(i>0)
	  grid[i-1][j]=detonate_square(grid[i-1][j],bomb_type);
	if(i<grid.size()-1)
	  grid[i+1][j]=detonate_square(grid[i+1][j],bomb_type);
	if(j>0)
	  grid[i][j-1]=detonate_square(grid[i][j-1],bomb_type);
	if(j<grid[0].size()-1)
	  grid[i][j+1]=detonate_square(grid[i][j+1],bomb_type);
	grid[i][j]='.';
      }
    }
  }
}
void transform_grid(vector<string>& grid,bool type){ //  if true then transform for processing, else for output
  if(type){
    for(int i=0;i<grid.size();i++)
      for(int j=0;j<grid[i].size();j++)
	grid[i][j]=grid[i][j]=='O'?'p':'.';
  }
  else{
     for(int i=0;i<grid.size();i++)
      for(int j=0;j<grid[i].size();j++)
	grid[i][j]=grid[i][j]=='.'?'.':'O';
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int r,c,n;
  cin>>r>>c>>n;
  vector<string> grid(r);
  //vector<vector<string>> states;
  string row;
  for(int i=0;i<r;i++){
    cin>>row;
    grid[i]=row;
  }
  if(n<2)
    print_grid(grid);
  else{
    transform_grid(grid,true);
   if(n%2==0)
     place(grid,'q');
   else if((n+1)%4==0){
     place(grid,'q');
     detonate(grid,'p');
   }
   else{
     place(grid,'q');
     detonate(grid,'p');
     place(grid,'p');
     detonate(grid,'q');
   }
   transform_grid(grid,false);
   print_grid(grid);
  } 
  return 0;
}
