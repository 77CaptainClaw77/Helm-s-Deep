#include <iostream>
using namespace std;
class acc;
class complex{
    int rp,ip;
    public:

    friend istream & operator >>(istream &in,complex& c);
    friend ostream & operator <<(ostream &out,complex& c);
    friend complex operator +(complex c1,complex c2);
    friend complex operator *(complex c1,complex  c2);
    friend complex operator -(complex c1,complex c2);

};

    complex operator *(complex c1,complex c2){
        complex c3;
        c3.rp=c1.rp*c2.rp-c1.ip*c2.ip;
        c3.ip=c1.rp*c2.ip+c1.ip*c2.rp;
        return c3;
    }
    complex operator +(complex c1,complex c2){
        complex c3;
        c3.ip=c1.ip+c2.ip;
        c3.rp=c1.rp+c2.rp;
        return c3;
    }
    complex operator -(complex c1,complex c2){
        complex c3;
        c3.ip=c1.ip-c2.ip;
        c3.rp=c1.rp-c2.rp;
        return c3;

    }
    istream & operator >>(istream &in,complex &c){
        cout<<"Enter the real part and the imaginary part";
        in>>c.rp;
        in>>c.ip;
        return in;
    }
    ostream & operator <<(ostream &out,complex &c)
    {
        out<<"\n"<<c.rp<<" + "<<c.ip<<" i";
        return out;
    }

int main(){
    complex c1,c2;
    cout<<"Enter the first number\n";
    cin>>c1;
    cout<<"Enter the  second number\n";
    cin>>c2;
    cout<<"\nThe first number is:-";
    cout<<c1;
    cout<<"\nThe second number is:-";
    cout<<c2;
    complex c3=c1+c2;
    complex c4=c1-c2;
    complex c5=c1*c2;
    cout<<"\nThe sum is:- "<<c3;
    cout<<"\nThe difference is:- "<<c4;
    cout<<"\nThe product is:- "<<c5;
    return 0;
}
