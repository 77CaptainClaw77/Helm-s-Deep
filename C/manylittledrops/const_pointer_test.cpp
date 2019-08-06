#include <iostream>
using namespace std;
int main(){
    const int a=100;
    const int* const p=&a;
    cout<<*p;
    return 0;
}
