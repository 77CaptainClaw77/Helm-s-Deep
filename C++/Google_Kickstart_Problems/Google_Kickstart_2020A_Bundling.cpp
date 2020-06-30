//This problem involves the use of a data structure called trie. This is used to reduce the memory required by the program.
//A trie although a type of tree can also be implemented as a 2-dimensional array with each row being a new node and each column containing address of next child.
//It would look something like this:-  int trie[no_of_nodes][no_of_children_per_node];
#include <iostream>
#include <string>
using namespace std;
struct node{
  node* children[26];
  int cnt=0; //used to count number of strings sharing common prefix
};
void insert(node* root,string str){ //simple insertion into trie
  node* temp=root;
  for(char ch:str){
    char c=ch-'A';
    if(temp->children[c]==NULL)
      temp->children[c]=new node();
    temp=temp->children[c];
  }
  temp->cnt++;
}
void get_pref_cnt(node* root,int& ans,int lvl,int& K){ //actually performing dfs on the trie
  for(int i=0;i<26;i++){  //lvl is the depth of the node
    if(root->children[i]!=NULL){
      get_pref_cnt(root->children[i],ans,lvl+1,K);// logically same as:- if(node->child!=NULL) dfs(node->child);
      root->cnt+=root->children[i]->cnt;  //recursively adds the count from the lowest ssubtree to higher subtrees
    }
  }
  while(root->cnt>=K){ //true for lowest common ancestor which can make a group of more than k
    ans+=lvl; //adding the depth of the lowest common ancestor
    root->cnt-=K; //since the k values are already considered, they are now subtracted from cnt
  }
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N,K;
    node* root=new node();
    string str;
    cin>>N>>K;
    for(int j=0;j<N;j++){
      cin>>str;
      insert(root,str);
    }
    int ans=0;
    get_pref_cnt(root,ans,0,K);
    cout<<"Case #"<<i+1<<": "<<ans<<"\n";
  }
  //bruteforce solution - does not work for large testcases
  // for(int i=0;i<T;i++){
  //   int N,K;
  //   cin>>N>>K;
  //   string arr[N];
  //   for(int i=0;i<N;i++)
  //     cin>>arr[i];
  //   map<string,int> pref_map;
  //   map<string,int>::iterator it;
  //   string str="";
  //   for(int i=0;i<N;i++){
  //     for(int j=1;j<=arr[i].size();j++)
  // 	pref_map[arr[i].substr(0,j)]++;
  //   }
  //   int ans=0;
  //   for(it=pref_map.begin();it!=pref_map.end();it++)
  //     ans+=((it->second)/K);
  //   cout<<"Case #"<<i+1<<": "<<ans<<"\n";
  // }
  return 0;
}
