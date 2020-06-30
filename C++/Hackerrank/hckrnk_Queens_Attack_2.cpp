#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
int main(int argc, char *argv[]) //1-indexing
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,k,r_q,c_q;
  cin>>n>>k>>r_q>>c_q;
  int obs[k][2];
  for(int i=0;i<k;i++)
    cin>>obs[i][0]>>obs[i][1];
  long move_count=0;
  int closest_t=0,closest_b=n+1,closest_l=0,closest_r=n+1,closest_tr=n,closest_tl=n,closest_bl=n,closest_br=n;
  for(int i=0;i<k;i++){
    int r=obs[i][0],c=obs[i][1];
    if(r==r_q){ //same row
      if(c>c_q){ //right of queen
	closest_r=min(closest_r,c);
      }
      else{ //left of queen
	closest_l=max(closest_l,c);
      }
    }
    else if(c==c_q){ //same col
      if(r>r_q){ //bottom of queen
	closest_b=min(r,closest_b);
      }
      else{ //top of queen
	closest_t=max(r,closest_t);
      }
    }
    else if(abs(r-r_q)==abs(c-c_q)){ //one of 4 diagonals
      if(r-r_q<0){ // first 2 quadrants
	if(c>c_q){ //first_quad
	  closest_tr=min(closest_tr,c-c_q);
	}
	else{ //second_quad
	  closest_tl=min(closest_tl,c_q-c);
	}
      }
      else{ //last 2 quadrants
	if(c>c_q){
	  closest_br=min(closest_br,c-c_q); //4th quadrant
	}
	else{
	  closest_bl=min(closest_bl,c_q-c); //3rd quadrant
	}
      }
    }
    else{ //Different position, do not count
      continue;
    }
  }
  int top_moves=r_q>1?r_q-closest_t-1:0;
  int bottom_moves=r_q<n?closest_b-r_q-1:0;
  int left_moves=c_q>1?c_q-closest_l-1:0;
  int right_moves=c_q<n?closest_r-c_q-1:0;
  int quad_1_moves=closest_tr==n?min(r_q-1,n-c_q):closest_tr-1;
  int quad_2_moves=closest_tl==n?min(r_q-1,c_q-1):closest_tl-1;
  int quad_3_moves=closest_bl==n?min(n-r_q,c_q-1):closest_bl-1;
  int quad_4_moves=closest_br==n?min(n-r_q,n-c_q):closest_br-1;
  move_count=top_moves+bottom_moves+left_moves+right_moves+quad_1_moves+quad_2_moves+quad_3_moves+quad_4_moves;
  cout<<move_count;
  return 0;
}
