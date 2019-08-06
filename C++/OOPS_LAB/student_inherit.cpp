#include <iostream>
using namespace std;
class STUDENT
{
	protected:
		char *USN;
	    int age;
	    char *Name;
	public:void init(){
			cout<<"\nEnter the name";
			cout<<"\nEnter the age";
			cout<<"\nEnter the USN";
			}
};
class UGSTUDENT:public STUDENT{
	int fees,stipend;
	int Semester;
	float semavg[8];
	public:void input(){
		cout<<"\nEnter the Semester";
		cin>>Semester;
		cout<<"\nEnter the fees";
		cin>>fees;
		cout<<"\nEnter the stipend";
		cin>>stipend;
	}
	friend void calcavg(){
		for()
	}
};
class PGSTUDENT:public STUDENT{
	int fees,stipend;
	int Semester;
	float semavg[6];
	public:void input()
	{	
		cout<<"\nEnter the Semester";
		cin>>Semester;
		cout<<"\nEnter the fees";
		cin>>fees;
		cout<<"\nEnter the stipend";
		cin>>stipend;
	}
	friend void calcavg()
};
