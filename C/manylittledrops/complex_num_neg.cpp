#include <iostream>
using namespace std;
class complex{
    int rp,ip;
public:complex():rp(0),ip(0){}
    void read(){
        cout<<"\nEnter the real part";
        cin>>rp;
        cout<<"Enter the imaginary part";
        cin>>ip;
    }
    void display(){
        if(ip>=0)
        cout<<"\n"<<rp<<"+"<<ip<<'i';
        else
            cout<<"\n"<<rp<<ip<<'i';
    }
    void operator ~(){
        rp*=-1;
        ip*=-1;
    }
};
int main(){
    complex c;
    int ch;
    cout<<"Select the desired option";
    while(1){
        cout<<"\n1.New Complex Number\n2.Negate\n3.Display\n4.Exit";
        cin>>ch;
        switch(ch){
        case 1:c.read();
        break;
        case 2:~c;
        break;
        case 3:c.display();
        break;
        case 4:return 0;
        default:cout<<"\nInvalid choice";
        }
    }
    return 0;
}
