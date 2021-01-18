/*File Information:-
Author: Kumarguru V

Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Chef has NN items in his shop (numbered 11 through NN); for each valid ii, the price of the ii-th item is PiP_i. Since Chef has very loyal customers, all NN items are guaranteed to be sold regardless of their price.
However, the government introduced a price ceiling KK, which means that for each item ii such that Pi>KP_i \gt K, its price should be reduced from PiP_i to KK.
Chef's revenue is the sum of prices of all the items he sells. Find the amount of revenue which Chef loses because of this price ceiling.
Link: https://www.codechef.com/problems/PRICECON
*/
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T,K,N,loss,temp;
  cin>>T;
  while(T--){
    loss=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      cin>>temp;
      if(temp>K)
	loss+=temp-K;
    }
    cout<<loss<<"\n";
  }
  return 0;
}
