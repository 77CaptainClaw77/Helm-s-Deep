#include <iostream>
#include <string>

using namespace std;
int main(){
    int m,n,breaker;
    breaker=0;
    string mes;
    cin>>n>>m;
    char arr[n][m];
    cout<<"Enter the message";
    cin>>mes;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    /*int len=mes.size();
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(k<len)
                arr[i][j]=mes[k++];
            else{
                breaker=1;
                break;
            }
        }
        if(breaker==1)
            break;
    }*/
    int rc=n;//row count
    int cc=m;//column count
    //string code=" a";
    while(n>0 && m>0){
        for(int i=0;i<m;i++)
            cout<<arr[n][i];
        for(int j=0;j<n;j++)
            cout<<arr[j][m];
        for(int k=m-1;k>=0;k--)
            cout<<arr[n][k];
        m--;
        n--;
        for(int l=n-1;l>=0;l++)
            cout<<arr[l][cc-m-1];

    }
    /*cout<<code;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
    }*/

}
