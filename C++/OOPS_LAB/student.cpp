#include <iostream>
using namespace std;
class personal;
class student
{
	char name[20],usn[20];
	int m[3];
	bool pass;
	char grade;
	static int count;
	float avg;
	void calcavg(){
		avg=(m[0]+m[1]+m[2]+0.0)/3;
	}
	void calcgrade(){
		grade=avg>90?'S':(avg>80?'A':(avg>70?'B':(avg>60?'C':(avg>50?'D':'F'))));
	}
	public:void init(){
			cout<<"Enter the name";
			cin>>name;
			cout<<"Enter the usn";
			cin>>usn;
			cout<<"Enter the marks in 3 subjects";
			cin>>m[0]>>m[1]>>m[2];
			avg=m[0]+m[1]+m[2];
			pass=true;
			calcavg();
			calcgrade();	
			grade_point();		
	}
	void grade_point(){
		if(m[0]<50 || m[1]<50 || m[2]<50)
			pass=false;
		else
			count++;
	}	
	static int display_count()
	{return count;}
	friend void display(student s,personal p);
};
class personal{
	long mobile_no;
	char address[40];
	public:void init(){
		cout<<"Enter the mobile_no";
		cin>>mobile_no;
		cout<<"Enter the address";
		cin>>address;
	}
	friend void display(student s,personal p);
};
int student::count=0;
void printline(int range=70,char ch='*'){
		cout<<endl;
		for(int i=0;i<70;i++)
			cout<<ch;
		cout<<endl;
}
void display(student s,personal p){
	cout<<"\nAcademic Details";
	cout<<"\nStudent Name:"<<s.name;
	cout<<"\nUSN:"<<s.usn;
	cout<<"\nMarks in subject 1:"<<s.m[0];
	cout<<"\nMarks in subject 2:"<<s.m[1];
	cout<<"\nMarks in subject 3:"<<s.m[2];
	cout<<"\nAverage marks:"<<s.avg;
	cout<<"\nGrade Secured:"<<s.grade;
	cout<<"\nResult:"<<(s.pass==true?"PASS":"FAIL");
	printline();
	cout<<"\nPersonal Details";
	cout<<"\nMobile Number:"<<p.mobile_no;
	cout<<"\nAddress:"<<p.address;
}
int main(){
	int n;
	cout<<"Enter the number of students";
	cin>>n;
	personal p[n];
	student s[n];
	cout<<"Enter the details of "<<n<<" students\n";
	for(int i=0;i<n;i++)
	{
		s[i].init();
		p[i].init();	
	}
	printline();
	for(int i=0;i<n;i++)
	{
		cout<<"Student "<<i+1;
		display(s[i],p[i]);	
		printline();
	}
	cout<<"\nTotal Students Passed: "<<student::display_count();
	return 0;
}	
