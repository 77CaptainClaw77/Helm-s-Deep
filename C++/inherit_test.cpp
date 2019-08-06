#include <iostream>
using namespace std;
class A{
    protected:const int a=100;
};
class B:public virtual  A{

};
class C:public virtual A{

};
class D:public B,public C{
   public: void out(){cout<<C::a;}
};
int main(){
    D a;
    a.out();
}
