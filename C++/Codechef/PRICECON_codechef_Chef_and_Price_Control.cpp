#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T,K,N,loss,temp;
  cin>>T;
  while(T--){
    loss=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      cin>>temp;
      if(temp>K)
	loss+=temp-K;
    }
    cout<<loss<<"\n";
  }
  return 0;
}
