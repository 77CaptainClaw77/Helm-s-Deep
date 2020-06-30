#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(int argc, char *argv[])
{
  int T,temp;
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>T;
  int N,Z;
  while(T--){
    cin>>N>>Z;
    priority_queue<int> pq;
    for(int i=0;i<N;i++){
      cin>>temp;
      pq.push(temp);
    }
    int attacks=0;
    while(Z>0){
      if(pq.empty())
	break;
      int ele=pq.top();
      if(ele==0)
	break;
      Z-=ele;
      attacks++;
      pq.pop();
      pq.push(ele/2);
    }
    if(Z>0)
      cout<<"Evacuate\n";
    else
      cout<<attacks<<"\n";
  }
  return 0;
}
