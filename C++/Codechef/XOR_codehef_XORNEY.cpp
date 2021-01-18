/*File Information:-
Author: Kumarguru V

Chef has given you a sequence A[1], A[2], ..., A[N] composed of N nonnegative integer numbers. Then, for each pair (i; j) such that 1 <= i < j <= N, we have written a number that equals to A[i] xor A[j] (xor is exclusive or, "xor" in Pascal, "^" in C++). Thus, we have obtained N*(N-1)/2 numbers. Your task is to find K minimal numbers among them.

Link: https://www.codechef.com/problems/XOR
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
  long long L,R,T,total,o_c;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  while(T--){
    cin>>L>>R;
    total=R-L;
    if(L%2!=0 && R%2!=0)
      o_c=(total/2)+1;
    else
      o_c=(total+1)/2;
    if(o_c%2==0)
      cout<<"Even\n";
    else
      cout<<"Odd\n";
  }
  return 0;
}
