#include <bits/stdc++.h>
using namespace std;
// int main(int argc, char *argv[])
// {
//   cin.tie(0);
//   ios::sync_with_stdio(0);
//   int n,q;
//   unordered_map<int,vector<pair<int,int>>> rset,gset,bset;
//   cin>>n>>q;
//   int r,g,b;
//   for(int i=0;i<n;i++){
//     cin>>r>>g>>b;
//     rset[r].push_back(make_pair(g,b));
//     gset[g].push_back(make_pair(r,b));
//     bset[b].push_back(make_pair(r,g));
//   }
//   for(int i=0;i<q;i++){
//     cin>>r>>g>>b;
//     bool rfound=false,gfound=false,bfound=false;
//     if(rset.find(r)!=rset.end() && gset.find(g)!=gset.end() && bset.find(b)!=bset.end()){
//       for(pair<int,int> c:rset[r]){
// 	if(c.first<=g && c.second<=b){
// 	  rfound=true;
// 	  break;
// 	}
//       }
//       if(rfound){
// 	for(pair<int,int> c:gset[g]){
// 	  if(c.first<=r && c.second<=b){
// 	    gfound=true;
// 	    break;
// 	  }
// 	}
//       }
//       if(gfound){
// 	for(pair<int,int> c:bset[b]){
// 	  if(c.first<=r && c.second<=g){
// 	    bfound=true;
// 	    break;
// 	  }
// 	}
//       }
//       cout<<((rfound && gfound && bfound)?"YES\n":"NO\n");
//     }
//     else
//       cout<<"NO\n";
//   }
//   return 0;
// }
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,q,r,g,b; 
  cin>>n>>q;
  map<int,vector<int>> R,G,B;
  vector<int> r_vals,g_vals,b_vals;
  set<vector<int>> all_vals;//fast lookup
  for(int i=0;i<n;i++){
    cin>>r>>g>>b;
    R[r].push_back(i);
    G[g].push_back(i);
    B[b].push_back(i);
    r_vals.push_back(r);
    g_vals.push_back(g);
    b_vals.push_back(b);
    vector<int> v{r,g,b};
    all_vals.insert(v);
  }
  for(int i=0;i<q;i++){
    cin>>r>>g>>b;
    vector<int> v{r,g,b};
    if(all_vals.find(v)!=all_vals.end())
      cout<<"YES\n";
    else{
      if(R.find(r)!=R.end() && G.find(g)!=G.end() && B.find(b)!=B.end()){
	bool rfound=false,gfound=false,bfound=false;
	for(int k=0;k<R[r].size();k++){
	  if(g_vals[R[r][k]]<=g && b_vals[R[r][k]]<=b){
	    rfound=true;
	    break;
	  }
	}
	if(rfound){
	  for(int k=0;k<G[g].size();k++){
	    if(r_vals[G[g][k]]<=r && b_vals[G[g][k]]<=b){
	      gfound=true;
	      break;
	    }
	  }
	}
	if(gfound){
  	  for(int k=0;k<B[b].size();k++){
	    if(r_vals[B[b][k]]<=r && g_vals[B[b][k]]<=g){
	      bfound=true;
	      break;
	    }
	  }
	}
	if(rfound && bfound && gfound)
	  cout<<"YES\n";
	else
	  cout<<"NO\n";
      }
      else
	cout<<"NO\n";
    }
  }
  return 0;
}

