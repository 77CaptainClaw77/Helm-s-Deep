#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;
class primkey
{
    public:
        char usn[13],dept[5],name[20];
        char buffer[50], buffer2[30];
        void add()
        {
            fstream f1,f2;
            f1.open("index.txt",ios::out|ios::app);
            f2.open("records.txt",ios::out|ios::app);
            cout<<"Enter the name : ";
            cin>>name;
            cout<<"Enter the dept : ";
                        cin>>dept;
            cout<<"Enter the usn : ";
                        cin>>usn;
            strcpy(buffer,usn);
            strcat(buffer,"|");
            strcat(buffer,name);
            strcat(buffer,"|");
            strcat(buffer,dept);
                        strcat(buffer,"#");
            strcpy(buffer2,usn);
            strcat(buffer2,"|");
            strcat(buffer2,name);
            f1<<buffer2;
            f1<<endl;
            f2<<buffer;
            f2<<endl;
            f1.close();
            f2.close();
            cout<<"Data added successfully "<<endl;
        }
        void search()
        {
            char usn1[20];
            cout<<"Enter the usn to search : ";
            cin>>usn1;
            int siz;
            siz=strlen(usn1);
            usn1[siz]='\0';
            int i,flag=0;
            fstream f1,f2;
            f1.open("index.txt",ios::in);
            f1.seekg(0,ios::beg);
            f2.open("records.txt",ios::in);
            f2.seekg(0,ios::beg);
            while(!f1.eof())
            {
                f1>>buffer2;
                for(i=0;i<10;i++)
                {
                    usn[i]=buffer2[i];
                }
                usn[i]='\0';
                if( strcmp(usn,usn1)==0 )
                {
                    cout<<"Searching data found"<<endl;
                    flag=1;
                    break;
                }

            int k=0;
                int j;
                if(flag==1)
                {
                    for(j=(i+1);j<(i+11);j++)
                    {
                        usn1[k]=buffer2[j];
                        k++;
                    }
                    usn1[k]='\0';
                    break;
                }

            }

            if(flag==1)
            {
                while(!f2.eof())
                {
                    f2>>buffer;
                    for(i=0;i<10;i++)
                    {
                        usn[i]=buffer[i];
                    }
                    usn[i]='\0';

                    if(strcmp(usn,usn1)==0)
                    {

                        cout<<buffer<<endl<<endl;
                        break;
                    }
                }
                }
            else
            {
                cout<<"Data requested was not found in the INDEX "<<endl;
            }
        }
               void delet()
           {
        fstream f3,f4,f5,f6,f7,f8;
        f3.open("index.txt",ios::in);
        f5.open("12.txt",ios::out|ios::trunc);
        f6.open("34.txt",ios::out|ios::trunc);
        f3>>buffer2;
        cout<<"Enter the USN"<<endl;
        char tusn[15];
        cin>>tusn;
        int siz;
        siz=strlen(tusn);
        tusn[siz]='\0';
        int i=0;
        while(!f3.eof())
        {
            cout<<"Entered ";
                        for(i=0;i<10;i++)
                        {
                               usn[i]=buffer2[i];
                        }
                        usn[i]='\0';
            cout<<"USN "<<usn<<endl;
            if(strcmp(usn,tusn)==0)
            {
                char buf[33];
                cout<<"Found some match"<<endl;
                f3>>buf;
                while(!f3.eof())
                {
                    f6<<buf<<endl;
                    f3>>buf;
                }
                f3.close();
                f6.close();
                f4.open("index.txt",ios::out|ios::trunc);
                f7.open("12.txt",ios::in);
                f8.open("34.txt",ios::in);
                f7>>buffer2;
                while(!f7.eof())
                {
                    f4<<buffer2<<endl;
                    f7>>buffer2;
                }
                f8>>buffer2;
                while(!f8.eof())
                {
                    f4<<buffer2<<endl;
                    f8>>buffer2;
                }
                f4.close();
                f7.close();
                f8.close();
                cout<<endl<<"Data Deleted Successfully"<<endl;
                return;
            }
            f5<<buffer<<endl;
            i=0;
            f3>>buffer;
    }
        cout<<"No record satisify the condition"<<endl;
    }
};
int main()
{
    cout<<"###########  Labset Program - 8  ###########\n\n";
    primkey ob1;
    int n;
    while(1)
    {
        cout<<"\nSelect the desired option:-\n1.Add\n2.Search\n3.Delete\n4.Exit\n";
        cin>>n;
        cout<<endl<<endl;
        switch(n)
        {
            case 1 : ob1.add();
                break;
            case 2 : ob1.search();
                break;
            case 3 : ob1.delet();
                break;
            case 4 : return 0;
        }
    }
}

