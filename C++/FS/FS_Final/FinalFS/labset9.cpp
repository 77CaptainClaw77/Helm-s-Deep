#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;
class record
{
    public:char sem[5] , usn[20] , name[20];
}rec[20] , found[20];
    char st_no[5] , rt_name[20];
    int no;
    void create_index_file()
    {
        ofstream index , index1;
        int i;
        index.open("secindex.txt" , ios::out);
        index1.open("record.txt" , ios::out);
        for( i = 0; i < no; i++)
        {
            if(i == no-1)
            {
                index <<rec[i].name<<"|"<<rec[i].usn<<"|"<<i+1;
                index1<<i+1<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].sem;
            }
            else
            {
                index <<rec[i].name<<"|"<<rec[i].usn<<"|"<<i+1<<endl;
                index1 <<i+1<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].sem<<endl;
            }
        }
        index.close();
        index1.close();
    }
void retrieve_record(char *index)
{
    fstream f1;
    char buff[80],*p;
    f1.open("record.txt",ios::in);
    while(!f1.eof())
    {
        f1.getline(buff,80,'\n');
        p=strtok(buff,"|");
        if(strcmp(index, p)==0){
            cout<<"\nStudent Details\n";
            cout<<"\nUSN\tName\tSemester\n";
            while(p!=NULL)
            {
                p=strtok(NULL,"|");
                if(p!=NULL)
                    cout<<p<<"\t";
            }
        }
    }
    f1.close();
}
void delete_record(char *idx)
{
    fstream f1;
    int i;
    char buff[80],*p,index[20][20];
    f1.open("record.txt",ios::in);
    i=0;
    while(!f1.eof())
    {
        f1.getline(buff,80,'\n');
        p=strtok(buff,"|");
        strcpy(index[i],p);
        p=strtok(NULL,"|");
        strcpy(rec[i].usn,p);
        p=strtok(NULL,"|");
        strcpy(rec[i].name,p);
        p=strtok(NULL,"|");
        strcpy(rec[i].sem,p);
        i++;
    }
    no=i;
    f1.close();
    int k=-1;
    for(i=0;i<no;i++)
    {
        if(strcmp(index[i],idx)==0)
        {
            k=i;
            break;
        }
    }
    if(k>-1)
    {
        for(i=k;i<no-1;i++)
            rec[i]=rec[i+1];
        no--;
        create_index_file();
        cout<<"\nData Successfully Deleted\n";
    }
    else
        cout<<"\nInvalid Name\n";
}
void display_record()
{
    char buff[80] , *p;
    int flag=1;
    ifstream f1;
    f1.open("record.txt" , ios::in);
    cout<<"\n\nStudent Details\n";
    cout<<"USN\t\tName\t\tSemester\n";
    while(! f1.eof())
    {
        f1.getline(buff , 80 , '\n');
        p= strtok(buff, "|");
        while(p!= NULL)
        {
            flag =0;
            p= strtok(NULL , "|");
            if(p != NULL)
                cout<<p<<setw(17);
        }
        cout<<endl<<setw(0);
    }
    if(flag == 1)
        cout<<"\nNo record found";
    f1.close();
}
void retrieve_details(int ch)
{
    int k=0, i;
    char buff[80] , *p;
    ifstream f1;
    char chusn[20] , index[20][80];
    f1.open("secindex.txt" , ios::in);
    while(!f1.eof())
    {
        f1.getline(buff , 80 , '\n');
        p = strtok(buff , "|");
        if(strcmp(rt_name , p) == 0)
        {
            strcpy(found[k].name , p);
            p = strtok(NULL , "|");
            strcpy(found[k].usn , p);
            p = strtok(NULL , "|");
            strcpy(index[k] , p);
            k++;
        }
    }
    if(k == 1)
    {
        if(ch == 2)
            retrieve_record(index[0]);
        else
            delete_record(index[0]);
    }
    else if(k > 1)
    {
        cout<<"Please choose the candidate USN\n";
        for( i = 0; i < k; i++)
        {
            cout<<"Name = "<<found[i].name <<"USN = "<<found[i].usn<<endl;
        }
        cin>>chusn;
        for(i=0; i<k ; i++)
        {
            if(strcmp(chusn , found[i].usn) == 0)
            {
                if(ch == 2)
                    retrieve_record(index[i]);
                else
                    delete_record(index[i]);
            }
        }
    }
    else
        cout<<"Invalid Name\n";
}
void readData()
{
    cout<<"Enter no of students"<<endl;
    cin>>no;
    for(int i = 0; i < no; i++)
    {
        cout<<"\nEnter the details of student "<<i+1;
        cout<<"\nUSN: ";
        cin>>rec[i].usn;
        cout<<"Name: ";
        cin>>rec[i].name;
        cout<<"Sem: ";
        cin>>rec[i].sem;
    }
    create_index_file();
    cout<<"Successfully inserted."<<endl;
}
void searchData()
{
    cout<<"Enter the name to search\t";
    cin>>rt_name;
    retrieve_details(2);
}
void deleteData()
{
    cout<<"Enter the student name to delete\t";
    cin>>rt_name;
    retrieve_details(3);
}
int main()
{
    cout<<"###########  Labset Program - 9  ###########\n\n";
    int ch;
    while(1)
    {
        cout<<"\nSelect the desired option:-\n1.Insert Data\n2.Display Data\n3.Search Data\n4.Delete Data\n5.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: readData();
            break;
            case 2: display_record();
            break;
            case 3: searchData();
            break;
            case 4: deleteData();
            break;
            case 5: exit(1);
            default:cout<<"Invalid choice."<<endl;
        }
    }
    return 0;
}
