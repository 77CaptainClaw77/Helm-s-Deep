#include <iostream>
#include <cmath>
using namespace std;
int convertToInteger(int);
class OCTAL
{
    int val;
  public:
    OCTAL(int x=0) : val(x) {}
    int operator+(int x) { return (convertToInteger(val) + x); }   
    friend int operator +(int x,OCTAL  o); 
};
int convertToInteger(int val){
    int raise=0,new_val=0,dig=0;
    while(val>0){
       new_val+=pow(8,raise++)*(val%10);
        val/=10;
    }
    return new_val;
}
int operator +(int x,OCTAL o){return (x+convertToInteger(o.val));}
int convertToOctal(int val){
    if (val < 8)
        return val;
    return val % 8 + (convertToOctal(val / 8) * 10);
}
int main(){
    OCTAL h;
    int x,ch,res;    
    while(1){
    cout<<"\nSelect the  desired option:- \n1. Conversion \n2. Addition\n3.Exit";
    cin>>ch;
    if(ch==3){return 0;}
    if(ch==1){
        cout<<"\n1.Integer to Octal \n2.Octal to Integer";
        cin>>ch;
        if(ch==1)
         {   cout<<"\nEnter the integer";
            cin>>x;
            res=convertToOctal(x);   
         }
         else{
             cout<<"\nEnter the octal number";
             cin>>x;
             res=convertToInteger(x);
         }
    }
    else if(ch==2){
        cout<<"\n1. Integer + Octal\n2.Octal + Integer";
        cin>>ch;
        if(ch==1){
            cout<<"\nEnter the numbers";
            cin>>x>>res;
            h=OCTAL(res);
            res=x+h;
        }
        else{
            cout << "\nEnter the numbers";
            cin >> res >> x;
            OCTAL h=OCTAL(res);
            res=h+x;
        }
    }
    else{
        cout<<"\nInvalid Input";
        continue;
    }
    cout<<"\nThe result is "<<res;
    }
}
