#include <bits/stdc++.h>
using namespace std;
int modded_exponent(int x,int p,int m){
  int ans=1;
  for(int i=0;i<p;i++)
    ans=(ans*x)%m;
  return ans;
}
int main(int argc, char *argv[])
{
  int p,q,n,totient,e,d;
  cout<<"Enter two primes: ";
  cin>>p>>q;
  n=p*q;
  totient=(p-1)*(q-1);
  cout<<"Enter the value of e: ";
  cin>>e;
  bool priv_key_exists=false;
  for(int i=1;i<totient;i++){
    if((i*e-1)%totient==0){
      d=i;
      priv_key_exists=true;
      break;
    }
  }
  if(!priv_key_exists){
    cout<<"RSA encryption cannot be applied with the given parameters!";
    exit(0);
  }
  cout<<"n: "<<n<<"\te: "<<e<<"\td: "<<d<<"\n";
  cout<<"Enter the message: ";
  int x;
  cin>>x;
  int encrypted=modded_exponent(x,e,n);
  cout<<"Encrypted Message: "<<encrypted;
  int decrypted=modded_exponent(encrypted,d,n);
  cout<<"\nDecrypted Message: "<<decrypted;
  return 0;
}
