#include <iostream>
#include <stack>
#include <string>
using namespace std;
void append_str(string &S,string &W){
  S=S+W;
}
string delete_str(string &S,int k){
  string deleted=S.substr(S.size()-k);
  S=S.substr(0,S.size()-k);
  return deleted;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int Q;
  string S="";
  stack<int> ops;
  stack<string> deletion_info_stack;
  stack<int> append_len_stack;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int type;
    cin>>type;
    if(type==1){ //append
      string W;
      cin>>W;
      append_len_stack.push(W.size());
      append_str(S,W);
      ops.push(1);
    }
    else if(type==2){ //delete
      int k;
      cin>>k;
      deletion_info_stack.push(delete_str(S,k));
      ops.push(2);
    }
    else if(type==3){ //print
      int k;
      cin>>k;
      cout<<S[k-1]<<"\n";
    }
    else{ //undo
      int op=ops.top();
      if(op==1){
	int del_len=append_len_stack.top();
	string del=delete_str(S,del_len);
	append_len_stack.pop();
      }
      else{
	string W=deletion_info_stack.top();
	append_str(S,W);
	deletion_info_stack.pop();
      }
      ops.pop();
    }
  }
  return 0;
}
