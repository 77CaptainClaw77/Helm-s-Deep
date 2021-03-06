#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int magic_square[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
	  magic_square[i][j]=0;
    int magic_num=(n*(n*n+1))/2;
    int p_x=n/2,p_y=n-1;
    for(int i=0;i<n*n;i++){
        if(!magic_square[p_x][p_y]){
            magic_square[p_x][p_y]=i+1;
            p_x--;
            p_y++;
	    if(p_x==-1 && p_y==n){
	      p_x=0;
	      p_y=n-2;
	    }
	    else{
	      p_y=p_y%n;
	      if(p_x<0) 
                p_x=n-1;
	    }
        }
        else{
            p_x=(p_x+1)%n;
            p_y-=2;
            if(p_y<0)
                p_y=n-p_y;
            i--; //adjust for not entering value;
        }
	cout<<p_x<<" "<<p_y<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<magic_square[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
