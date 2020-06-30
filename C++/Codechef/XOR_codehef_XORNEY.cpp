#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
  long long L,R,T,total,o_c;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  while(T--){
    cin>>L>>R;
    total=R-L;
    if(L%2!=0 && R%2!=0)
      o_c=(total/2)+1;
    else
      o_c=(total+1)/2;
    if(o_c%2==0)
      cout<<"Even\n";
    else
      cout<<"Odd\n";
  }
  return 0;
}
