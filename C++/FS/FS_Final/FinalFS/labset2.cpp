#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#define RECORD_LEN 30
using namespace std;
class student
{
        public:
        char name[25],usn[11],branch[15],age[3],sem[3],buf[100];
        void pack();
        void unpack();
        public:
        void display();
        void search();
        void add();
        void modify();
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
        strcpy(usn,strtok(buf,"|"));
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
        cout<<"Enter the AGE : ";
        cin>>age;
        pack();
        ofstream fout;
        fout.open("data.txt",ios::app);
        fout<<buf;
        fout.close();
}
void student :: display()
{
        ifstream fin;
        fin.open("data.txt");
        while(!fin.eof())
        {
                fin>>buf;
                if(fin.fail())
                break;
                unpack();
                cout<<"\nUSN:"<<usn<<"\nNAME:"<<name<<"\nBranch:"<<branch<<"\nSEM:"<<sem<<"\nAGE:"<<age<<"\n";
        }
        fin.close();
}
void student :: search()
{
        ifstream fin;
        fin.open("data.txt");
        char key[RECORD_LEN];
        cout<<"Enter the key : ";
        cin>>key;
        int found = 0;
        while(!fin.eof())
        {
                fin>>buf;
                if(fin.fail()) break;
                unpack();
                if(!strcmp(usn,key))
                {

cout<<"\nUSN:"<<usn<<"\nNAME:"<<name<<"\nBranch:"<<branch<<"\nSEM:"<<sem<<"\nAGE:"<<age<<"\n";
                        found = 1;
                }
        }
        if(found==0)
        cout<<"Student not found\n";
        fin.close();
        return;
}
void student :: modify()
{
        fstream f;
        f.open("data.txt",ios::in|ios::out);
        char key[RECORD_LEN];
        cout<<"Enter the key : ";
        cin>>key;
        while(!f.eof())
        {
                f>>buf;
                if(f.fail()) break;
                unpack();
                if(!strcmp(usn,key))
                {
                        cout<<"\nStudent Found ";
                        cout<<"\nEnter the usn";
                        cin>>usn;
                        cout<<"Enter the Name:";
                        cin>>name;
                        cout<<"Enter the branch:";
                        cin>>branch;
                        cout<<"Enter the sem:";
                        cin>>sem;
                        cout<<"Enter the new age:";
                        cin>>age;
                        pack();
                        f.seekp((int)f.tellg()-RECORD_LEN,ios::beg);
                        f<<buf;
                        f.close();
                        return;
                }
        }
        cout<<"Record not found\n";
        f.close();
}
int main(void)
{
        cout<<"###########  Labset Program - 2  ###########\n\n"<<endl;
        student s;
        int ch;
        while(1)
        {
                cout<<"\nSelect the desired option:-\n1.Add \n2.Search \n3.Modify \n4.Display\n5.Exit\n";
                cin>>ch;
                switch(ch)
                {
                 case 1:
                          s.add();
                          break;
                 case 2:
                           s.search();
                           break;
                  case 3:
                          s.modify();
                          break;
                  case 4:
                          s.display();
                          break;
                  case 5:exit(0);
                  default: cout<<"invalid\n";
               }
            }
}
