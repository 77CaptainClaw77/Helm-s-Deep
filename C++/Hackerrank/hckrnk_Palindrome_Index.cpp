#include <bits/stdc++.h>
using namespace std;
int is_palindrome(string s){
  for(int i=0;i<s.size()/2;i++){
    if(s[i]!=s[s.size()-1-i])
      return i;
  }
  return -1;
}
int main(int argc, char *argv[])
{
  int q;
  cin>>q;
  while(q--){
    string s;
    cin>>s;
    int r=is_palindrome(s);
    if(r==-1)
      cout<<-1;
    else{
      string p=s.substr(0,r)+s.substr(r+1);
      string q=s.substr(0,s.size()-1-r)+s.substr(s.size()-r);
      //cout<<s<<" "<<r<<" "<<p<<" "<<q<<"\n";
      if(is_palindrome(p)==-1)
	cout<<r;
      else if(is_palindrome(q)==-1)
	cout<<s.size()-r-1;
      else
	cout<<-1;
    }
    cout<<"\n";
  }
  return 0;
}
