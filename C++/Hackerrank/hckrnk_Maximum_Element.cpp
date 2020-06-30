#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  stack<pair<int,int>> max_stck;
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int type;
    cin>>type;
    if(type==1){
      int ele;
      cin>>ele;
      if(max_stck.empty())
	max_stck.push(make_pair(ele,ele));
      else
	max_stck.push(make_pair(ele,max((max_stck.top()).second,ele)));
    }
    else if(type==2){
      if(!max_stck.empty())
	max_stck.pop();
    }
    else{
      cout<<(max_stck.top()).second<<"\n";
    }
  }
  return 0;
}
