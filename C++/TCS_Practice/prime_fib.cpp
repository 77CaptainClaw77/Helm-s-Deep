#include <iostream>
#include <set>
#include <iterator>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int combine_num(int a,int b){
  int t=b;
  do{
    t/=10;
    a*=10;
  }while(t>0);
  return a+b;
}
set<int> precompute_primes(){
  set<int> primes;
  vector<bool> is_prime_val(10001,true);
  for(int i=2;i<=10000;i++){
    if(is_prime_val[i] && i*i<=10000){
      for(int j=i*i;j<=10000;j+=i)
	is_prime_val[j]=false;
    }
  }
  for(int i=2;i<=10000;i++){
    if(is_prime_val[i])
      primes.insert(i);
  }
  return primes;
}
int main(int argc, char *argv[])
{
  set<int> prime_vals=precompute_primes();
  cout<<prime_vals.size();
  int n1,n2;
  cin>>n1>>n2;
  set<int> req_primes;
  set<int>::iterator it=prime_vals.begin();
  while(*it<n1)
    it++;
  while(*it<=n2){
    req_primes.insert(*it);
    it++;
  }
  it=prime_vals.begin();
  int count=0;
  int min_val=INT_MAX,max_val=INT_MIN;
  map<int,set<int>> vals;
  for(int v:prime_vals){
    if(v>10)
      vals[v%10].insert(v/10);
    if(v>100)
      vals[v%100].insert(v/100);
    if(v>1000)
      vals[v%1000].insert(v/1000);
  }
  set<int> l2;
  for(int r:req_primes){
    map<int,set<int>>::iterator map_iter=vals.find(r);
    if(map_iter!=vals.end()){
      for(int p:req_primes){
	if(p==r) continue;
	if((map_iter->second).find(p)!=(map_iter->second).end()){
	  int num=combine_num(r,p);
	  if(prime_vals.find(num)!=prime_vals.end())
	    l2.insert(num);
	}
      }
    }
  }
  cout<<l2.size();
  return 0;
}
