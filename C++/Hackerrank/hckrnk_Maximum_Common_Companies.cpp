// TODO: Does not work when a node has outdegree higher than 1, use map<pair<int,int>,vector<int>>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> v1,vector<int> v2,vector<int> v3){
  map<pair<int,int>,int> m;
  for(int i=0;i<v1.size();i++)
    m[make_pair(v1[i],v3[i])]=v2[i];
  map<pair<int,int>,int>::iterator it=m.begin();
  int max_prod=0;
  while(it!=m.end()){
    int prod=1;
    prod=prod*(it->first).first;
    int col=(it->first).second;
    int fele=it->second;
    while(m.find(make_pair(fele,col))!=m.end()){
      prod=prod*(fele);
      fele=m[make_pair(fele,col)];
    }
    prod=prod*fele;
    max_prod=max(prod,max_prod);
    it++;
  }
  cout<<max_prod;
}
int main(int argc, char *argv[])
{
  int n;
  cin>>n;
  vector<int> v1(n),v2(n),v3(n);
  for(int i=0;i<n;i++)
    cin>>v1[i];
  for(int i=0;i<n;i++)
    cin>>v2[i];
  for(int i=0;i<n;i++)
    cin>>v3[i];
  solve(v1,v2,v3);
  return 0;
}
