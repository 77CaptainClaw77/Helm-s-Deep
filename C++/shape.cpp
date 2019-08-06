#include  <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
enum selection{RECTANGLE=1,TRIANGLE,CIRCLE,QUIT};
class SHAPE
{
	protected:float a,b,c;
	float area;
	public:SHAPE(){
	}
	virtual float area_compute(){
	}
	void display(){
		cout<<"\nThe area of the figure is "<<area;
	}
			
};
class triangle : public SHAPE{
	
	public:triangle(float x,float y,float z)
	{
		a=x;
		b=y;
		c=z;
	}
	triangle(){
	}
	float area_compute(){
		float s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
	} 
};
class circle : public SHAPE{
	
	public:circle(float a){
		this->a=a;
		this->b=this->c=0;
	}
	circle(){}
	float area_compute(){
		area=3.141*a*a;
	} 
};
class rectangle : public SHAPE{
	
	public:rectangle(float a,float b){
		this->a=a;
		this->b=b;
		this->c=0;
	}
	rectangle(){}
	float area_compute(){
		area=a*b*1.0;
	} 
};
void exitrequest(){
	do{
	cout<<"\nAre you sure you want to exit, press \'y\' for yes press \'n\' for no:";
	char ch;
	cin>>ch;
	if(ch=='y')	
		exit(0);
	if(ch=='n')
		return;
	}while(1);
}
int main(){
	cout<<"\nSelect the desired option";
	int a,b,c;
	SHAPE *s;
	rectangle r;
	circle cir;
	triangle t;
	do{
		cout<<"\n1.Rectangle\n2.Triangle\n3.Circle\n4.Exit";
		cout<<"\nYour Choice:";
		int choice;
		cin>>choice;
		switch(choice){
			case RECTANGLE:cout<<"\nEnter the sides of the rectangle";
					cin>>a>>b;
					r=rectangle(a,b);
					s=&r;
					s->area_compute();
					s->SHAPE::display();
					break;
			case TRIANGLE:cout<<"\nEnter the sides of the triangle";
					cin>>a>>b>>c;
					t=triangle(a,b,c);
					s=&t;
					s->area_compute();
					s->SHAPE::display();
					break;
			case CIRCLE:cout<<"\nEnter the radius of the circle";
						cin>>a;
						cir=circle(a);
						s=&cir;
						s->area_compute();
						s->SHAPE::display();
						break;
			case QUIT:exitrequest();
						break; 
		}
	}while(1);	
	return 0;
}


