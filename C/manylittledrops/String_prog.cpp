#include <iostream>
#include <cstring>
using namespace std;
class STRING{
    char *str;
    int len;
    public:STRING(){
        len=1;
        *str="\0";
    }
    STRING(char *s){
        len=strlen(s)+1;
        str=new char[len];
        strcpy(str,s);
    }
    STRING(STRING& st){
        len=st.len;
        str=new char[len];
        strcpy(str,st);
    }
    void display(){
        cout<<"\nThe string is : "<<str;
    }
    STRING operator +(STRING s1){

    }
};
