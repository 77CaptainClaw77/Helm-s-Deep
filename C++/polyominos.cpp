#include <iostream>
#include <vector>
using namespace std;
int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int R,C;
    cin>>R>>C;
    vector<vector<char>> v;
    for(int j=0;j<R;j++){
      vector<char> r;
      for(int k=0;k<C;k++){
	char ch;
	cin>>ch;
	r.push_back(ch);
      }
      v.push_back(r);
    }
    for(int i=0;i<C;i++){
      
    }
  }
  return 0;
}
