#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;
const long n=pow(10,9);
pair<int,int> decode_instruction(string ins){
  int mul=1;
  int n_moves=0,e_moves=0;
  stack<pair<int,int>> instructions;
  stack<int> multipliers;
  for(char ch:ins){
    if(isalpha(ch)){
      if(ch=='N')
	n_moves++;
      else if(ch=='S')
	n_moves--;
      else if(ch=='E')
	e_moves++;
      else
	e_moves--;
    }
    else if(isdigit(ch))
      multipliers.push(ch-'0');
    else if(ch=='('){
      instructions.push(make_pair(n_moves,e_moves));
      n_moves=0;
      e_moves=0;
    }
    else{
      mul=multipliers.top();
      multipliers.pop();
      if(n_moves>0)
	n_moves=((((n_moves%n))*mul)%n);
      else
	n_moves=(abs((-(abs(n_moves)%n))*mul)%n);
      if(e_moves>0)
	e_moves=((((e_moves%n))*mul)%n);
      else
	e_moves=(abs((-(abs(e_moves)%n))*mul)%n);
      n_moves=n_moves+instructions.top().first;
      e_moves=e_moves+instructions.top().second;
      instructions.pop();
    }
  }
  return make_pair(n_moves,e_moves);
}
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    string str;
    cin>>str;
    int n_moves=0;
    int e_moves=0;
    pair<int,int> change=decode_instruction(str);
    n_moves=change.first;
    e_moves=change.second;
    int n_pos=1,e_pos=1;
    if(n_moves>0)
      n_pos=n+1-(n_moves%n);
    if(n_moves<0)
      n_pos=(1-n_moves)%n;
    if(e_moves>0)
      e_pos=(1+e_moves)%n;
    if(e_moves<0)
      e_pos=n+1-(abs(e_moves)%n);
    cout<<"Case #"<<i+1<<": "<<n_pos<<" "<<e_pos<<endl;
  }
  return 0;
}
