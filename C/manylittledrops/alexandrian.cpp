#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int m,int n)
{
    int r;
    while(n>0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int diophantine(int p,int q)
{
        for (int i = 0; i * p <= 1; i++) {

        // check if it is satisfying the equation
        if ((1 - (i * p)) % q == 0) {
            return ((1-i*p)*p*q);
        }
        if(i==20)
            break;
}
}
int main(){
    int p=100,q=100;
    int r;
    vector<int> A;
    int n;
   // cout<<"Enter range";
   // cin>>n;
    p=q=n;
    for(int i=1;i<p;i++){
        for(int j=i+1;j<q;j++)
        {
            if(gcd(i,j)==1)
            {
                cout<<endl<<diophantine(-i,j);
                //A.push_back(diophantine(i,j));
                //A.push_back(diophantine(-i,j));
               // A.push_back(diophantine(i,-j));
            }   //cout<<endl<<i<<" "<<j;
        }
    }
    //for(auto k=A.begin();k<A.end();k++){
      //    cout<<endl<<*k;
    //}
}
