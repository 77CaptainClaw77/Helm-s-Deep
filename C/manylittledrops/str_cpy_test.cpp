#include <iostream>
using namespace std;
int main(){
    char s1[]="Hello";
    char *s2=s1;
   // cout<<s2;
    *s2='\0';
    cout<<s1;
    return 0;
}