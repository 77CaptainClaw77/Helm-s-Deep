#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N,B,house_count;
    cin>>N>>B;
    house_count=0;
    vector<int> v(N);
    for(int i=0;i<N;i++)
      cin>>v[i];
    sort(v.begin(), v.end());
    for(int e:v){
      B-=e;
      if(B>=0)
	house_count++;
    }
    cout<<"Case #"<<i+1<<": "<<house_count<<"\n";
  }
  return 0;
}
