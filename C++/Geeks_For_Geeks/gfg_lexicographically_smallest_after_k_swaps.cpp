#include <bits/stdc++.h>
using namespace std;
void make_swap(int i,int s,string& str){
  char sw=str[s];
  for(int j=s;j>i;j--)
    str[j]=str[j-1];
  str[i]=sw;
}
int main(int argc, char *argv[])
{
  // cin.tie(0);
  // ios::sync_with_stdio(0);
  string str;
  int K;
  cin>>str>>K;
  int smallest=0;
  //Greedy Approach
  for(int i=0;i<str.size();i++){
    smallest=i;
    for(int j=0;j<K;j++){
      if(i+j+1>=str.size()) break;
      if(str[i+j+1]<str[i])
	smallest=str[i+1+j]<str[smallest]?(i+j+1):smallest;
    }
    if(smallest!=i){
      make_swap(i,smallest,str);
      K-=smallest-i;
    }
  }
  cout<<str;
  return 0;
}
