#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    int p_count=0;
    for(int i=0;i<s.size()-1;i++){
      if(s[i]!=s[i+1]){
	p_count++;
	i++;
      }
    }
    cout<<p_count<<"\n";
  }
  return 0;
}
