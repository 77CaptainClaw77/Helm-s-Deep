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
