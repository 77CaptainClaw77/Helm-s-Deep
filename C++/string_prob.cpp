#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  char ch;
  cin>>ch;
  string line;
  map<int,set<pair<string,int>>> students;
  for(int i=0;i<n;i++){
    getline(cin,line);
    int c1=line.find(',');
    string name=line.substr(0,c1);
    int c2=line.find(c1+1,',');
    int roll_no=stoi(line.substr(c1+2,c2-c1-2));
    int marks=line.substr(c2+2);
  }
  vector<pair<int,string>> answer;
  map<int,set<pair<string,int>>>::iterator iter=students.begin();
  while(iter!=students.end()){
    set<pair<string,int>>::iterator it=(iter->second).begin();
    while(it!=(iter->second).end()){
      answer.push_back((*it).first);
      it++;
    }
    iter++;
  }
  return 0;
}
