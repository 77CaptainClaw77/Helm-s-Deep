#include <iostream>
class myclass{
    int b;
    static int a;
    public:void showval();
};
int myclass::a=100;
void myclass::showval(){
    b=a+10;
    a++;
    std::cin>>a;
    std::cout<<a;
}

int main(){
    myclass my;
    my.showval();
    return 0;
}
