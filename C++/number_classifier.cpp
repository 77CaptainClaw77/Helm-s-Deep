#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
class number_classifier
{
  vector<int> number_set,primes,composites,odds,evens,positives,negatives;
  void get_input();
  void generate_random_input();
  public:void classify();
};
bool is_prime(int n)
{
  for(int i=2;i<n;i++)
    if(n%i==0)
      return false;
  return true;
}
void print_vector(vector<int> v){
  for(int a:v)
    cout<<a<<" ";
}
void number_classifier::get_input(){
  int n;
  cout<<"Enter the number of values to be classified";
  cin>>n;
  cout<<"Enter the space separated list of values:-\n";
  for(int i=0;i<n;i++)
    {int temp;
      cin>>temp;
      number_set.push_back(temp);
    }
}
void number_classifier::generate_random_input(){
  srand(time(NULL));
  int n;
  cout<<"Enter the number of values to be generated randomly";
  cin>>n;
  for(int i=0;i<n;i++)
    number_set.push_back((rand()%(n*100))-(n*50));
}
void number_classifier::classify(){
  char ch;
  cout<<"Press y to input values, press any other key for random input";
  cin>>ch;
  if(ch=='y' || ch=='Y')
    get_input();
  else
    generate_random_input();
  for(int num:number_set)
    {
      if(num>0)
	positives.push_back(num);
      else
	negatives.push_back(num);
      if(num%2==0)
	evens.push_back(num);
      else
	odds.push_back(num);
      if(is_prime((num>0?num:-num)))
	primes.push_back(num);
      else
	composites.push_back(num);
    }
  cout<<endl<<"Number Set: ";
  print_vector(number_set);
  cout<<endl<<"Positive Numbers: ";
  print_vector(positives);
  cout<<endl<<"Negative Numbers: ";
  print_vector(negatives);
  cout<<endl<<"Odd Numbers: ";
  print_vector(odds);
  cout<<endl<<"Even Numbers: ";
  print_vector(evens);
  cout<<endl<<"Prime Numbers: ";
  print_vector(primes);
  cout<<endl<<"Composite Numbers: ";
  print_vector(composites);
}
int main()
{
  char ch;
  do{
  number_classifier nc;
  nc.classify();
  cout<<"\nPress y to continue any other key to stop";
  cin>>ch;
  }while(ch=='y');
  return 0;
}
