#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  string bs;
  cin>>bs;
  if(bs.find("1")==string::npos)
    cout<<"-1";
  else if(bs.find("0")==string::npos)
    cout<<"0";
  else{
    int mtwopow=0,twopow=0;
    for(int i=0;i<bs.size();i++){
      if(bs[i]=='0'){
	twopow=1;
	int l=i==0?bs.size()-1:i-1;
	int r=i+1;
	while(r<bs.size() && bs[r]=='0'){
	  r++;
	  twopow++;
	}
	while(bs[l]=='0'){
	  l=l==0?bs.size()-1:l-1;
	  twopow++;
	}
	i=r;
      }
      mtwopow=max(mtwopow,twopow);
    }
    cout<<mtwopow;
  }
  return 0;
}
