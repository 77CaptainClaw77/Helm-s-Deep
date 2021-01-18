/*File Information:-
Author: Kumarguru V

Eddy goes to Taxila University, one of the renowned university in the world. He wants to get admission in this university but the head of the university won't allow him unless he proves his command on numbers. The head doesn't want to defame his university by admitting a fool so he takes an admission test.
He gives Eddy two numbers LLL and RRR. Now, Eddy is asked to tell the count of numbers between [L,R][L,R][L,R] (inclusive) which have even number of divisors.
Now, he wants your help in this question. The Head tries to act smart by giving R<LR<LR \lt L to outsmart Eddy. In such cases he has to find answer for range [R,L][R,L][R,L] (inclusive). Will you help him?
Input:

First line will contain TTT, number of testcases. Then the testcases follow. 
Each testcase contains of a single line of input, two integers l,rl,rl, r. 

Output:
For each testcase, output in a single line count of numbers with even number of divisors.
Constraints

1≤T≤10001≤T≤10001 \leq T \leq 1000
1≤L,R≤1091≤L,R≤1091 \leq L,R \leq 10^9
0≤abs(L−R)≤4.1030≤abs(L−R)≤4.1030 \leq abs(L-R) \leq 4.10^3

Sample Input:
2
1 5
3 1

Sample Output:
3
2

EXPLANATION:
Output 1: From [1,5][1,5][1,5] there are 333 numbers with even number of divisors i.e.  2,3,52,3,52,3,5.
Output 2: From [1,3][1,3][1,3] there are 222 numbers with even number of divisors i.e. 2,32,32,3.
All submissions for this problem are available.



Author:
4★sarthak_eddy


Tags:
sarthak_eddy


Date Added:
24-01-2020


Time Limit:
1 secs


Source Limit:
50000 Bytes


Languages:
CPP14, C, JAVA, PYTH 3.6, PYTH, CS2, ADA, PYPY, PYP3, TEXT, PAS fpc, RUBY, PHP, NODEJS, GO, TCL, HASK, PERL, SCALA, kotlin, BASH, JS, PAS gpc, BF, LISP sbcl, CLOJ, LUA, D, R, CAML, rust, ASM, FORT, FS, LISP clisp, SQL, swift, SCM guile, PERL6, CLPS, WSPC, ERL, ICK, NICE, PRLG, ICON, PIKE, COB, SCM chicken, SCM qobi, ST, NEM





Submit

Link: https://www.codechef.com/problems/A
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  while(T--){
    long L,R;
    cin>>L>>R;
    if(L>R)
      swap(L,R);
    long ans=R-L+1-(floor(sqrt(R))-ceil(sqrt(L))+1);
    cout<<ans<<"\n";
  }
  return 0;
}
