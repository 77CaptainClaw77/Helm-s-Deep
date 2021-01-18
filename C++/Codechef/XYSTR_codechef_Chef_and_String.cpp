/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
There are NNN students standing in a row and numbered 111 through NNN from left to right. You are given a string SSS with length NNN, where for each valid iii, the iii-th character of SSS is 'x' if the iii-th student is a girl or 'y' if this student is a boy. Students standing next to each other in the row are friends.
The students are asked to form pairs for a dance competition. Each pair must consist of a boy and a girl. Two students can only form a pair if they are friends. Each student can only be part of at most one pair. What is the maximum number of pairs that can be formed?
Link: https://www.codechef.com/problems/V
*/
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    int p_count=0;
    for(int i=0;i<s.size()-1;i++){
      if(s[i]!=s[i+1]){
	p_count++;
	i++;
      }
    }
    cout<<p_count<<"\n";
  }
  return 0;
}
