#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class OCTAL{
	int val;
	public:OCTAL(int val){
		this->val=val;
	}
	//friend int make_decimal(OCTAL o);
	friend OCTAL operator +(OCTAL o,int k);
	friend int operator +(int k,OCTAL o);
	friend OCTAL operator >>(istream& in,OCTAL &o);
	friend ostream& operator <<(ostream& out,OCTAL o);
};
OCTAL operator >>(istream& in,OCTAL &o){
	in>>o.val;
	return o;
}
ostream& operator <<(ostream& out,OCTAL o){
	out<<o.val;
	return out;
}
int make_octal(int val){
		if(val<8)
			return val;
		return val%8+(make_octal(val/8)*10);
}/*
int make_decimal(OCTAL o){
		int dec,base;
		base=0;
		dec=0;
		int temp;
		while(o.val>0){
			temp=o.val%10;
			dec+=temp*pow(8.0,base++);
			o.val/=10;
		}
		return dec;
}*/
OCTAL operator +(OCTAL o,int k){
	//return (make_decimal(o.val)+k); defs are reversed!!
	int octal_val=0;
	int dec,base;
		base=0;
		dec=0;
		int temp;
			//cout<<"\nl1";
	while(o.val>8)
	{
			temp=o.val%10;
			dec+=temp*pow(8.0,base++);
			o.val=o.val/10;
	}
	temp=k+dec;
	cout<<temp;
	//cout<<"\nl2";
	int dig=0;
	while(temp>0){
		int mul=pow(10.0,dig);
		octal_val=octal_val+(mul*(temp%8));
		temp=temp/8;
		dig++;
	}
	return OCTAL(octal_val);
}
int operator +(int k,OCTAL o){
	//return OCTAL(make_octal(k+make_decimal(o.val)));
	int dec,base;
		base=0;
		dec=0;
		int temp;
		while(o.val>0){
			temp=o.val%10;
			dec+=temp*pow(8.0,base++);
			o.val/=10;
		}
	return (k+dec);
}

int main(){
	OCTAL o(0);
	int d,ch;
	do{
	cout<<"\n1.Conversion\n2.Additon\n3.Exit";
	cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\n1.Decimal To Octal\n2.Octal To decimal";
				cin>>ch;
				if(ch==1){
					cout<<"\nEnter the decimal number: ";
					cin>>d;
					o=OCTAL(0);
					o=o+d;
					cout<<"\nThe octal value of "<<d<<" is "<<o;
				}
				else{
					cout<<"\nEnter the octal number: ";
					cin>>o;					
					d=(0+o); 
					cout<<"\nThe decimal value of "<<o<<" is "<<d;
				}
		break;
		case 2:cout<<"\nResult in \n1.Octal\n2.Decimal";
				cin>>ch;
				cout<<"\nEnter the decimal";
				cin>>d;
				cout<<"\nEnter the octal number";
				cin>>o;
				if(ch==1)
					cout<<"\nThe result is "<<(o+d);
				else
					cout<<"\nThe result is "<<(d+o);
		break;
		case 3:exit(0);
		default:cout<<"\nInvalid Choice!!";
	}
	}while(1);
	return 0;
}
