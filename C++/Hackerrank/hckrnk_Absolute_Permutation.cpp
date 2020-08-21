#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    if(k==0){
      for(int i=1;i<=n;i++){
	cout<<i<<" ";
      }
      cout<<"\n";
      continue;
    }
    if(n%k!=0 || (n/k)%2!=0)
      cout<<-1<<"\n";
    else{
      int par=1;
      for(int i=1;i<=n;i++){
	cout<<(i+(par*k))<<" ";
	if(i%k==0)
	  par=-par;
      }
      cout<<"\n";
    }
  }
  return 0;
}
