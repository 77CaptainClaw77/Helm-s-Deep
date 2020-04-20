#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <fstream>
#include <vector>
#include <map>
class user{
    private: string username,password;
    bool is_logged_in;
    map<string,string> user_defined_fields;
    public: bool user_login(vector<string> fields);
    bool sign_up(vector<string> fields);
    string get_current_username();

};

#endif // USER_H_INCLUDED
