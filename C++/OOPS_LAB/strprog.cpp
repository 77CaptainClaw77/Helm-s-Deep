#include <iostream>
#include <cstring>
using namespace std;
int BruteForceStringMatch(char *s1,char *s2){
	int m=strlen(s1);
	int n=strlen(s2);
	int matchpos=-1;
	for(int i=0;i<n-m+1;i++){
		matchpos=i;
		for(int j=0;j<m;j++){
			if(s1[j]!=s2[i+j]){
				matchpos=-1;
				break;
			}
		}
		if(matchpos!=-1)
			return matchpos;
	}
	return -1;
}
void stringdel(char* origstr,int dpos,int slen){//slen:length of substring, dpos:delete position
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
int main(){
	char *s1=new char[20];
	char *s2=new char[20];
	bool revmatch=false;//Indicates is s1>s2 then we need to reverse this.
	cout<<"\nEnter the first string";
	cin>>s1;
	cout<<"\nEnter the second string";
	cin>>s2;
	int pos;
	if(strlen(s1)>strlen(s2)){
		revmatch=true;
		pos=BruteForceStringMatch(s2,s1);
	}
	else
		pos=BruteForceStringMatch(s1,s2);
	cout<<pos;
	if(pos!=-1){
		if(revmatch)
			stringdel(s1,pos,strlen(s2));
		else
			stringdel(s2,pos,strlen(s1));
	}
	else
		cout<<"\nSubstring not found";
}
