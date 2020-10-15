#include <iostream>
using namespace std;
int main()
{
  int tcases;
  cin>>tcases;
  while(tcases--){
    long long r[3],v[3],n;
    for(int i=0;i<3;i++)
      cin>>r[i];
    for(int i=0;i<3;i++)
      cin>>v[i];
    cin>>n;
    int ans1=(v[0]*n)%360;
    int ans2=(v[1]*n)%360;
    int ans3=(v[2]*n)%360;
    if(ans1==ans2 && ans2==ans3)
      cout<<"TRUE\n";
    else
      cout<<"FALSE\n";
  }
  return 0;
}
