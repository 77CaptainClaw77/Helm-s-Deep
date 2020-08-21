#include <bits/stdc++.h>
using namespace std;
bool prime(int ele){
  set<int> pl={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
  return pl.find(ele)!=pl.end()?true:false;
}
int main(int argc, char *argv[])
{
  int D,P;
  cin>>D>>P;
  vector<int> start_points;
  int count=0;
  for(int i=0;i<P;i++)
    start_points.push_back(i*(D/P));
  for(int i=0;i<D/P;i++){
    bool is_prime=true;
    for(size_t j=0;j<start_points.size();j++){
      if(!prime(start_points[j]+i)){
	is_prime=false;
	break;
      }
    }
    if(is_prime) count++;
  }
  cout<<count;
  return 0;
}
