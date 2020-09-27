#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* make_table(){
  char* t=malloc(sizeof(char)*26);
  int i;
  for(i=0;i<26;i++)
    t[i]='Z'-i;
  return t;
}
int main(){
  char* table=make_table();
  char message[100],answer[100];
  fgets(message,99,stdin);
  int i;
  for(i=0;i<strlen(message);i++){
    if(!isalpha(message[i])){
      putc(message[i],stdout);
      continue;
    }
    putc(isupper(message[i])?table[message[i]-'A']:table[message[i]-'a'],stdout);
  }
}
