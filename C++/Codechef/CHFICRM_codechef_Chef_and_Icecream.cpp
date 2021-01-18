/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Chef owns an icecream shop in Chefland named scoORZ. There are only three types of coins in Chefland: Rs. 5, Rs. 10 and Rs. 15. An icecream costs Rs. 5.
There are NNN people (numbered 111 through NNN) standing in a queue to buy icecream from scoORZ. Each person wants to buy exactly one icecream. For each valid iii, the iii-th person has one coin with value aiaia_i. It is only possible for someone to buy an icecream when Chef can give them back their change exactly ― for example, if someone pays with a Rs. 10 coin, Chef needs to have a Rs. 5 coin that he gives to this person as change.
Initially, Chef has no money. He wants to know if he can sell icecream to everyone in the queue, in the given order. Since he is busy eating his own icecream, can you tell him if he can serve all these people?
Link: https://www.codechef.com/problems/O
*/
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
