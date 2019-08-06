#include <iostream>
using namespace std;
class myclass{
    int a,b;
    public:myclass(){
        a=5;
        b=10;
    }
    void display(){
        cout<<"\n"<<a<<"\n"<<b;
    }
};
int main(){
    myclass c;
    c.display();
    return 0;
}

