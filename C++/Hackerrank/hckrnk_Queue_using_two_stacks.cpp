#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> newest_on_top,oldest_on_top;
  int q,type;
  cin>>q;
  while(q--){
    cin>>type;
    if(type==1){
      int push_val;
      cin>>push_val;
      newest_on_top.push(push_val);
    }
    else{
      if(oldest_on_top.empty()){
	while(!newest_on_top.empty()){
	  int ele=newest_on_top.top();
	  oldest_on_top.push(ele);
	  newest_on_top.pop();
	}
      }
      if(type==2)
	oldest_on_top.pop();
      else
	cout<<oldest_on_top.top()<<endl;
    }
  }
  return 0;
}
