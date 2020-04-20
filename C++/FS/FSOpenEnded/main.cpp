#include <iostream>
#include "User.h"
//driver program to demonstrate file operations
//
using namespace std;

int main()
{
    vector<string> fields={"Username","Password","Date of Birth","USN"};
    user new_user=user(fields,"Password");
    new_user.sign_up();
    return 0;
}
