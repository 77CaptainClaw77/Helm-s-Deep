#include <bits/stdc++.h>
using namespace std;
long long get_sum(priority_queue<long long> pq){
  long long sum=0;
  while(!pq.empty()){
    sum+=pq.top();
    pq.pop();
  }
  return sum;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  priority_queue<long long> pq;
  int N,K;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    long long temp;
    cin>>temp;
    pq.push(temp);
  }
  for(int i=0;i<K;i++){
    long long ele=pq.top();
    if(ele==0) break;
    pq.pop();
    pq.push(ele/2);
  }
  cout<<get_sum(pq);
  return 0;
}
