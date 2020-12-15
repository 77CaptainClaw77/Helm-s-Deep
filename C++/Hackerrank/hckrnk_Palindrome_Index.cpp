#include <bits/stdc++.h>
using namespace std;
int is_palindrome(string s){ //if s is a palindrome returns -1 else returns index at which not equal
  for(int i=0;i<s.size()/2;i++){//i=0...n/2
    if(s[i]!=s[s.size()-1-i])//i!=n-1-i
      return i;
  }
  return -1;
}
int main(int argc, char *argv[])
{
  int q;
  cin>>q; //no of queries
  while(q--){
    string s;
    cin>>s; //string input
    int r=is_palindrome(s); // if r is -1 then already palindrome
    if(r==-1)
      cout<<-1;
    else{
      string p=s.substr(0,r)+s.substr(r+1);// copy s to p by deleting ith character
      string q=s.substr(0,s.size()-1-r)+s.substr(s.size()-r);// copy s to q by deleting n-1-ith character
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
