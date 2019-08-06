#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define def 1
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the row and col count";
    cin>>n>>m;
    char matrix[n][m];
    string str;
    cout<<"Enter the message to be encoded";
    cin>>str;
    int out=0;
    int a=0;
         for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                matrix[j][k]=str[a++];
                if(str[a]=='\0'){
                    out=1;
                    break;
            }
        }if(out)
        break;
    }
    cout<<"1.Clockwise\n2.Anticlockwise";
    string encoded="";
    int r_count=n;
    do{
    for(int i=r_count-m;i<m-1;i++){
        encoded+=matrix[r_count-m][i];
        cout<<"At loop 1: "<<encoded<<"\n";
    }
    for(int i=r_count-m;i<m-1;i++){
        encoded+=matrix[i][m-1];
        cout<<"At loop 2: "<<encoded<<"\n";
    }
    for(int i=m-1;i>=r_count-m;i--){
        encoded+=matrix[m-1][i];
        cout<<"At loop 3: "<<encoded<<"\n";
    }
    for(int i=m-2;i>0;i--){
        if(m-1==n%2)
            break;
        encoded+=matrix[i][r_count-m];
        cout<<"At loop 4: "<<encoded<<"\n";
    }
    m--;
    }while(m>0);
    cout<<"\n"<<encoded;
	return 0;
}
