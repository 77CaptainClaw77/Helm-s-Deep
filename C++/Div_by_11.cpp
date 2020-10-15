#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
  string num;
  cin>>num;
  //for corner cases ignore trailing 0s
  //for(int i=0;i<num.size() && num[i]=='0';i++);
  //num=num.substr(i,num.size());
  int s=0,cnt=0,n=num.size();
  for(int i=0;i<n;i++){
    s=0;
    bool p=true;
    for(int j=i;j<n;j++){
      int t=num[j]-'0';
      s+=(p?t:-t);
      p=!p;
      cnt=(s==0?cnt+1:cnt);
    }
  }
  cout<<cnt;
  return 0;
}
