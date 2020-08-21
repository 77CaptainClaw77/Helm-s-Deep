#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int n,c,m;
    cin>>n>>c>>m;
    int wrapper_count=n/c,count=n/c;
    while(wrapper_count>=m){
      int new_c=wrapper_count/m;
      count+=new_c;
      wrapper_count=wrapper_count%m;
      wrapper_count+=new_c;
    }
    cout<<count<<"\n";
  }
  return 0;
}
