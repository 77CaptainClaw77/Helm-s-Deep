#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(vector<int> x){
  for(int i:x)
    cout<<i<<"\t";
   cout<<endl;
}
int main(){
  vector<int> x={1,2,3,4,5,6,7,8,9,10};
  make_heap(x.begin(),x.end());
  print_vector(x);
  pop_heap(x.begin(),x.end());
  print_vector(x);
  x.pop_back();
  print_vector(x);
  x.push_back(100);
  print_vector(x);
  push_heap(x.begin(),x.end());
  print_vector(x);
  return 0;
}
