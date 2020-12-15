/* 

3 cases - 2 possible 1 not
ab
abcdfslkjfdslkj
2
base case: Min no of moves>given no of moves : IMPOSSIBLE
abc
abcd
1
case 1: Min no of moves=given no of moves : POSSIBLE
abcd
abcde
2
NO
abcd
abcde
3
YES
case 2: Moves>min no difference is even : POSSIBLE if odd : IMPOSSIBLE
abcd
abcdert
12
case 3:Moves>min no ie Moves>=size of s+size of t : POSSIBLE
no of moves: given
min no of moves: to find
abcdefg
abcdijk
5
how to find min no?
abcdefgplo
asvfdgg
^
no of delete ops=size of s - common_len
no of append ops=size of t - common_len
min_no of ops=no of del+no of app
abcdefgh
abcd
   ^
abcd
abcdef
   ^
abcdef
abcdgh
   ^
i=4

common_len=1  
common_len=4
min_no_of_moves

abcd
afcd
1
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
  string s,t;
  int k;//moves
  string answer;
  cin>>s>>t>>k;//inputs
  int move_count,i;//move_count=min_count i=common_len
  for(i=0;i<s.size() && i<t.size();i++)
    if(s[i]!=t[i])
      break;
  move_count=(t.size()-i)+(s.size()-i);
  if(k==move_count) // Moves=min of moves
    answer="Yes";
  else if(k<move_count) // Moves<min of moves
    answer="No";
  else{// Moves>min of moves
    if((k-move_count)%2==0) // Even Diff
      answer="Yes";
    else if(k-s.size()>=t.size()) // k>=t.size()+s.size() 
      answer="Yes";
    else
      answer="No";
  }
  cout<<answer;
  return 0;
}
