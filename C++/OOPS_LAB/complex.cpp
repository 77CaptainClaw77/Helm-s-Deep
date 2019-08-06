#include <iostream>
#include <cmath>
using namespace std;
class complex{
	float x,y;
	public:
	complex(int x,int y){
		this->x=x;
		this->y=y;
	}
	complex(){}
	void operator -(){
		x=-x;
		y=-y;
	}
	complex operator -(complex c){
		return complex(x-c.x,y-c.y);
	}
	complex operator +(complex c){
		return complex(x+c.x,y+c.y);
	}
	complex operator *(complex c){
		return complex((x*c.x-y*c.y),(x*c.y+y*c.x));	
	}
	friend istream& operator >>(istream &in,complex& c);
	friend ostream& operator <<(ostream &out,complex& c);
};
istream& operator >>(istream &in,complex &c){
		cout<<"\nEnter the real part";
		in>>c.x;
		cout<<"\nEnter the imaginary part";
		in>>c.y;
		return in;
	}
ostream& operator <<(ostream &out,complex& c){
	out<<endl<<c.x<<" + "<<c.y<<"i"<<endl;
	return out;
}
int main(){
 complex c,c1,c2;
 //complex c2(5,6);
 //cout<<c2;
 cin>>c;
 cout<<c;
 -c;
 cout<<c;
 cin>>c1;
 cin>>c2;
 c=c1+c2;//addition
 cout<<c;
 c=c1-c2;//subtraction
 cout<<c;
 c=c1*c2;//multiplication
 cout<<c;
 return 0;
}
