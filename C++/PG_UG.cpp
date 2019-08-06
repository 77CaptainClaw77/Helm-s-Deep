#include <iostream>
//#include <>
using namespace std;
class STUDENT{
protected:char name[20];
    char usn[11];
    int age;
public: void read_input(){
    cout<<"\nEnter the name";
    cin>>name;
    cout<<"\nEnter the USN";
    cin>>usn;
    cout<<"\nEnter the age";
    cin>>age;
}    
void show_data(){
    cout<<"\nName:"<<name<<"\nUSN:"<<usn<<"\nAge:"<<age;
}
};
class PGSTUDENT:public STUDENT{    
    protected:int Semester;
    float fees,stipend;
    public:void read_input()
    {
        STUDENT::read_input();
        cout<<"\nEnter the semester";
        cin>>Semester;
        cout<<"\nEnter the fees";
        cin>>fees;
        cout<<"\nEnter the stipend";
        cin>>stipend;
    }
    void show_data()
    {
        STUDENT::show_data();
        cout<<"\nSemester:"<<Semester<<"\nFees:"<<fees<<"\nStipend:"<<stipend;
    }
    friend void get_avg(PGSTUDENT pg[], int n);
};
void get_avg(PGSTUDENT pg[], int n)
{
    float avg[6];
    int count[6] = {0};
    for (int i = 0; i < n; i++)
    {
        avg[pg[i].Semester - 1] += pg[i].age;
        count[pg[i].Semester - 1]++;
    }
    for (int i = 0; i < 6; i++)
    {
        if(count[i]!=0){
        avg[i] /= count[i];
        cout << endl<< i + 1 << " Semester age average:" << avg[i];
        }
    }
}
class UGSTUDENT:public STUDENT{
    int Semester;
    float fees, stipend;

  public:
    void read_input()
    {
        STUDENT::read_input();
        cout << "\nEnter the semester";
        cin >> Semester;
        cout << "\nEnter the fees";
        cin >> fees;
        cout << "\nEnter the stipend";
        cin >> stipend;
    }
    void show_data()
    {
        STUDENT::show_data();
        cout << "\nSemester:" << Semester << "\nFees:" << fees << "\nStipend:" << stipend;
    }
    friend void get_avg(UGSTUDENT ug[],int n);
};
void get_avg(UGSTUDENT ug[], int n)
{
    float avg[8];
    int count[8] = {0};
    for (int i = 0; i < n; i++)
    {
        avg[ug[i].Semester - 1] += ug[i].age;
        count[ug[i].Semester - 1]++;
    }
    for (int i = 0; i < 8; i++)
    {
        if (count[i] != 0)
        {
            avg[i] /= count[i];
            cout << endl
                 << i + 1 << " Semester age average:" << avg[i];
        }
    }
}
int main(){
    int pg_count,ug_count;
    cout<<"\nEnter the number of students in PG";
    cin>>pg_count;
    cout <<"\nEnter the number of students in UG";
    cin >>ug_count;
    cout<<"\nEnter the data for the UG students";
    PGSTUDENT PG[pg_count];
    UGSTUDENT UG[ug_count];
    for(int i=0;i<ug_count;i++)
        UG[i].read_input();
    cout << "\nEnter the data for the PG students";
    for (int i = 0; i < pg_count; i++)
        PG[i].read_input();
    cout<<"\nThe UG Student Data Entered is:- ";
    for (int i = 0; i < ug_count; i++)
        UG[i].show_data();
    get_avg(UG,ug_count);
    cout << "\nThe PG Student Data Entered is:- ";
    for (int i = 0; i < pg_count; i++)
        PG[i].show_data();
    get_avg(PG,pg_count);
}