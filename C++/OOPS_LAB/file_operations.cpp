#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
//using namespace;
char filename[20];
class student{
	string name,gender;
	int age,height,weight;
	public:void read_data();
			void write_data();
			friend void display_data(student s[],int);
			friend void input_data(student	s[],int);
};
void student::read_data()
{
	ifstream file_read;
	file_read.open(filename,ios::in);
	file_read.read((char*)this,sizeof(*this));
}
void student::write_data(){
    ofstream file_write;
    file_write.open((filename),ios::out);
    file_write.write((char*)this,sizeof(*this));
}
void display_data(student s[],int n){
    for (int i=0;i<n;i++){
        s[i].read_data();
        cout<<"\nName:"<<s[i].name;
        cout<<"\nAge:"<<s[i].age;
        cout<<"\nHeight:"<<s[i].height;
        cout<<"\nWeight:"<<s[i].weight;
        cout<<"\nGender:"<<s[i].gender;
    }
}
void input_data(student s[],int n){
    for (int i=0;i<n;i++)
    {
    cout<<"\nEnter the name:";
    cin>>s[i].name;
    cout<<"\nEnter the gender:";
    cin>>s[i].gender;
    cout<<"\nEnter the age:";
    cin>>s[i].age;
    cout<<"\nEnter the height:";
    cin>>s[i].height;
    cout<<"\nEnter the weight:";
    cin>>s[i].weight;
    s[i].write_data();
    cin.ignore();
    }
}
int main(){
	student *s;
	string str;
	int n;
	cout<<"Enter the number of students";
	cin>>n;
	s=new student[n];
	cout<<"Enter the name of the file to write the data into";
	cin>>filename;
	input_data(s,n);
	cout<<"\nThe data has been written into the file "<<filename;
	cout<<"\nThe file contents are ";
	display_data(s,n);
	return 0;
}


