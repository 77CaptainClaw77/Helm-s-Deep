#include <iostream>
#define MAX_REC_COUNT 20
using namespace std;
class Person
{
    protected:char name[20];
    int code;
};
class Account:virtual public Person
{
    protected: float pay;
};
class Admin:virtual public Person
{
    protected: char Experience[50];
};
class Master:public Admin,public Account
{
    public:
    void create_Record(){
            cout<<"\nEnter the name";
            cin>>name;
            cout<<"\nEnter the code";
            cin>>code;
            cout<<"\nEnter the pay";
            cin>>pay;
            cin.ignore();
            cout<<"\nEnter the experience";
            cin.getline(Experience,sizeof(Experience));
    } 
    friend void find_Record(Master records[],int n);
    void display_Record(){
            cout<<"\nName: "<<name;
            cout<<"\nCode: "<<code;
            cout<<"\nPay: "<<pay;
            cout<<"\nExperience: "<<Experience;
    }
};
void find_Record(Master records[], int n)
{
    int s_code;
    bool found = false;
    cout << "\nEnter the code of the record you want to find: ";
    cin >> s_code;
    for (int i = 0; i < n; i++)
    {
        if (records[i].code == s_code)
        {
            cout << "\nThe record has been found!";
            records[i].display_Record();
            cout << "\nDo you want to update this record? Press y for yes and anything else for no";
            char ch;
            cin >> ch;
            if (ch == 'y')
                records[i].create_Record();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nRecord Not Found!";
}
    int main()
    {
        Master m[MAX_REC_COUNT];
        int ch;
        int n = 0;
        cout << "\nSelect the desired option:-";
        while (1)
        {
            cout << "\n1.Create Record\n2.Update Record\n3.Display Records\n4.Exit";
            cin >> ch;
            switch (ch)
            {
            case 1:m[n++].create_Record();
            break;
            case 2:find_Record(m,n);
            break;
            case 3:for(int i=0;i<n;i++)
                        m[i].display_Record();
            break;
            case 4:return 0;
            default:cout<<"\nInvalid Input";
        }
    
    }
}
