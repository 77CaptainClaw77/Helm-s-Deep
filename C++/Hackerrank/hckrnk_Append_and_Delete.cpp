#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  string s,t;
  int k;
  string answer;
  cin>>s>>t>>k;
  int move_count,i;
  for(i=0;i<s.size() && i<t.size();i++)
    if(s[i]!=t[i])
      break;
  if(i==s.size())
    move_count=t.size()-i;
  else if(i==t.size())
    move_count=s.size()-i;
  else
    move_count=(t.size()-i)+(s.size()-i);
  if(k==move_count)
    answer="Yes";
  else if(k<move_count)
    answer="No";
  else{
    if((k-move_count)%2==0)
      answer="Yes";
    else if(k-s.size()>=t.size())
      answer="Yes";
    else
      answer="No";
  }
  cout<<answer;
  return 0;
}
