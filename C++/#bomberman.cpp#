#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
void detonate(vector<vector<char>> &g,int r,int c,char type){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(g[i][j]==type){
                g[i][j]='r';
                if(i!=0)
                    g[i-1][j]=g[i-1][j]!=type?'r':type;
                if(j!=0)
                    g[i][j-1]=g[i][j-1]!=type?'r':type;
                if(i!=r-1)
                    g[i+1][j]=g[i+1][j]!=type?'r':type;
                if(j!=c-1)
                    g[i][j+1]=g[i][j+1]!=type?'r':type;
            }
        }  
    }    
}
void place(vector<vector<char>> &g,int r,int c,int type){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            g[i][j]=g[i][j]=='r'?type:g[i][j];
}
vector<string> bomberMan(int n, vector<string> grid) {
int r=grid.size(),c=grid[0].size();
vector<vector<char>> g(r,vector<char> (c));
for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
        g[i][j]=grid[i][j]=='.'?'r':'p';
for(int i=2;i<=n;i++){
    if(i%2==0){
        if(i%4==0)
            place(g,r,c,'p');
        else
            place(g,r,c,'q');
    }
    else{
      if((i+1)%4==0)
	  detonate(g,r,c,'p');
        else
            detonate(g,r,c,'q');
    }
}
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            grid[i][j]=g[i][j]=='r'?'.':'O';
    return grid;

}
int main(){
  vector<string> grid={".......","...O.O.","....O..","..O....","OO...OO","OO.O..."};
  bomberMan(5,grid);
  return 0;
}
