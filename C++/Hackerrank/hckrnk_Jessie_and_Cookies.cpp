#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  int N,K;
  cin>>N>>K;
  int temp;
  priority_queue<long,vector<long>,greater<int>> pq;
  for(int i=0;i<N;i++){
    cin>>temp;
    pq.push(temp);
  }
  int op=0;
  while(pq.size()>1 && pq.top()<K){
    op++;
    int v1=pq.top();
    pq.pop();
    int v2=pq.top();
    pq.pop();
    pq.push(v1+2*v2);
  }
  if(pq.size()<=1){
    if(pq.size()<1 || pq.top()<K)
      cout<<"-1\n";
    else
      cout<<op<<"\n";
  }
  else
    cout<<op<<"\n";
  return 0;
}
