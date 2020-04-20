#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include "fileop.h"
class user{
    private: static bool is_logged_in,;
    map<string,string> user_defined_fields;
    string password_field,user_id_field;
    FileOperations FOP;
    public:user();
    bool user_login();
    bool sign_up();
    string xor_encrypt(){}
    string get_user_attribute(string attr);
};
user::user(vector<string> fields,string password_field,string user_id_field){
    for(string field:fields)
        user_defined_fields[field]="";
    password_field="";
}
void user::sign_up(){
    for(pair<string,string>& p:fields){
        cout<<endl<<p.first<<" : ";
        getline(cin,p.second);
        if(p.first==password_field)
            p.second-xor_encrypt(p.second);
    }
    FOP.write_record(fields);
}
string user::get_user_attribute(attr){
    return user_defined_fields[attr];
}
string XOR_encrypt(string word){
    const char enc_key='*';
    string enc_pass=word;
    for(int i=0;i<word.size();i++)
        word[i]=enc_key^word[i];
    return enc_pass;
}
#endif // USER_H_INCLUDED
