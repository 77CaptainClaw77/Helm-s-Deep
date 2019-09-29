// Program to handle all file operations
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
class file_operations
{
    string word;
private: string encrypt(string s) //Base 64 Encyption
  {

  }
public: vector<string> read_data(char* filename)
    {
      vector<string> data;      
      fstream f_r;
      f_r.open(filename,ios::in);
      while(!f_r.eof())
	{
	  string temp;
	  getline(f_r,temp);
	  data.push_back(temp);
	}
      for(string d:data)
	cout<<d<<endl;
      return data;
    }
    void write_word_to_file()
    {
      
    }
    void add_to_scores()
    {

    }
    void retrieve_high_scores() // sorting algorithm here
    {

    }
    void add_user(string username,string password) //Create new user use encryption here
    {

    }
};
int main()
{
  file_operations f_op;
  vector<string> ds=f_op.read_data();
  
  return 0;
}
