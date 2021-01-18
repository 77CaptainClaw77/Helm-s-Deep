/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
As usual, Tom and Jerry are fighting. Tom has strength TSTS and Jerry has strength JSJS. You are given TSTS and your task is to find the number of possible values of JSJS such that Jerry wins the following game.
The game consists of one or more turns. In each turn:

If both TSTS and JSJS are even, their values get divided by 22 and the game proceeds with the next turn.
If both TSTS and JSJS are odd, a tie is declared and the game ends.
If TSTS is even and JSJS is odd, Tom wins the game.
If TSTS is odd and JSJS is even, Jerry wins the game.

Find the number of possible initial values of JSJS such that 1≤JS≤TS1 \le JS \le TS, there is no tie and Jerry wins the game.
Link: https://www.codechef.com/problems/EOEO
*/
#include <iostream>
using namespace std;
int get_p_of_two(long long n){
  int p=1;
  while(n>0){
    if(n&1)
      break;
    p++;
    n=n>>1;
  }
  return p;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long long TS;
    cin>>TS;
    int p=get_p_of_two(TS);
    long long div=1<<p;
    long long ans=TS/div;
    cout<<ans<<"\n";
  }
  return 0;
}
