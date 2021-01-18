/*File Information:-
Author: Kumarguru V

Problem Description
Zack is a tailor by profession. He is famous for making square-shaped beautifully-cut and sewed handkerchieves.
The customers demand large-sized handkerchieves. So, now Zack is determined to get the maximum size out of the cloth.
He has a rectangular piece of cloth of length 'L' and breadth 'B'. His task is to divide it into 'N' square-shaped cloth pieces each of side length ‘S’.
So he can make handkerchieves out of them of the maximum size.
Input: The first line of the input contains T- the number of test cases. T lines follow. 
	Each line of the test case contains L followed by B.
Output: S -the maximum length of each square-shaped handkerchief.
Constraints:
1 <= T <= 1000
1 <= L, B <= 1000
Sample Input:
1
40 30
Sample Output:
10
All submissions for this problem are available.



Author:
2★kaushambi


Editorial:
https://discuss.codechef.com/problems/ZACKHAN


Tags:
easy, greatest-common-divisor, kaushambi


Date Added:
12-09-2016


Time Limit:
1 secs


Source Limit:
50000 Bytes


Languages:
CPP14, C, JAVA, PYTH 3.6, PYTH, CS2, ADA, PYPY, PYP3, TEXT, PAS fpc, RUBY, PHP, NODEJS, GO, TCL, HASK, PERL, SCALA, BASH, JS, PAS gpc, BF, LISP sbcl, CLOJ, LUA, D, CAML, ASM, FORT, FS, LISP clisp, SCM guile, PERL6, CLPS, WSPC, ERL, ICK, NICE, PRLG, ICON, PIKE, SCM chicken, SCM qobi, ST, NEM





Submit

Link: https://www.codechef.com/problems/ZACKHAN
*/
#include <iostream>
#include <algorithm>
using namespace std;
//Essentially  a GCD problem
int fast_solve(int a,int b){ //find gcd by euclidean algorithm
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
void solve(int L,int B,int lim,int& S){  //naive solution
  S=1; //if unit squares, no wastage
  for(int i=2;i<=lim;i++)
    if(L%i==0 && B%i==0)
      S=i;  
}
int main(int argc, char *argv[])
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T,L,B,S;
  cin>>T;
  while(T--){
    cin>>L>>B;
    // solve(L,B,min(L,B),S);
    cout<<fast_solve(L,B)<<endl;
  }
  return 0;
}
