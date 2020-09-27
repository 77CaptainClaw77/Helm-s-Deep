#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  vector<string> answer;
  int n;
  cin>>n;
  vector<string> a(n),b(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cin>>b[i];
  for(int i=0;i<n;i++){
    unordered_set<char> s;
    string res="NO";
    for(int j=0;j<a[i].size();j++)
      s.insert(a[i][j]);
    for(int j=0;j<b[i].size();j++){
      if(s.find(b[i][j])!=s.end()){
	res="YES";
	break;
      }
    }
    answer.push_back(res);
  }
  for(int i=0;i<answer.size();i++)
    cout<<answer[i]<<"\n";
  return 0;
}
