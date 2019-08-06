#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdio>
using namespace std;
class file_scrambler
{
  string orig_name,scrambled_name;
  void write_to_file(string f_name,vector<string> contents);
  vector<string> read_from_file(string f_name);
public:void scrambler();
};
void file_scrambler::write_to_file(string f_name,vector<string> contents)
{
  ofstream out_file(f_name);
  for(string line:contents)
    {
      out_file<<line;
      out_file<<"\n";
    }
  out_file.close();
}
vector<string> file_scrambler::read_from_file(string f_name)
{
  vector<string> contents;
  string line;
  ifstream in_file(f_name);
  fflush(stdin);
  while(getline(in_file,line))
    contents.push_back(line);
  in_file.close();
  return contents;
}
void file_scrambler::scrambler()
{
  cout<<"Enter the name of the original file";
  cin>>orig_name;
  cout<<"Enter the file contents(type the word end to stop):- ";
  vector<string> orig_contents,temp,scram_contents;
  while(1)
    {
    string line,t;
    getline(cin,line);
    t=line;
    transform(t.begin(),t.end(),t.begin(),::tolower);
    if(t=="end")
      break;
    orig_contents.push_back(line);
  }
  write_to_file(orig_name,orig_contents);
  int shift;
  cout<<"Enter the shift value: ";
  cin>>shift;
  for(string str:orig_contents)
    {
    for(int i=0;i<str.length();i++)
      {
	if(isalpha(str[i]))
	  {
	    if(str[i]>='a')
		str[i]=((str[i]-'a'+shift)%26)+'a';
	    else
		str[i]=((str[i]-'A'+shift)%26)+'A';
	  }
      }
	scram_contents.push_back(str);
  }
    cout<<"Enter the name of the scrambled file: ";
    cin>>scrambled_name;
    write_to_file(scrambled_name,scram_contents);
    cout<<"\nOrigin file contents:- \n";
    temp=read_from_file(orig_name);
    for(string str:temp)
      cout<<str<<endl;
    temp=read_from_file(scrambled_name);
    cout<<"\nScrambled file contents:- \n";
    for(string str:temp)
      cout<<str<<endl;
}
int main()
{
  file_scrambler fs;
  fs.scrambler();
  return 0;
}
