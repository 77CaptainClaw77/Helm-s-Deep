#include<bits/stdc++.h>

using namespace std;

void update_map(map<int,pair<int,int>>& m,string str,string pattern,int pos){
  map<int,pair<int,int>>::iterator iter;
  for(iter=m.begin();iter!=m.end();iter++){
    if((iter->second).first<pattern.size() && pattern[(iter->second).first]==str[pos])
      (iter->second).first=(iter->second).first+1;
    else
      (iter->second).second=(iter->second).second+1;
  }
}
int find_map_min(map<int,pair<int,int>>& m,int sz){
  map<int,pair<int,int>>::iterator iter;
  int min_val=INT_MAX;
  for(iter=m.begin();iter!=m.end();iter++){
    if((iter->second).first==sz)
      min_val=min(min_val,(iter->second).second);
  }
  return min_val;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str,pattern;
        cin>>str>>pattern;
        size_t match_ind=0,del_count=0;
	map<int,pair<int,int>> m;
        for(size_t i=0;i<str.size();i++){
	  update_map(m,str,pattern,i);
	  if(pattern[0]==str[i])
	    m[i]=make_pair(1,0);
        }
	int res=find_map_min(m,pattern.size());
        if(res!=INT_MAX)
            cout<<"YES "<<res<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
