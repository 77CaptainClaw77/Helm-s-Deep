#include <iostream>
using  namespace std;

int i=0;

class A{
public: ~A(){
    i=10;
}};
int fun(){
    i=3;
    A obj;
    return i++;
}
int main(){
    cout<<fun()<<" "<<i<<endl;
    return  0;
}
