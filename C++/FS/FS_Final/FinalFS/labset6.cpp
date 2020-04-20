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
    cout<<"###########  Labset Program - 6  ###########\n\n"<<endl;
    ofstream f1,f2,f3;
    f1.open("Name1.txt");
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
    f2.open("Name2.txt");
    cout<<"Enter names in second list (Enter -1 to stop reading names)"<<endl;
    while(f2)
    {
        getline(cin,name);
        if(name=="-1")
            break;
        f2<<name<<endl;
    }
    f2.close();
    cout<<"Number of Names in \"Name1.txt\" file = "<<getCount("Name1.txt")<<endl;
    cout<<"Number of Names in \"Name2.txt\" file = "<<getCount("Name2.txt")<<endl;
    ifstream fi_1,fi_2,fi_3;
    fi_1.open("Name1.txt");
    fi_2.open("Name2.txt");
    f3.open("Name3.txt");
    string name1,name2;
    if(fi_1&&fi_2)
    {
        getline(fi_1,name1);
        getline(fi_2,name2);
        while(fi_1&&fi_2)
        {
            if(name1<name2)
                getline(fi_1,name1);
            else if(name1>name2)
                getline(fi_2,name2);
            else if(name1 == name2)
            {
                f3<<name1<<endl;
                getline(fi_1,name1);
                getline(fi_2,name2);
            }
        }
        int x=getCount("Name3.txt");
        cout<<"Number of Names in merged file : "<<x<<endl;
        cout<<"Contents of merged file:- "<<endl;
        if(x>0)
        {
            fi_3.open("Name3.txt");
            while(fi_3)
            {
                getline(fi_3,name);
                cout<<name<<endl;
            }
        }
        else
            cout<<"NO NAMES"<<endl;
    }
    else
        cout<<"Something went wrong"<<endl;
    fi_1.close();
    fi_2.close();
    fi_3.close();
    f3.close();
}
