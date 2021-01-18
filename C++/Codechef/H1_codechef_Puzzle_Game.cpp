/*File Information:-
Author: Kumarguru V

Johnny has some difficulty memorizing the small prime numbers. So, his computer science teacher has asked him to play with the following puzzle game frequently.
The puzzle is a 3x3 board consisting of numbers from 1 to 9. The objective of the puzzle is to swap the tiles until the following final state is reached:
1 2 3
4 5 6
7 8 9

At each step, Johnny may swap two adjacent tiles if their sum is a prime number. Two tiles are considered adjacent if they have a common edge.
Help Johnny to find the shortest number of steps needed to reach the goal state.
Link: https://www.codechef.com/problems/H1
*/
#include <bits/stdc++.h>
using namespace std;
long long tenpow[]={(long long)1,(long long)1E1,(long long)1E2,(long long)1E3,(long long)1E4,(long long)1E5,(long long)1E6,(long long)1E7,(long long)1E8,(long long)1E9,(long long)1E10};

int is_prime(int n){
  if(n==3 || n==5 || n==7 || n==11 || n==13 || n==17)
    return 1;
  return 0;
}

inline int get_pos(int x,int y) //grid coordinates to number position
{
  return 3*x+y;
}

inline int get_num(int num,int pos){
  int n=num%tenpow[9-pos];
  return n/tenpow[8-pos];
}
int set_num(int num,int pos,int nn){
  int n=num;
  int i=num%tenpow[8-pos];
  int j=num/tenpow[8-pos];
  j=(j/10)*10+nn;
  j=j*tenpow[8-pos]+i;
  return j;
}

int swap_num(int num,int p1,int p2){
  int s1=get_num(num,p1);
  int s2=get_num(num,p2);
  num=set_num(num,p1,s2);
  num=set_num(num,p2,s1);
  return num;
}

void solve(vector<int>& testcases,unordered_map<int,int>& reachable,unordered_map<int,int>& steps){
  int start_state=123456789;
  reachable[start_state]=1;
  steps[start_state]=1;
  queue<pair<int,int>> state_q;
  state_q.push(make_pair(start_state,0));
  while(!state_q.empty()){
    pair<int,int> cur=state_q.front();
    state_q.pop();
    steps[cur.first]=cur.second;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	for(int k=0;k<2;k++){
	  int ni=i+k;
	  int nj=j+1-k;
	  if(ni>=3 || nj>=3)
	    continue;
	  int pos1=get_pos(i,j),pos2=get_pos(ni,nj);
	  if(!is_prime(get_num(cur.first,pos1)+get_num(cur.first,pos2)))
	    continue;
	  int newstate=swap_num(cur.first,pos1,pos2);
	  if(reachable.find(newstate)!=reachable.end())
	    continue;
	  reachable[newstate]=1;
	  state_q.push(make_pair(newstate,cur.second+1));
	}
      }
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  unordered_map<int,int> reachable,steps;
  vector<int> testcases;
  while(t--){
    int tcase=0,dig=0;
    for(int i=0;i<9;i++){
      cin>>dig;
      tcase=tcase*10+dig;
    }
    testcases.push_back(tcase);
    steps[tcase]=-1;
  }
  solve(testcases,reachable,steps);
  for(int t:testcases)
    cout<<steps[t]<<endl;
  return 0;
}
