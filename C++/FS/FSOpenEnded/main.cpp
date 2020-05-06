#include <iostream>
#include "User.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <ios>
//defining colour codes for colour output
#define KGRN  "\x1B[32m"
#define KBOLD "\x1B[1m"
#define KRED  "\x1B[31m"
#define RST  "\x1B[0m"
#define KCYN  "\x1B[36m"
//driver program to demonstrate file operations
//runs a simple application that uses user accounts for user management
using namespace std;
void clear_input_buffer(){ //function to clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.clear();
}
void print_title_screen(){
    cout<<endl;
    cout<<KRED<<KBOLD;
    cout<<"\t\t**************************\n";
    cout<<"\t\t*";
    cout<<KGRN<<" USER MANAGEMENT SYSTEM "<<KRED<<"*\n";
    cout<<"\t\t**************************\n";
    cout<<RST<<KGRN;
    cout<<endl<<endl;
}
user create_new_account_type(){
    string role,str,user_id_field,password_field;
    vector<string> user_fields;
    cout<<"\nEnter the new user role( ex. admin): ";
    getline(cin,role);
    cout<<"\nEnter the fields for each user(Enter an empty line to stop):-\n";
    while(1){
        getline(cin,str);
        if(str==""){
            if(user_fields.size()<2)
                cout<<"There must be atleast two user fields!\n";
            else
                break;
        }
        user_fields.push_back(str);
    }
    cout<<"\nEnter the name of the field you want to use as an user id field: ";
    getline(cin,user_id_field);
    cout<<"\nEnter the name of the field you want to use as a password field: ";
    getline(cin,password_field);
    cout<<"\nUser Account Type Successfully Created!";
    return user(role,user_fields,password_field,user_id_field);
}
//\n3.Signup\n4.Login\n5.Logout\n6.Delete account\n
int main()
{
    string temp="";
    cout<<KGRN;
    print_title_screen();
    int ch;
    int cur_user;
    vector<user> user_account_handlers;
    while(1){
        cur_user=-1;
        cout<<"\n1.Create new account type\n2.Select user type\n3.Exit\n";
        cout<<"Select the desired option: ";
        cin>>ch;
        clear_input_buffer();
        if(ch==1){
            user new_user=create_new_account_type();
            user_account_handlers.push_back(new_user);
        }
        else if(ch==2){
            string usr_type;
            cout<<"\nEnter the user type: ";
            getline(cin,usr_type);
            for(size_t i=0;i<user_account_handlers.size();i++)
                if(usr_type==user_account_handlers[i].get_user_role())
                    cur_user=i;
            if(cur_user==-1){
                cout<<"User role not found!";
                continue;
            }
            int choice;
            while(1){
                cout<<"\n1.Signup\n2.Login\n3.View Current user_id field\n4.View user attribute\n5.Logout\n6.Delete account\n";
                cout<<"Select the desired option: ";
                cin>>choice;
                clear_input_buffer();
                if(choice==1){
                    do{
                        cout<<"\nSIGNUP";
                    }while(!user_account_handlers[cur_user].sign_up());
                    cout<<"\nNew Account Successfully Created!";
                }
                else if(choice==2){
                    do{
                        cout<<"\nLOGIN";
                    }while(!user_account_handlers[cur_user].user_login());
                    cout<<"\nLogged in as "<<user_account_handlers[cur_user].get_current_user();
                }
                else if(choice==3){
                    if(user_account_handlers[cur_user].get_status())
                        cout<<"\nCurrently Logged in as "<<user_account_handlers[cur_user].get_current_user();
                    else
                        cout<<"\nNot Logged In!";
                }
                else if(choice==4){
                    string attrib;
                    cout<<"\nEnter the user attribute: ";
                    getline(cin,attrib);
                    string attrib_val=user_account_handlers[cur_user].get_user_attribute(attrib);
                    if(attrib_val!="None")
                        cout<<"\n"<<attrib<<" : "<<attrib_val;
                    else
                        cout<<"\nUser not found!";
                }
                else if(choice==5){
                    if(user_account_handlers[cur_user].logout())
                        cout<<"\nSuccessfully logged out!";
                }
                else if(choice==6){
                    if(!user_account_handlers[cur_user].get_status()){
                        cout<<"\nYou must first be logged in to delete the account!";
                    }
                    else{
                        string option;
                        cout<<"\nAre you sure you want to delete this account?(Type \'yes\' or \'no\')\n";
                        getline(cin,option);
                        if(option=="yes"){
                            if(user_account_handlers[cur_user].delete_current_account())
                                cout<<"\nAccount Successfully deleted!";
                            else
                                cout<<"\nDeletion Failed!";
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Choice Selected!!\n";
                }
            }
        }
        else if(ch==3){
            cout<<"\nThank You For Using User Management System";
            exit(0);
        }
        else{
            cout<<"\nInvalid Choice Selected!!\n";
        }
    }
    return 0;
}
