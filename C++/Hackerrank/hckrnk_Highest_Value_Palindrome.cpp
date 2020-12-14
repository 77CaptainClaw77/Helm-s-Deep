#include <bits/stdc++.h>
using namespace std;
void make_palindrome(string& str){
  int n=str.size();
  for(int i=0;i<n/2;i++){
    if(str[i]!=str[n-1-i]){
      if(str[i]>str[n-1-i])
	str[n-1-i]=str[i];
      else
	str[i]=str[n-1-i];
    }
  }
}
int main(int argc, char *argv[])
{
  int n,k;
  string str;
  cin>>n>>k;
  cin>>str;
  int ch_req=0;
  for(int i=0;i<n/2;i++)
    if(str[i]!=str[n-1-i])
      ch_req++;
  if(k<ch_req)
    cout<<"-1";
  else{
    int l_pos=0;
    while(k>ch_req){
      if(k==1 && ch_req==0)
	break;
      while((str[l_pos]=='9' || str[n-1-l_pos]=='9') && l_pos<n/2)
	l_pos++;
      if(k==ch_req+1 && str[l_pos]==str[n-1-l_pos]){
	l_pos++; // if this change is made at l_pos then k becomes less than ch_req, so this change can only be done where they are inequal so ch_req is decremented.
	continue;
      }
      if(l_pos>=n/2)
	break;
      if(ch_req>0 && str[l_pos]!=str[n-1-l_pos])
	ch_req--;
      str[l_pos]='9';
      str[n-1-l_pos]='9';
      k=k-2;
    }
    if(k-ch_req>0 && n%2!=0)
      str[n/2]='9';
    make_palindrome(str);
    cout<<str;
  }
  return 0;
}
