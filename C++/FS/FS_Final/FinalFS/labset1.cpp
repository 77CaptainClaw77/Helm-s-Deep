#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    cout<<"###########  Labset Program - 1  ###########\n\n";
    int ch;
    while(1){
        cout<<"\nSelect the desired option\n1.Keyboard\n2.File Input\n3.Exit\n";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1 : {
                        ofstream out_stream;
                        out_stream.open("reverse.txt");
                        string name;
                        cout<<"Enter the number of names: ";
                        int n;
                        cin>>n;
                        getline(cin,name);
                        cout<<"Enter the names:-\n";
                        for(int i=0;i<n;i++)
                        {
                            getline(cin,name);
                            out_stream<<name<<endl;
                        }
                        out_stream.close();
                        cout<<"\nReversed Names:-\n";
                        ifstream in_stream("reverse.txt");
                        while(in_stream)
                        {
                            getline(in_stream,name);
                            reverse(name.begin(),name.end());
                            cout<<name<<endl;
                        }
                        in_stream.close();
                      }
                      break;
            case 2 : {
                        string Name,fname;
                        cout<<"Enter file name with extension : ";
                        cin>>fname;
                        ifstream f_input(fname);
                        ofstream f_output("ReverseNamesOutput.txt");
                        if(f_input)
                        {
                            cout<<"File found."<<endl;
                            while(f_input&&f_output)
                            {
                                getline(f_input,Name);
                                reverse(Name.begin(),Name.end());
                                f_output<<Name<<endl;
                            }
                            cout<<"Output is redirected to a file(ReverseNamesOutput.txt)"<<endl;
                        }
                        else
                            cout<<"File Not Found"<<endl;
                        f_input.close();
                        f_output.close();
                      }
                      break;
            case 3: exit(0);
            default: cout<<"Invalid choice."<<endl;
        }
    }
    return 0;
}

