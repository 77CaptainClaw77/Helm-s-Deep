#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
class user
{
  string user_name; //Username
  string password; //Password
 // int user_id; //To identify users unniquely
public:
    string get_uname() {return user_name;}
    user(){}
    user(string uname,string pass)
    {
        user_name=uname;
        password=pass;
    }
static string b64encrypt(string pass) //Use base64 to encrypt here
  {
    clock_t start_time=clock();
    char allowed_char_set[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char* encrypted=(char*)malloc(sizeof(char)*100);
    int pass_len=pass.length();//Holds the length of the original string
    int index,val,padding,count,no_of_bits,temp,k;
    k=0;
    for(int i=0;i<pass_len;i+=3) //Encoding 3 characters at a time 6*4=8*3 and produce equivalent 4 characters
      {
	val=count=no_of_bits=0;
	for(int j=i;j<pass_len && j<=i+2;j++) //To group 3 character binaries together
	  {
	    val=val<<8; //Left shift to accomodate 8 characters
	    val=val|pass[j]; //OR to combine the binary values into a single string
	    count++; //Keeps track of characters to calculate padding
	  }
	no_of_bits=count*8; //Each character in ascii is 8 bits
	padding=no_of_bits%3; //Equivalent to mod 6 . Used to calculate no of padding characters required
	while(no_of_bits!=0)
	  {
	    if(no_of_bits>=6) //Complete block
	      {
		temp=(no_of_bits-6);
		index=(val>>temp) & 63;
		no_of_bits-=6;
	      }
	    else //Incomplete block
	      {
		temp=(6-no_of_bits);
		index=(val<<temp) & 63;
		no_of_bits=0;
	      }
	    	encrypted[k++]=allowed_char_set[index]; //Encryption done.
	  }

      }
    for(int i=0;i<padding;i++)
      {
	encrypted[k++]='=';
      }
    encrypted[k]='\0';
    //cout<<encrypted;
    //cout<<endl;
    clock_t end_time=clock();
    double time_taken=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    cout<<endl<<"\t\tOperation Performed: Password Encryption";
    cout<<endl<<"\t\tAlgorithm Used : Base64 Encryption";
    cout<<endl<<"\t\tAlgorithm Efficiency : O(n)";
    cout<<endl<<"\t\tLength Of Plain Text Password : "<<pass_len<<" characters";
    cout<<endl<<"\t\tSize of Encrypted Password: "<<k;
    cout<<endl<<"\t\tTime Taken For Encryption: "<<time_taken<<" seconds";

    return string(encrypted);
  }
  bool verify_password(string pass) //Function to verify user password by decrypting and checking password
  {
  //read user data then encrypt and check.

  return true;
  }
  bool password_is_valid(string pass)//Check if a user entered passsword is valid
  {
    bool is_valid=true;
    string not_allowed=".:{}[]()*&^%$#@!~`/?><|+=-, ";
    for(char ch:not_allowed)
      if(pass.find(ch)!=string::npos)
        is_valid=false;
    cout<<"HERE";
    return is_valid;
  }
};

#endif // USER_H_INCLUDED
