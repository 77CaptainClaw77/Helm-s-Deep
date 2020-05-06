#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define KBLCK "\x1B[30m"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <iterator>
#include "fileop.h"
#define KGRN  "\x1B[32m"
class user{
    private:
    string user_role; //stores the rule of the current user such as admin or employee etc
    map<string,string> user_defined_fields;
    vector<string> arr_fields; //vector is used to maintain order as map reorders fields
    string password_field,user_id_field;
    FileOperations FOP;
    const char enc_key='*'; //key used for encryption
    public: string get_user_role();
    static bool is_logged_in;
    user(string role,vector<string> fields,string password_field,string user_id_field);
    bool user_login();
    bool sign_up();
    string XOR_encrypt(string str);
    bool check_password(string entered_password);
    string get_user_attribute(string attr);
    bool logout();
    bool get_status();
    string get_current_user();
    bool delete_current_account();
};
bool user::is_logged_in=false;
user::user(string role,vector<string> fields,string password_field,string user_id_field){
    this->user_role=role;
    arr_fields=fields;
    for(string field:fields)
        user_defined_fields[field]="";
    this->password_field=password_field;
    this->user_id_field=user_id_field;
}
//function to perform signup
bool user::sign_up(){
    if(is_logged_in)
        return false;
    string rep_password;
    for(string f:arr_fields){
        cout<<endl<<f<<" : ";
        if(f==password_field)
            cout<<KBLCK;
        getline(cin,user_defined_fields[f]);
        if(f==password_field)
            cout<<KGRN;
        if(f==user_id_field){
            if(FOP.get_position(user_defined_fields[f])!=-1){
                cout<<"Error! "<<user_id_field<<" already exists!"<<endl;
                return false;
            }
        }
        if(f==password_field){
            cout<<endl<<"Repeat "+password_field<<" : ";
            cout<<KBLCK;
            getline(cin,rep_password);
            cout<<KGRN;
            if(rep_password!=user_defined_fields[f]){
                cout<<password_field<<"s Do Not Match!!"<<endl;
                return false;
            }
        }
    }
    user_defined_fields[password_field]=XOR_encrypt(user_defined_fields[password_field]);
    FOP.write_record(user_defined_fields,user_id_field);
    return true;
}
//Get any user attribute by name
string user::get_user_attribute(string attr){
    if(user_defined_fields.find(attr)!=user_defined_fields.end())
        return user_defined_fields[attr];
    return "NONE";
}
//Encrypt a string using XOR encryption
string user::XOR_encrypt(string str){
    for(size_t i=0;i<str.size();i++)
        str[i]=enc_key^str[i];
    return str;
}
//Decrypt password and validate entered password
bool user::check_password(string entered_password){
    string actual_password=XOR_encrypt(user_defined_fields[password_field]);
    if(actual_password==entered_password)
        return true;
    return false;
}
//Perform user login
bool user::user_login(){
    string user_name,password_entered;
    cout<<endl<<user_id_field<<" : ";
    getline(cin,user_name);
    cout<<endl<<password_field<<" : ";
    cout<<KBLCK; //set text color to black to hide password
    getline(cin,password_entered); //input username and password
    cout<<KGRN; //reset text color
    int rec_pos=FOP.get_position(user_name); //get position of record from the index file.
    if(rec_pos!=-1){
        FOP.read_record(user_defined_fields,rec_pos);
        if(check_password(password_entered)){
            is_logged_in=true;
            return true;
        }
        else
            cout<<"Incorrect Password!"<<endl;
    }
    else
        cout<<user_id_field<<" not found!"<<endl;
    return false;
}
//logout the user
bool user::logout(){
    if(is_logged_in){
        is_logged_in=false;
        return true;
    }
    cout<<"Not Logged In!"<<endl;
    return false;
}
//Check if user is logged in
bool user::get_status(){
    return is_logged_in;
}
//delete the current user account
bool user::delete_current_account(){
    if(!is_logged_in){
        cout<<"Not Logged In!"<<endl;
        return false;
    }
    else{
        int del_pos=FOP.get_position(user_defined_fields[user_id_field]);
        FOP.del_account(del_pos,user_defined_fields[user_id_field]);
        is_logged_in=false;
        return true;
    }
}
//get user role
string user::get_user_role(){
    return user_role;
}
string user::get_current_user(){
    if(is_logged_in)
        return user_defined_fields[user_id_field];
    return "None";
}
#endif // USER_H_INCLUDED
