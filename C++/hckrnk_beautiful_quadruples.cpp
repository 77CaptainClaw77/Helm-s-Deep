#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
int beautifulQuadruples(int a, int b, int c, int d) {
    vector<int> limits={a,b,c,d};
    int beautiful=0,count=0;
    sort(limits.begin(),limits.end());
    //for(int i=0;i<limits.size();i++)
      //  cout<<limits[i];
    for(int i=1;i<=limits[0];i++){
        for(int j=i;j<=limits[1];j++){
            for(int k=j;k<=limits[2];k++){
                for(int l=k;l<=limits[3];l++){
                    cout<<endl<<i<<"\t"<<j<<"\t"<<k<<"\t"<<l;
                    if(i^j^k^l)
                        beautiful++;
		    count++;
                }
            }
        }
    }
    cout<<endl<<count<<endl;
    return beautiful;
}
int main(int argc, char *argv[])
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<endl<<beautifulQuadruples(a,b,c,d);
  return 0;
}
