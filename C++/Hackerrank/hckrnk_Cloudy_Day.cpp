//// TODO: INCOMPLETE, Solution is wrong!
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;
struct Town{
  ll population,x;
};
struct Cloud{
  ll x,range;
};
bool comp_towns(Town a,Town b){
  return a.x<b.x;
}
//below sort does not pass all cases, it is too slow.
// void sort_towns(Town towns[],int l,int h){
//   if(l<h){
//     int i=l,j=l-1;
//     long piv=towns[h].x;
//     for(i=l;i<h;i++){
//       if(towns[i].<piv){
// 	j++;
// 	swap(towns[i],towns[j]);
//       }
//     }
//     swap(towns[j+1],towns[h]);
//     int p=j+1;
//     sort_towns(towns,l,p-1);
//     sort_towns(towns,p+1,h);
//   }
// }
int find_first_town(Town towns[],int n,ll k){ //smallest greater than key
  int l=0,h=n-1;
  while(l<h){
    int m=l+(h-l)/2;
    if(towns[m].x>=k)
      h=m;
    else
      l=m+1;
  }
  if(towns[h].x<k)
    return -1; //town not found
  return h; 
}
int find_last_town(Town towns[],int n,ll k){//largest smaller than key
  int l=0,h=n-1;
  while(l<h){
    int m=l+(h-l+1)/2;
    if(towns[m].x<=k)
      l=m;
    else
      h=m-1;
  }
  if(towns[l].x>k)
    return -1; //town not found
  return l;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n;
  //Input begins here
  Town towns[n];
  for(int i=0;i<n;i++)
    cin>>towns[i].population; 
  for(int i=0;i<n;i++)
    cin>>towns[i].x;
  cin>>m;
  Cloud clouds[m];
  for(int i=0;i<m;i++)
    cin>>clouds[i].x;
  for(int i=0;i<m;i++)
    cin>>clouds[i].range;
  sort(towns,towns+n,comp_towns);
  //sort_towns(towns,0,n-1);
  int town_counts[n]={};
  vector<pair<int,int>> cloud_towns(m);
  for(int i=0;i<m;i++){
    cloud_towns[i]=make_pair(-1,-1);
    int l=find_first_town(towns,n,clouds[i].x-clouds[i].range);
    if(l==-1)
      continue;
    int r=find_last_town(towns,n,clouds[i].x+clouds[i].range);
    if(r==-1)
      continue;
    cloud_towns[i]=make_pair(l,r);
    town_counts[l]++;
    if(r<n-1)
      town_counts[r+1]--;
  }
  ll sunny_town_pops=0,pop=0,max_pop=0;
  ll prev_one_sum[n]={};
  ll one_sum=0;
  for(int i=1;i<n;i++)
    town_counts[i]+=town_counts[i-1];
  for(int i=0;i<n;i++){
    if(town_counts[i]==1)
      one_sum+=towns[i].population;
    prev_one_sum[i]=one_sum;
  }
  for(int i=0;i<m;i++){
    int l=cloud_towns[i].first,r=cloud_towns[i].second;
    if(l==-1 || r==-1) continue;
    ll rsum=prev_one_sum[r];
    ll lsum=l==0?0:prev_one_sum[l-1];
    pop=rsum-lsum;
    max_pop=max(pop,max_pop);
  }
  for(int i=0;i<n;i++){
    if(town_counts[i]==0)
      sunny_town_pops+=towns[i].population;
  }
  cout<<max_pop+sunny_town_pops;
  return 0;
}
