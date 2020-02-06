#include <iostream>
#include <cmath>
using namespace std;
int main(){
  float S,P,a1,b1,a2,b2;
  cout<<"Enter sum and product";
  cin>>S>>P;
  int det=(S*S)-(4*P);
  if(det<0){
    cout<<"No real solutions!";
  }
  else if(det==0){
    a1=b1=S/2;
    cout<<"Only 1 solution ==> ";
    cout<<"a="<<a1<<"\tb="<<b1;
  }
  else{
    a1=(S-sqrt(det))/2;
    a2=(S+sqrt(det))/2;
    b1=S-a1;
    b2=S-a2;
    cout<<"2 solutions:-";
    cout<<endl<<"Solution 1 ==> ";
    cout<<"a="<<a1<<"\tb="<<b1;
    cout<<endl<<"Solution 2 ==> ";
    cout<<"a="<<a2<<"\tb="<<b2;
  }
  return 0;
}
