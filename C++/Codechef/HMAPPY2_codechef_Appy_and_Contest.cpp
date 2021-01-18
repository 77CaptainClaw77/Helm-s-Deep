/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Appy and Chef are participating in a contest. There are NNN problems in this contest; each problem has a unique problem code between 111 and NNN inclusive. Appy and Chef decided to split the problems to solve between them ― Appy should solve the problems whose problem codes are divisible by AAA but not divisible by BBB, and Chef should solve the problems whose problem codes are divisible by BBB but not divisible by AAA (they decided to not solve the problems whose codes are divisible by both AAA and BBB).
To win, it is necessary to solve at least KKK problems. You have to tell Appy whether they are going to win or lose.
Link: https://www.codechef.com/problems/N
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long get_gcd(int a,int b){
  if(a<b)
    swap(a,b);
  int t=b;
  while(t!=0){
    t=a%b;
    a=b;
    b=t;
  }
  return a;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long long N,A,B,K;
    cin>>N>>A>>B>>K;
    long long divs_A=N/A,divs_B=N/B;
    //long long comm_divs=N/(A*B); WRONG because lcm of A,B can be less than A*B
    
    long long comm_divs=N/((A*B)/get_gcd(A,B)); 
    long long ans=divs_A+divs_B-2*comm_divs;//2 because both chef and Appu cannot solve
    if(ans>=K)
      cout<<"Win\n";
    else
      cout<<"Lose\n";
  }
  return 0;
}
