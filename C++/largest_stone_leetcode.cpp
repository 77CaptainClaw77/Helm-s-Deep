#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
  vector<int> myheap=stones;
  make_heap(myheap.begin(),myheap.end());
  while(myheap.size()>=2){
    int new_ele=myheap.front();
    pop_heap(myheap.begin(),myheap.end());
    myheap.pop_back();
    int diff=new_ele-myheap.front();                
    pop_heap(myheap.begin(),myheap.end());
    myheap.pop_back();
    if(diff){
      myheap.push_back(diff);
      push_heap(myheap.begin(),myheap.end());
    }
  }
  return myheap.empty()?0:myheap[0];
}
int main(){
  vector<int> stones={2,7,4,1,8,1};
  cout<<lastStoneWeight(stones);
  return 0;
}
