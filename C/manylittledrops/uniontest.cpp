#include <iostream>
union u{
    int a;
    int b;
    int func(){
        a=b;
        double c;
        return a++;
    }
};
int main()
{
   u a;
    std::cout<<sizeof(u);
    std::cout<<std::endl<<a.func();
    return 0;
}
