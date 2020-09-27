#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char getshifted(char x,char y,int flag){ //if flag is 1 shift forward otherwise backward
  char adder;
  if(isupper(x)){
    y=toupper(y);
    adder='A';
  }
  else{
    y=tolower(y);
    adder='a';
  }
  if(flag)
    return adder+(x+y-2*adder)%26;
  return adder+(x-y<0?26+x-y:x-y);
}
char* encrypt(char* message,char* key){
  int kpos=0,encpos=0,klen=strlen(key);
  char* secret=malloc(sizeof(char)*(strlen(message)+1));
  while(encpos<strlen(message)){
    secret[encpos]=getshifted(message[encpos],key[kpos],1);
    kpos=(kpos+1)%klen;
    encpos++;
  }
  return secret;
}
char* decrypt(char* secret,char* key){
  int kpos=0,decpos=0,klen=strlen(key);
  char* message=malloc(sizeof(char)*(strlen(secret)+1));
  while(decpos<strlen(secret)){
    message[decpos]=getshifted(secret[decpos],key[kpos],0);
    kpos=(kpos+1)%klen;
    decpos++;
  }
  return message;
} 
int main(int argc,char* argv[]){
  char message[100],key[100];
  scanf("%s %s",message,key);
  printf("%s\n%s",encrypt(message,key),decrypt(encrypt(message,key),key));
  return 0;
}
