/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
On a sunny day, Akbar and Birbal were taking a leisurely walk in palace gardens. Suddenly, Akbar noticed a bunch of sticks on the ground and decided to test Birbal's wits.
There are NNN stick holders with negligible size (numbered 111 through NNN) in a row on the ground. Akbar places all the sticks in them vertically; for each valid iii, the initial height of the stick in the iii-th holder is AiAiA_i. Birbal has a stick cutter and his task is to completely cut all these sticks, i.e. reduce the heights of all sticks to 000. He may perform zero or more operations; in each operation, he should do the following:

Choose an integer HHH and fix the cutter at the height HHH above the ground.
The cutter moves from the 111-st to the NNN-th stick holder. Whenever it encounters a stick whose current height is greater than HHH, it cuts this stick down to height HHH (i.e. for a stick with height h>Hh>Hh \gt H, it removes its upper part with length h−Hh−Hh-H).
All the upper parts of sticks that are cut in one operation must have equal lengths. Otherwise, the operation may not be performed.

For example, if the heights of sticks are initially [5,3,5][5,3,5][5, 3, 5], then some valid values for HHH in the first operation are 333 and 444 ― the cutter cuts the upper parts of two sticks and their lengths are [2,2][2,2][2, 2] and [1,1][1,1][1, 1] respectively. H=2H=2H = 2 is an invalid choice because it would cut the upper parts of all three sticks with lengths [3,1,3][3,1,3][3, 1, 3], which are not all equal.
Akbar wants Birbal to completely cut all sticks in the minimum possible number of operations. If you want to be friends with Birbal, help him solve the problem.
Link: https://www.codechef.com/problems/O
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--){
    int n,temp;
    cin>>n;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
      cin>>temp;
      if(temp!=0)
	s.insert(temp);
    }
    cout<<s.size()<<"\n";
  }
  return 0;
}
