#include <iostream>
#include <string>
using namespace std;
string gen_next(string str){
  int k=-1;
  for(int i=0;i<str.size()-1;i++){
    if(str[i]<str[i+1])
      k=i;
  }
  if(k==-1)
    return "no answer";
  int l=k+1;
  for(int i=k+2;i<str.size();i++){
    if(str[k]<str[i])
      l=i;
  }
  char c=str[k];
  str[k]=str[l];
  str[l]=c;
  int n=str.size();
  int rev_start=k+1;
  for(int i=0;i<(n-rev_start)/2;i++){
    c=str[i+rev_start];
    str[i+rev_start]=str[n-1-i];
    str[n-1-i]=c;
  }
  return str;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  string str;
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>str;
    cout<<gen_next(str)<<"\n";
  }
  return 0;
}
