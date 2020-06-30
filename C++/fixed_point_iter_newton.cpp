#include <cmath>
#include <iostream>
#include <iomanip>
#define lim pow(10,-10)
using namespace std;
long double get_newton(long double val){
  long double denom=-(sin(val)+(val*cos(val)));
  long double nom=1-(val*sin(val));
  long double ans=val-(nom/denom);
  return ans;
}
int main(int argc,char* argv[]){
  long double x,err;
  int count=0;
  while(1){
    err=abs(x-get_newton(x));
    count++;
    x=get_newton(x);
    if(err<lim) break;
    if(count>10000000) break;
  }
  cout<<fixed<<setprecision(15)<<endl<<count<<" "<<x<<" "<<err;
  return 0;
}
