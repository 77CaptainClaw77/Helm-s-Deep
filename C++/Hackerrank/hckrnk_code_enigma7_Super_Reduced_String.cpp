#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  cin>>s;
  string sr="";
  int cnt=0;
  do{
    cnt=0;
    sr="";
    for(int i=0;i<s.size();i++){
      if(i==s.size()-1)
	sr=sr+s[i];
      else{
	if(s[i]==s[i+1]){
	  i++;
	  cnt++;
	}
	else
	  sr+=s[i];
      }
    }
    s=sr;
  }while(cnt>0);
  if(sr.empty())
    cout<<"Empty String";
  else
    cout<<sr;
  return 0;
}
