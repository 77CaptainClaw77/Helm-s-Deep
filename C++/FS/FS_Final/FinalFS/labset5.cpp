#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
using namespace std;
int getCount(string fname)
{
    ifstream fin;
    fin.open(fname);
    string str;
    int count=0;
    while(getline(fin,str))
        count++;
    fin.close();
    return count;
}
int main()
{
    cout<<"###########  Labset Program - 5  ###########\n\n"<<endl;
    ofstream f1,f2,f3;
    f1.open("Names1.txt");
    string name;
    cout<<"Enter names in first list (Enter -1 to stop reading names)"<<endl;
    while(f1)
    {
        getline(cin,name);
        if(name=="-1")
            break;
        f1<<name<<endl;
    }
    f1.close();
    f2.open("Names2.txt");
    cout<<"Enter names in second list (Enter -1 to stop reading names)"<<endl;
    while(f2)
    {
        getline(cin,name);
        if(name=="-1")
            break;
        f2<<name<<endl;
    }
    f2.close();
    int countx,county;
    countx = getCount("Names1.txt");
    county = getCount("Names2.txt");
    cout<<"Number of Names in \"Names1.txt\" file = "<<countx<<endl;
    cout<<"Number of Names in \"Names2.txt\" file = "<<county<<endl;
    ifstream fi_1,fi_2,fi_3;
    fi_1.open("Names1.txt");
    fi_2.open("Names2.txt");
    f3.open("Names3.txt");
    string name1,name2;
    int x = 0;
    int y = 0;
    if(fi_1&&fi_2)
    {
        getline(fi_1,name1);
        getline(fi_2,name2);
        while(fi_1&&fi_2)
        {
            if(name1<name2)
            {
                f3<<name1<<endl;
                getline(fi_1,name1);
                x++;
            }
            else if(name1>name2)
            {
                f3<<name2<<endl;
                getline(fi_2,name2);
                y++;
            }
            else if(name1 == name2)
            {
                f3<<name1<<endl;
                getline(fi_1,name1);
                getline(fi_2,name2);
                x++;
                y++;
            }
        }
        if(x!=countx)
        {
            while(fi_1)
            {
                f3<<name1<<endl;
                getline(fi_1,name1);
            }
        }
        if(y!=county)
        {
            while(fi_2)
            {
                 f3<<name2<<endl;
                 getline(fi_2,name2);
            }
        }
        cout<<"Number of Names in merged file : "<<getCount("Names3.txt")<<endl;
        cout<<"Contents of merged file:- "<<endl;
        fi_3.open("Names3.txt");
        while(fi_3)
        {
            getline(fi_3,name);
            cout<<name<<endl;
        }
    }
    else
        cout<<"Something went wrong"<<endl;
    fi_1.close();
    fi_2.close();
    fi_3.close();
    f3.close();
}

