#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void print_vec(vector<int> v){
  for(int i:v)
    cout<<i<<" ";
  cout<<"\n";
}
void print_mat(vector<vector<int>> m){
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      cout<<m[i][j]<<" ";
    }
    cout<<"\n";
  }
}
vector<int> extract_layer(vector<vector<int>> matrix,int layer_no){
  vector<int> layer;
  int col_cnt=matrix[0].size(),row_cnt=matrix.size();
  int m=matrix.size(),n=matrix[0].size();
  for(int i=layer_no;i<n-1-layer_no;i++)
    layer.push_back(matrix[layer_no][i]);

  for(int i=layer_no;i<m-1-layer_no;i++)
    layer.push_back(matrix[i][n-1-layer_no]);

  for(int i=layer_no;i<n-1-layer_no;i++)
    layer.push_back(matrix[m-1-layer_no][n-1-i]);

  for(int i=layer_no;i<m-1-layer_no;i++)
    layer.push_back(matrix[m-1-i][layer_no]);
  return layer;
}
void rotate_layer(vector<int>& layer,int r){
  vector<int> temp;
  int n=layer.size();
  int rot=r%n;
  for(int i=0;i<rot;i++)
    temp.push_back(layer[i]);
  for(int i=rot;i<n;i++)
    layer[i-rot]=layer[i];
  int ind=0;
  for(int i=n-rot;i<n;i++)
    layer[i]=temp[ind++];
}
void manipulate_layer(vector<vector<int>>& matrix,vector<int> new_layer,int layer_no){
  int ind=0;
  int col_cnt=matrix[0].size(),row_cnt=matrix.size();
  int m=matrix.size(),n=matrix[0].size();
  for(int i=layer_no;i<n-1-layer_no;i++)
    matrix[layer_no][i]=new_layer[ind++];

  for(int i=layer_no;i<m-1-layer_no;i++)
    matrix[i][n-1-layer_no]=new_layer[ind++];

  for(int i=layer_no;i<n-1-layer_no;i++)
    matrix[m-1-layer_no][n-1-i]=new_layer[ind++];

  for(int i=layer_no;i<m-1-layer_no;i++)
    matrix[m-1-i][layer_no]=new_layer[ind++];
}
int main(int argc, char *argv[])
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,r;
  cin>>m>>n>>r;
  vector<vector<int>> matrix(m,vector<int>(n));
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>matrix[i][j];
  int x=min(m,n);
  vector<vector<int>> layers(x/2);
  for(int i=0;i<x/2;i++)
    layers[i]=extract_layer(matrix,i);
  for(int i=0;i<x/2;i++)
    rotate_layer(layers[i],r);
  for(int i=0;i<x/2;i++)
    manipulate_layer(matrix,layers[i],i);
  print_mat(matrix);
  return 0;
}
