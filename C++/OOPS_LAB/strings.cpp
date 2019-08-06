#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
class STR{
	char *str;
	int len;
	public:STR(char s[]){
		len=strlen(s)+1;
		str=new char[len];
		strcpy(str,s);
	}
	STR(STR& s1){
		len=s1.len;
		str=new char[len];
		strcpy(str,s1.str);
	}
	STR(){
		len=1;
		str=new char[len];
		str[0]='\0';	
	}
	STR operator +(STR s1){
		STR temp;
		temp.len=s1.len+len-1;
		temp.str=new char[temp.len];
		temp.str=strcat(str,s1.str);
		return temp;
	}
	int operator >=(STR s1){
		return (len-s1.len);	
	}
	void display(){
		cout<<str;
	}
};
int main(){
	STR s1,s2,s3;
	cout<<"\nEnter the first string: ";
	char *st1=new char[20];
	cin>>st1;
	s1=STR(st1);
	cout<<"\nEnter the second string: ";
	char *st2=new char[20];
	cin>>st2;
	s2=STR(st2);
	cout<<"\nThe first string is :- ";
	s1.display();
	cout<<"\nThe second string is :- ";
	s2.display();
	s3=s1+s2;
	cout<<"\nThe concatenated string is :-";
	s3.display();
	int diff=(s1>=s2);
	cout<<endl;
	if(diff>0)
		cout<<"String s1 exceeds s2 by "<<diff<<" characters";
	else if(diff<0)
		cout<<"String s2 exceeds s1 by "<<-diff<<" characters";
	else
		cout<<"The strings are equal";
	return 0;	
}

