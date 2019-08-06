#include <iostream>
using namespace std;
class feet;
class inches{
    int in;

    public:inches(){}
        inches add(feet);
};
class feet{
    int ft;
    public:feet(){}
        friend inches inches::add(feet);
};
inches inches::add(feet ft)
{
    inches i;
    i.in=10;
    return i;
}
int main(){
    inches i;
    feet f;
    inches k=i.add(f);
    return 0;
}
