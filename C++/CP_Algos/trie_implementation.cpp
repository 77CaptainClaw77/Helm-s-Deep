#include <iostream>
#include <map>
using namespace std;
struct node{
  struct node* children[26];
  bool is_word_end;
  int word_end_points;
};
node* new_n(){
  node* newn=new node;
  newn->is_word_end=false;
  newn->word_end_points=0;
  for(int i=0;i<26;i++)
    newn->children[i]=nullptr;
  return newn;
}
void insert_trie(node* root,string str){
  node* temp_node=root;
  for(char ch:str){
    if(temp_node->children[ch-'A']!=nullptr)
      temp_node=temp_node->children[ch-'A'];
    else{
      temp_node->children[ch-'A']=new_n();
      temp_node=temp_node->children[ch-'A'];
    }
  }
  temp_node->is_word_end=true;
  temp_node->word_end_points++;
}
bool search_trie(node* root,string str){
  node* temp_node=root;
  for(char ch:str){
    if(temp_node->children[ch-'A']==NULL)
      return false;
    else{
      temp_node=temp_node->children[ch-'A'];
    }
  }
  if(temp_node!=nullptr && temp_node->is_word_end)
    return true;
  return false;
}
void trie_sum(node* root,int& sum){
  for(int i=0;i<26;i++){
    if(root->children[i]!=nullptr)
      trie_sum(root->children[i],sum);
  }
  sum=sum+root->word_end_points;
}
int get_pref_count(node* root,string pref){
  node* temp_node=root;
  for(char ch:pref){
    if(temp_node->children[ch-'A']==NULL)
      return 0;
    else
      temp_node=temp_node->children[ch-'A'];
  }
  int sum=0;
  trie_sum(temp_node,sum);
  return sum;
}
int main(int argc, char *argv[])
{
  node* n=new_n();
  string keys[]={"ALPHA","BETA","CHARLIE","CHAMPION"};
  for(int i=0;i<4;i++){
    insert_trie(n,keys[i]);
    cout<<search_trie(n,keys[i])<<"\n";
  }
  cout<<search_trie(n,"ALPH")<<"\n"<<search_trie(n,"MONSTER");
  cout<<"\n"<<get_pref_count(n,"CHA");
  return 0;
}

