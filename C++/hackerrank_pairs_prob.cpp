#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
    int T;
    for(int i=0;i<T;i++){
        int n,d;
        cin>>n;
        cin>>d;
        vector<int> people(n);
        for(int j=0;j<n;j++)
            cin>>people[j];
        vector<pair<int,int>> pairs;
        for(int j=0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(people[j]<people[k])
                    pairs.push_back(make_pair(people[j],people[k]));
            }
        }
        cout<<pairs.size()<<"\n("<<pairs[d].first<<","<<pairs[d].second<<")\n";
    }
    return 0;
}
