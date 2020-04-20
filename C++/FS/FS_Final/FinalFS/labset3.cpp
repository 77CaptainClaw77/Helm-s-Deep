#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
class student
{
        char name[30];
        char usn[15];
        char branch[5];
        char sem[5];
        char buf[70];
        public:
        student()
        {}
        void pack()
        {
                strcpy(buf, usn);
                strcat(buf, "|");
                strcat(buf, name);
                strcat(buf, "|");
                strcat(buf, branch);
                strcat(buf, "|");
                strcat(buf, sem);
                strcat(buf, "|");
                strcat(buf,"#");
                strcat(buf, "\n");
        }
        void unpack()
        {
                char *ptr = buf;
                while(*ptr!='#')
                {
                        if(*ptr == '|')
                                *ptr = '\0';
                        ptr++;
                }
                ptr = buf;
                strcpy(usn,ptr);
                ptr = ptr +strlen(ptr)+1;
                strcpy(name,ptr);
                ptr = ptr +strlen(ptr)+1;
                strcpy(branch,ptr);
                ptr = ptr+strlen(ptr)+1;
                strcpy(sem,ptr);
        }

        void display()
        {
                int chk = 0;
                ifstream ifile("out.txt", ios::in);
                ifile.getline(buf, '#');
                while(!ifile.eof())
                {
                        chk =1;
                        unpack();
                        cout << "USN: "<<usn<<"\tName: "<<name<<"\tBranch:"<<branch<<"\tSem: "<<sem<<"\n";
                        ifile.getline(buf, '#');
                }
                if(!chk)
                        cout << "File is empty\n";
                ifile.close();
        }
        int search(char key[])
        {
                int found = 0;
                ifstream ifile("out.txt", ios::in);
                while(!ifile.eof() && !found)
                {
                        ifile.getline(buf, '#');
                        unpack();
                        if(strcmp(key, usn) == 0)
                        {
                                found = 1;
                        }
                }
                ifile.close();
                return found;
        }
        void modify()
        {
                char key[10];
                cout<<"Enter The USN Of The Record To Be Modified"<<endl;
                cin>>key;
                int found = 0;
                fstream is;
                is.open("out.txt",ios::in|ios::out);
                while(!is.eof() && !found)
                {
                is.getline(buf, '#');
                int l = strlen(buf) + 1;
                unpack();
                if(strcmp(key, usn) == 0)
                {
                int pos=is.tellg();
                pos = pos-l;
                is.seekg(pos,ios::beg);
                cout<<"Modify 1:NAME\t2:BRANCH\t3:-SEM\t4:all\n";
                cout<<"Enter  choice\n";
                int ch;
                cin>>ch;
                switch(ch)
                {
                        case 1 : cout<<"NAME :\n";
                                         cin>>name;
                                         break;
                        case 2 : cout<<"BRANCH :\n";
                                         cin>>branch;
                                         break;
                        case 3 : cout<<"SEM :\n";
                                         cin>>sem;
                                         break;
                        case 4:cout<<"enter name,branch,sem\n";
                                cin>>name>>branch>>sem;
                                break;
                        default :cout<<"wrong choice !!!";
                                exit(0);
                }
                found = 1;
                pack();
                is.write(buf,strlen(buf));
                }
                }
                if(!found)
                cout<<"The Record with the given usn does not exist "<<endl;
                is.close();
        }
        void write()
        {
                ofstream ofile("out.txt", ios::out | ios::app);
                ofile.write(buf, strlen(buf));
                ofile.close();
        }
        void insert(){
                cout << "Enter USN\n";
                cin >> usn;
                cout << "Enter Name\n";
                cin >> name;
                cout << "Enter Branch\n";
                cin >> branch;
                cout << "Enter Sem\n";
                cin >> sem;
                pack();
                write();
        }
};
int main(){
    cout<<"###########  Labset Program - 3  ###########\n\n";
    int ch;
    while(1){
            cout << "\nSelect the desired option:-\n1.Insert\n2.Modify\n3.Search\n4.Display\n5.Exit\n";
            char usn[10];
            int found;
            cin >> ch;
            student s;
            switch(ch){
                    case 1: s.insert();
                                    break;
                    case 2: s.modify();
                                    break;
                    case 3: cout << "Enter usn to search\n";
                                    cin >> usn;
                                    found = s.search(usn);
                                    if(found == 0)
                                            cout << "No such record!\n";
                                    else
                                            cout << "Record found!\n";
                                    break;
                    case 4: s.display();
                                    break;
                    case 5:return(0);
                    default: cout << "Invalid ch!\n";
            }
        }
        return 0;
    }
