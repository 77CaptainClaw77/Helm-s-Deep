#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T,N;
  cin>>T;
  while(T--){
    bool possible=true;
    cin>>N;
    int f_count=0,t_count=0,temp=0;
    for(int i=0;i<N;i++){
      cin>>temp;
      if(possible){
	if(temp==5){
	  f_count++;
	  continue;
	}
	else if(temp==10){
	  if(f_count==0)
	    possible=false;
	  else{
	    f_count--;
	    t_count++;
	  }
	}
	else{
	  if(t_count==0){
	    if(f_count<2){
	      possible=false;
	    }
	    f_count-=2;
	  }
	  else
	    t_count--;
	}
      }
    }
    if(possible)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
