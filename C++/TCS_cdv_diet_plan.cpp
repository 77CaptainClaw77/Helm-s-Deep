#include <bits/stdc++.h>
using namespace std;
//for every combination, we need to compute shortfall and diversity as absolute values
// here return false if the combination is not possible, ie any one shortfall is less than 0
bool get_absolute_values(vector<int>& diet,vector<vector<int>>& food_vals,vector<int>& proposed_vals,pair<vector<int>,int>& vals){
  int p_sf=0,c_sf=0,f_sf=0;
  for(size_t i=0;i<food_vals.size();i++){
    p_sf+=food_vals[i][0]*proposed_vals[i];
    c_sf+=food_vals[i][1]*proposed_vals[i];
    f_sf+=food_vals[i][2]*proposed_vals[i];
  }
  p_sf=diet[0]-p_sf;
  c_sf=diet[1]-c_sf;
  f_sf=diet[2]-f_sf;
  if(p_sf<0 || c_sf<0 || f_sf<0) 
    return 0;
  int diversity=max(max(p_sf,c_sf),f_sf)-min(min(p_sf,c_sf),f_sf);
  vector<int> shortfalls={p_sf,c_sf,f_sf,p_sf+c_sf+f_sf};
  vals=make_pair(shortfalls,diversity);
  return true;
}
void compute_minimum_shortfall(vector<int>& diet,vector<vector<int>>& food_vals,vector<int> proposed_solution,pair<vector<int>,int>& best_solution){
  pair<vector<int>,int> soln;
  // for(int i:proposed_solution){
  //   cout<<i<<" ";
  // }
  //cout<<"\n";
  if(get_absolute_values(diet,food_vals,proposed_solution,soln)){
    //check if better than best and call next iteration
    if(soln.first[3]<best_solution.first[3] || (soln.first[3]==best_solution.first[3] && soln.second<best_solution.second))
      best_solution=soln;
    for(size_t i=0;i<food_vals.size();i++){
      vector<int> new_soln=proposed_solution;
      new_soln[i]++;
      compute_minimum_shortfall(diet,food_vals,new_soln,best_solution);
    }
  }
  return;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  //two things are important - 1. Shortfall 2. Diversity
  //only minimum shortfall solution is required
  vector<int> min_shortfall(3); //store shortfall of all three types
  int food_counts;
  string required,foods;
  getline(cin,required);
  getline(cin,foods);
  vector<int> diet(3);
  int temp=0;
  
  //read_requried diet
  for(size_t i=0;i<required.size();i++){
    if(isdigit(required[i]))
      temp=(temp*10)+(required[i]-'0');
    else if(isalpha(required[i])){
      if(required[i]=='P') diet[0]=temp;
      else if(required[i]=='C') diet[1]=temp;
      else diet[2]=temp;
    }
    else
      temp=0;
  }
  vector<vector<int>> food_vals;
  vector<int> food_val(3);
  temp=0;
  
  //read all food vals
  for(size_t i=0;i<foods.size();i++){
    if(isdigit(foods[i]))
      temp=(temp*10)+(foods[i]-'0');
    else if(isalpha(foods[i])){
      if(foods[i]=='P') food_val[0]=temp;
      else if(foods[i]=='C') food_val[1]=temp;
      else food_val[2]=temp;
    }
    else if(foods[i]=='|'){
      food_vals.push_back(food_val);
      temp=0;
    }
    else
      temp=0;
  }
  food_vals.push_back(food_val);
  vector<int> base_solution={0,0,0};
  pair<vector<int>,int> best_solution;
  vector<int> start_state={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
  int div=INT_MAX;
  best_solution=make_pair(start_state,div);
  compute_minimum_shortfall(diet,food_vals,base_solution,best_solution);
  //cout<<"\n";
  for(size_t i=0;i<best_solution.first.size()-1;i++)
    cout<<best_solution.first[i]<<" ";
  return 0;
}
