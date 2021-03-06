#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------------
//Function to print map of adjacent words
//---------------------------------------------------------------------------------
void print_adjacent_word_map(map<string,vector<string>> word_map){
  map<string,vector<string>>::const_iterator iter;
  for(iter=word_map.begin();iter!=word_map.end();iter++){
    cout<<iter->first<<" : ";
    vector<string> adj_words=iter->second;
    for(int i=0;i<adj_words.size();i++){
      cout<<adj_words[i]<<" ";
    }
    cout<<" : "<<adj_words.size()<<endl;
  }
}
//---------------------------------------------------------------------------------
//Function to determine if two words differ by a single character.
//---------------------------------------------------------------------------------
bool differ_by_single_char(string word1,string word2){
  if(word1.length()!=word2.length())
    return false;
  int diff_count=0;
  for(int i=0;i<word1.length();i++){
    if(word1[i]!=word2[i]){
      diff_count++;
      if(diff_count>1)
	return false;
    }
  }
  return (diff_count==1);
}
//---------------------------------------------------------------------------------
//Function to compute map by bruteforce method
//---------------------------------------------------------------------------------
map<string,vector<string>> brute_force_adjacent_list(vector<string> word_list){
  map<string,vector<string>> adjacent_list;
  for(int i=0;i<word_list.size();i++){
    for(int j=i+1;j<word_list.size();j++){
      if(differ_by_single_char(word_list[i],word_list[j])){
	  adjacent_list[word_list[i]].push_back(word_list[j]);
	  adjacent_list[word_list[j]].push_back(word_list[i]);
	}
    }
  }
  return adjacent_list;   
}
//---------------------------------------------------------------------------------
//Function to compute map by grouping words by size
//---------------------------------------------------------------------------------
map<string,vector<string>> group_by_size_adjacent_list(vector<string> word_list){
  map<int,vector<string>> size_groups;
  map<string,vector<string>> adjacent_list;
  for(int i=0;i<word_list.size();i++)
    size_groups[word_list[i].length()].push_back(word_list[i]);
  map<int,vector<string>>::const_iterator iter;
  for(iter=size_groups.begin();iter!=size_groups.end();iter++){
    vector<string> group_words=iter->second;
      for(int i=0;i<group_words.size();i++){
	for(int j=i+1;j<group_words.size();j++){
	  if(differ_by_single_char(group_words[i],group_words[j])){
	    adjacent_list[group_words[i]].push_back(group_words[j]);
	    adjacent_list[group_words[j]].push_back(group_words[i]);
	  }
	}
      }
  }
  return adjacent_list;   
}

//---------------------------------------------------------------------------------
//Function to compute map by creating cliques
//---------------------------------------------------------------------------------
map<string,vector<string>> optimal_adjacent_list(vector<string> word_list){
  map<int,vector<string>> size_groups;
  map<string,vector<string>> adjacent_list;
  for(int i=0;i<word_list.size();i++)
    size_groups[word_list[i].length()].push_back(word_list[i]);
  map<int,vector<string>>::const_iterator iter;
  for(iter=size_groups.begin();iter!=size_groups.end();iter++){
    vector<string> group_words=iter->second;
    int group_num=iter->first;
    for(int k=0;k<group_num;k++){
      map<string,vector<string>> word_rep;
      for(int l=0;l<group_words.size();l++){
	string rep=group_words[l];
	rep.erase(k,1);
	word_rep[rep].push_back(group_words[l]);
      }
      map<string,vector<string>>::iterator itl;
      for(itl=word_rep.begin();itl!=word_rep.end();itl++){
	vector<string> clique=itl->second;
	if(clique.size()>1){
	  for(int i=0;i<clique.size();i++){
	    for(int j=i+1;j<clique.size();j++){
	      adjacent_list[clique[i]].push_back(clique[j]);
	      adjacent_list[clique[j]].push_back(clique[i]);
	    }
	  }     
	}
      }	
    }
  }
  return adjacent_list;   
}

//---------------------------------------------------------------------------------
//Function to read words from file into vector
//---------------------------------------------------------------------------------
vector<string> read_word_list(){
  fstream fr=fstream("word_list_2.txt",ios::in);
  vector<string> word_list;
  while(!fr.eof()){
    string word;
    fr>>word;
    word_list.push_back(word);
  }
  return word_list;
}
int main(int argc,char* argv[]){
  vector<string> word_list=read_word_list();
    map<string,vector<string>> adjacent_word_map=optimal_adjacent_list(word_list);
  //  map<string,vector<string>> adjacent_word_map=group_by_size_adjacent_list(word_list);
  // map<string,vector<string>> adjacent_word_map=brute_force_adjacent_list(word_list);
  print_adjacent_word_map(adjacent_word_map);
  return 0;
}
