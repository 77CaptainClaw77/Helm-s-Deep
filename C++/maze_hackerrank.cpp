//#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            v[i].push_back(temp);
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int cur_dir=0; //0 = right  1 = up 2 = down 3=left
    int pos_x=0,pos_y=0;
    bool in_maze=true;
    while(in_maze){
      if(v[pos_x][pos_y]==1){
            if(cur_dir==0) cur_dir=2;
            if(cur_dir==1) cur_dir=0;
            if(cur_dir==2) cur_dir=3;
            if(cur_dir==3) cur_dir=1;
            v[pos_x][pos_y]=0;
        }
        int p_x=pos_x,p_y=pos_y;
        if(cur_dir==0) p_y+=1;
        if(cur_dir==1) p_x-=1;
        if(cur_dir==2) p_x+=1;
        if(cur_dir==3) p_y-=1;
        if(p_x<0 || p_x==m || p_y==n ||p_y<0){
            in_maze=false;
            cout<<cur_dir<<endl;
            break;
        }
        pos_x=p_x;
        pos_y=p_y;
    }
    cout<<pos_x<<" "<<pos_y;
    return 0;
    
}
