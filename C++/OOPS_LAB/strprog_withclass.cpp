#include <iostream>
#include <cstring>
using namespace std;
class STR{
	int len;
	char *str;
	public:STR(char s[]){
		len=strlen(s)+1;
		str=new char[len];
		strcpy(str,s);
	}
	STR(){
		len=1;
		str=new char[len];
		str[0]='\0';	
	}
	friend void del(char* origstr,int dpos,int slen);
	friend void assign_and_call(STR s1,STR s2);
	friend int operator >(STR s1,STR s2);
};
void del(char* origstr,int dpos,int slen){
	char* nstr=new char[20];//new string
	int k=0;
	for(int i=0;i<strlen(origstr);i++){
		if(i>=dpos && i<=dpos+slen-1)
			continue;
		nstr[k]=origstr[i];
		k++;
	}
	cout<<endl<<nstr<<"\n";
}
void assign_and_call(STR s1,STR s2){
	bool revmatch=false;
	int pos=-1;
	if(s1.len>s2.len){
		revmatch=true;
		pos=s2>s1;
	}
	else
		pos=s1>s2;
	cout<<pos;
	if(pos!=-1){
		if(revmatch)
			del(s1.str,pos,s2.len);
		else
			del(s2.str,pos,s1.len);
	}
	else
		cout<<"\nSubstring not found";
}

int operator >(STR s1,STR s2){
	int m=s1.len;
	int n=s2.len;
	int matchpos=-1;
	for(int i=0;i<n-m+1;i++){
		matchpos=i;
		for(int j=0;j<m;j++){
			if(s1.str[j]!=s2.str[i+j]){
				matchpos=-1;
				break;
			}
		}
		if(matchpos!=-1)
			return matchpos;
	}
	return -1;		
}
int main(){
	char *s1=new char[20];
	char *s2=new char[20];
	cout<<"\nEnter the first string";
	cin>>s1;
	cout<<"\nEnter the second string";
	cin>>s2;
	STR string1,string2;
	string1=STR(s1);
	string2=STR(s2);
	assign_and_call(string1,string2);
	return 0;	
}
