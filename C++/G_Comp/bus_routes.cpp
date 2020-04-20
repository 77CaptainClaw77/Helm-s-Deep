#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N,D;
    cin>>N>>D;
    int max_day=0,max_diff=0,max_ind=0;
    vector<int> vec(N);
    for(int j=0;j<N;j++){
      cin>>vec[j];
      int val=D%vec[j];
      if(val>max_day){
	max_day=val;
	max_ind=j;
      }
    }
    max_day=D-max_day;
    for(int j=0;j<max_ind;j++)
      max_diff=max(max_diff,max_day%vec[j]);
    cout<<"Case #"<<(i+1)<<": "<<max_day-max_diff<<endl;
  }
  return 0;
}
