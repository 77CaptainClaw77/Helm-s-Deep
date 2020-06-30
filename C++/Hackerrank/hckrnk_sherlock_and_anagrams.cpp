#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_anagram(string str1,string str2){
  string temp=str2;
  for(char ch:str1){
    for(int i=0;i<str2.size();i++){
      if(str2[i]==ch){
	str2.erase(str2.begin()+i);
	break;
      }
    }
  }
  bool res=str2==""?true:false;
  if(res)
    cout<<endl<<str1<<"\t"<<temp<<"\t"<<str2;
  return res;
}
void sherlock_anagrams(string str){
  int n=str.size();
  int anagram_count=0;
  for(int i=1;i<n;i++){
    vector<string> anagrams;
    for(int j=0;j<i+1;j++){
      string sub=str.substr(j,n-i);
      anagrams.push_back(sub);
    }
    int m=anagrams.size();
    for(int j=0;j<m-1;j++){
      for(int k=j+1;k<m;k++){
	bool res=is_anagram(anagrams[j],anagrams[k]);
	anagram_count=res?anagram_count+1:anagram_count;
      }
    }
  }
  cout<<anagram_count<<endl;
}
int main(int argc, char *argv[]){
  //bool a=is_anagram("iluhkqq","luhkqqh");	
  int q;
  cin>>q;
  for (int i=0; i<q; i++) {
    string str;
    cin>>str;
    sherlock_anagrams(str);
  }
  return 0;
}
