#include <bits/stdc++.h>
using namespace std;
vector<int> sort_intersect(vector<int> volcanic,vector<int> nonvolcanic){
  vector<int> answer;
  multiset<int> ms;
  int vcount=volcanic.size(),nvcount=nonvolcanic.size();
  for(int i=0;i<vcount;i++)
    ms.insert(volcanic[i]);
  for(int i=0;i<nvcount;i++){
    int temp=nonvolcanic[i];
    multiset<int>::iterator it=ms.find(temp);
    if(it!=ms.end()){
      answer.push_back(temp);
      ms.erase(it);
    }
  }
  sort(answer.begin(),answer.end(),greater<>());
  return answer;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int temp;
  multiset<int> ms;
  int vcount,nvcount;
  //vector<int> answer;
  cin>>vcount;
  vector<int> v(vcount);
  for(int i=0;i<vcount;i++)
    cin>>v[i];
  cin>>nvcount;
  vector<int> nv(nvcount);
  for(int i=0;i<nvcount;i++)
    cin>>nv[i];
  vector<int> answer=sort_intersect(v,nv);
  for(int i=0;i<answer.size();i++)
     cout<<answer[i]<<"\n";  
  // for(int i=0;i<vcount;i++){
  //   cin>>temp;
  //   ms.insert(temp);
  // }
  // cin>>nvcount;
  // for(int i=0;i<nvcount;i++){
  //   cin>>temp;
  //   multiset<int>::iterator it=ms.find(temp);
  //   if(it!=ms.end()){
  //     answer.push_back(temp);
  //     ms.erase(it);
  //   }
  // }
  // sort(answer.begin(),answer.end());
  // for(int i=answer.size()-1;i>=0;i--)
  //   cout<<answer[i]<<"\n";
  return 0;
}

//
