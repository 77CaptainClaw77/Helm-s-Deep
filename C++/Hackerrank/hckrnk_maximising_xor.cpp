#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  int l,r; // the maximum xor possible is done by finding leftmost set bit in xor of l and r, then considering all other positions on the right to be 1
  cin>>l>>r;
  int x_val=l^r;
  int left_count=0;
  while(x_val>0){
    x_val=x_val>>1;
    left_count++;
  }
  int max_possible=(1<<left_count)-1;
  cout<<max_possible;
  return 0;
}
