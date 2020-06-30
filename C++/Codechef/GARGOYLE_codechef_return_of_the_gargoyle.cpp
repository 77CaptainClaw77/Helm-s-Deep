#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
  int n,m_val,count;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  string str;
  getline(cin,str);
  getline(cin,str);
  map<string,int> m;
  m_val=0;
  for(int i=0;i<n;i++){
    getline(cin,str);
    if(m.find(str)==m.end())
      m[str]=1;
    else
      m[str]++;
    if(i!=n-1)
      getline(cin,str);
  }
  map<string,int>::iterator it=m.begin();
  while(it!=m.end()){
    str=it->first;
    count=it->second;
    int actual=0;
    for(int i=0;i<str.size();i++)
      if(str[i]=='T')
	actual++;
    if(actual==count)
      m_val=max(m_val,actual);
    it++;
  }
  cout<<m_val;
  return 0;
}
