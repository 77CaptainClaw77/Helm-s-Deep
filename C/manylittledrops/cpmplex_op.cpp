#include <iostream>
using namespace std;
class complex{
    int rp,ip;
    public:complex():rp(0),ip(0){}
    complex(int x,int y):rp(x),ip(y){}
    complex operator +(complex c){return complex((c.rp+rp),(c.ip+ip));}
    complex operator -(complex c){return complex((rp-c.rp),(ip-c.ip));}
    complex operator *(complex c){return complex((c.rp*rp-c.ip*ip),(c.ip*rp+c.rp*ip));}
    friend istream& operator >>(istream& in,complex& c);
    friend ostream& operator <<(ostream& out,complex& c);
};
 istream& operator >>(istream& in,complex& c){
    cout<<"\nEnter the real part";
    in>>c.rp;
    cout<<"Enter the imaginary part";
    in>>c.ip;
    return in;
 }
 ostream& operator <<(ostream& out,complex& c){
    out<<c.rp<<(c.ip>=0?"+":"")<<c.ip<<"i";
    return out;
 }
int main(){
    complex c1,c2,c3;
    cout<<"Enter the first number";
    cin>>c1;
    cout<<"Enter the second number";
    cin>>c2;
    c3=c1+c2;
    cout<<"\nThe sum of "<<c1<<" and "<<c2<<" is "<<c3;
    c3=c1-c2;
    cout<<"\nThe difference of "<<c1<<" and "<<c2<<" is "<<c3;
    c3=c1*c2;
    cout<<"\nThe product of "<<c1<<" and "<<c2<<" is "<<c3;
    return 0;
}
