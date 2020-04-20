#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
#define RECORD_LEN 30
using namespace std;
int count;
class student
{
    public:
        char name[25],usn[11],branch[15],sem[3],buf[100],age[10],rrn[2];
        void pack();
        void unpack();
    public:
        void display();
        void add();
        void searchRRN(int n)
        {
            ifstream in;
            in.open("data.txt",ios::in);
            in.seekg((n-1)*(RECORD_LEN+3),ios::beg);
            if(n<count+1)
            {
                in>>buf;
                unpack();
                cout<<"\nRRN is "<<rrn<<"\nUSN:"<<usn<<"\nNAME:"<<name<<"\nBranch:"<<branch<<"\nSEM:"<<sem<<"\nAGE:"<<age<<"\n";
            }
        else
        {
            cout<<"Invalid RRN"<<endl;
            return;
        }
    }
};
void student :: pack()
{
    strcpy(buf,usn);
    strcat(buf,"|");
    strcat(buf,name);
    strcat(buf,"|");
    strcat(buf,branch);
    strcat(buf,"|");
    strcat(buf,sem);
    strcat(buf,"|");
    strcat(buf,age);
    for(int i=strlen(buf); i<RECORD_LEN ; i++)
        strcat(buf,"#");
    strcat(buf,"\n");
}
void student :: unpack()
{
    strcpy(rrn,strtok(buf,"|"));
    strcpy(usn,strtok(NULL,"|"));
    strcpy(name,strtok(NULL,"|"));
    strcpy(branch,strtok(NULL,"|"));
    strcpy(sem,strtok(NULL,"|"));
    strcpy(age,strtok(NULL,"#"));
}
void student :: add()
{
    cout<<"Enter the USN : ";
    cin>>usn;
    cout<<"Enter the NAME : ";
    cin>>name;
    cout<<"Enter the BRANCH : ";
    cin>>branch;
    cout<<"Enter the SEM : ";
    cin>>sem;
    cout<<"Enter the AGE :";
    cin>>age;
    pack();
    ofstream fout;
    fout.open("data.txt",ios::app);
    fout<<count<<"|"<<buf;
    fout.close();
    count++;
}
void student :: display()
{
    ifstream fin;
    fin.open("data.txt");
    int x=1;
    while(!fin.eof())
    {
        fin>>buf;
        if(fin.fail())
            break;
        unpack();
        cout<<"\nRRN : "<<x++<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nBranch : "<<branch<<"\nSEM : "<<sem<<"\nAGE : "<<age<<"\n";
    }
    fin.close();
}

void getCount()
{
    ifstream fin;
    fin.open("data.txt");
    string str;
    while(getline(fin,str))
        count++;
    fin.close();
}
int main(void)
{
    cout<<"###########  Labset Program - 4  ###########\n\n"<<endl;
    count=0;
    getCount();
    student s;
    int ch;
    while(1)
    {
        cout<<"\nSelect the desired option:-\n1.Add \n2.Search by RRN \n3.Display\n4.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:s.add();
                    break;
            case 2:cout<<"Enter RRN "<<endl;
                    int rrn;
                    cin>>rrn;
                    s.searchRRN(rrn);
                    break;
            case 3:s.display();
                    break;
            case 4:exit(0);
            default: cout<<"Invalid Choice\n";
        }
    }
    return 0;
}
