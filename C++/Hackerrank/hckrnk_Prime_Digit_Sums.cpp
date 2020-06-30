//TODO
#include <iostream>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;
int sum_dig(int n){
  int s=0,x=0;
  while(n>0){
    x=n%10;
    s+=x;
    n/=10;
  }
  return s;
}
int main(int argc, char *argv[])
{
  set<int> all_valid_primes={3,5,7,11,13,17,19,23,29,31,37,41,43};
  int q,n;
  cin>>q;
  vector<int> threes,fours,fives;
  for(int i=10;i<100;i++){
    int s=sum_dig(i);
    for(int j=0;j<10;j++){
      if(all_valid_primes.find(s+j)!=all_valid_primes.end())
	threes.push_back(i*10+j);
    }
  }
  for(int i=0;i<threes.size();i++){
    int s=sum_dig(threes[i]);
    int si=s-(threes[i]/100);
    for(int j=0;j<10;j++){
      if(all_valid_primes.find(s+j)!=all_valid_primes.end() && all_valid_primes.find(si+j)!=all_valid_primes.end())
	fours.push_back(i*10+j);
    }
  }
  cout<<fours.size();
  for(int i=0;i<fours.size();i++){
    int s=sum_dig(fours[i]);
    int si=sum_dig(fours[i]%1000);
    int sii=sum_dig(fours[i]%100);
    for(int j=0;j<10;j++){
      if(all_valid_primes.find(s+j)!=all_valid_primes.end() && all_valid_primes.find(si+j)!=all_valid_primes.end() && all_valid_primes.find(sii+j)!=all_valid_primes.end())
	fives.push_back(i*10+j);
    }
  }
  cout<<endl<<fives.size()<<endl;
  int count=0;
  for(int i=0;i<fives.size();i++){
    int s=sum_dig(fours[i]%10000);
    int si=sum_dig(fours[i]%1000);
    int sii=sum_dig(fours[i]%100);
    for(int j=0;j<10;j++){
      if(all_valid_primes.find(s+j)!=all_valid_primes.end() && all_valid_primes.find(si+j)!=all_valid_primes.end() && all_valid_primes.find(sii+j)!=all_valid_primes.end())
	count++;
    }
  }
  cout<<count<<endl;
  // while(q--){
  //   cin>>n;
  //   if(n==1) 
  //     cout<<10<<endl;
  //   else if(n==2)
  //     cout<<90<<endl;
  //   else{ //start constructing
  //     vector<int> nums;
      
  //   }
  // }
  return 0;
}
