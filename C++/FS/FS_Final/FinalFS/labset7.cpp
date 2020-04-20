#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<string.h>
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

void read(string fname)
{
    ofstream fout;
    fout.open(fname);
    string name;
    cout<<"Enter names to \""<<fname<<"\" one per line in sorted order only."<<endl<<"(Enter -1 to stop reading names)"<<endl;
    while(fout)
    {
        getline(cin,name);
        if(name=="-1")
            break;
        fout<<name<<endl;
    }
    fout.close();
}

void merge(string fname1,string fname2,string fname3)
{
    ofstream fout;
    ifstream fin1,fin2,fin3;
    fin1.open(fname1);
    fin2.open(fname2);
    fout.open(fname3);
    string name1,name2;
    int x = 0;
    int y = 0;
    if(fin1&&fin2)
    {
        getline(fin1,name1);
        getline(fin2,name2);
        while(fin1&&fin2)
        {
            if(name1<name2)
            {
                fout<<name1<<endl;
                getline(fin1,name1);
                x++;
            }
            else if(name1>name2)
            {
                fout<<name2<<endl;
                getline(fin2,name2);
                y++;
            }
            else if(name1 == name2)
            {
                fout<<name1<<endl;
                getline(fin1,name1);
                getline(fin2,name2);
                x++;
                y++;
            }
        }
        if(x!=getCount(fname1))
        {
            while(fin1)
            {
                fout<<name1<<endl;
                getline(fin1,name1);
            }
        }
        if(y!=getCount(fname2))
        {
            while(fin2)
            {
                 fout<<name2<<endl;
                 getline(fin2,name2);
            }
        }
    }
    else
        cout<<"Something went wrong"<<endl;
}

void display(string str)
{
    cout<<"Number of Names in \""<<str<<"\" file = "<<getCount(str)<<endl;
}

int main()
{
    cout<<"###########  Labset Program - 7  ###########\n\n"<<endl;
    int k;
    cout<<"Enter k value (4 or 8) : ";
    cin>>k;
    if(k==4)
    {
        read("Kfile1.txt");
        read("Kfile2.txt");
        read("Kfile3.txt");
        read("Kfile4.txt");
        display("Kfile1.txt");
        display("Kfile2.txt");
        display("Kfile3.txt");
        display("Kfile4.txt");
        merge("Kfile1.txt","Kfile2.txt","K1.txt");
        merge("Kfile3.txt","Kfile4.txt","K2.txt");
        merge("K1.txt","K2.txt","Koutput.txt");
    }
    else if(k==8)
    {
        read("Kfile1.txt");
        read("Kfile2.txt");
        read("Kfile3.txt");
        read("Kfile4.txt");
        read("Kfile5.txt");
        read("Kfile6.txt");
        read("Kfile7.txt");
        read("Kfile8.txt");
        display("Kfile1.txt");
        display("Kfile2.txt");
        display("Kfile3.txt");
        display("Kfile4.txt");
        display("Kfile5.txt");
        display("Kfile6.txt");
        display("Kfile7.txt");
        display("Kfile8.txt");
        merge("Kfile1.txt","Kfile2.txt","K1.txt");
        merge("Kfile3.txt","Kfile4.txt","K2.txt");
        merge("Kfile5.txt","Kfile6.txt","K3.txt");
        merge("Kfile7.txt","Kfile8.txt","K4.txt");
        merge("K1.txt","K2.txt","K12.txt");
        merge("K3.txt","K4.txt","K34.txt");
        merge("K12.txt","K34.txt","Koutput.txt");
    }
    cout<<"Number of Names in \"Koutput.txt\" file = "<<getCount("Koutput.txt")<<endl;
    cout<<"Koutput.txt contains..."<<endl;
    ifstream fin;
    fin.open("Koutput.txt");
    string name;
    while(fin)
    {
        getline(fin,name);
        cout<<name<<endl;
    }
    fin.close();
}
