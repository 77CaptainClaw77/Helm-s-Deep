#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int comp(const void* a,const void* b){
  return strcmp(*(const char**)a, *(const char**)b);
}
char** get_2d_pointer(int size){
  char** l=(char**)malloc(sizeof(char*)*size);
  for(int i=0;i<size;i++)
    l[i]=(char*)malloc(sizeof(char)*50);
  return l;
}
int find_in_list(char** l,int size,char* str){
  for(int i=0;i<size;i++){
    if(strcmp(str,l[i])==0)
      return 1;
  }
  return 0;
}
char** cstyle_cosequential_merge(char** l1,char** l2,int s1,int s2,int& mlist_size){
  mlist_size=0;
  int s=s1+s2;
  char** m_list=get_2d_pointer(s);
  /*for(int i=0;i<s1;i++){
    if(find_in_list(m_list,s,l1[i])==0)
      strcpy(m_list[mlist_size++],l1[i]);
  }
  for(int i=0;i<s2;i++){
    if(find_in_list(m_list,s,l2[i])==0)
      strcpy(m_list[mlist_size++],l2[i]);
      }*/
  int p1=0,p2=0;
  while(p1<s1 && p2<s2){
    if(strcmp(l1[p1],l2[p2])<0)
      strcpy(m_list[mlist_size++],l1[p1++]);
    else
      strcpy(m_list[mlist_size++],l2[p2++]);
  }
  while(p1<s1){
    strcpy(m_list[mlist_size++],l1[p1++]);
  }
  while(p2<s2){
    strcpy(m_list[mlist_size++],l2[p2++]);
  }
  char** fin_list=get_2d_pointer(s);
  int fin_size=0;
  char* temp=(char*)malloc(sizeof(char)*50);
  strcpy(temp,m_list[0]);
  strcpy(fin_list[0],temp);
  for(int i=1;i<mlist_size;i++){
    if(strcmp(m_list[i],temp)!=0){
      strcpy(fin_list[++fin_size],m_list[i]);
      strcpy(temp,m_list[i]);
    }
  }
  mlist_size=fin_size+1;
  return fin_list;
}
void read_input(char** l,int size){
  printf("Enter the names:-\n");
  for(int i=0;i<size;i++)
    cin.getline(l[i],50);
}
void display(char** l,int size){
  for(int i=0;i<size;i++)
    printf("%s\n",l[i]);
}
int main(int argc,char* argv[]){
  int n,m;
  printf("Enter the number of names in list 1: ");
  scanf("%d",&n);
  printf("Enter the number of names in list 2: ");
  scanf("%d",&m);
  char** l1=get_2d_pointer(n);
  char** l2=get_2d_pointer(m);
  scanf("%*c");
  read_input(l1,n);
  read_input(l2,m);
  qsort(l1,n,sizeof(char*),comp);
  qsort(l2,m,sizeof(char*),comp);
  printf("List 1 :-\n");
  display(l1,n);
  printf("List 2 :-\n");
  display(l2,m);
  int msize=0;
  char** merge_list=cstyle_cosequential_merge(l1,l2,n,m,msize);
  printf("Merge List :-\n");
  display(merge_list,msize);
  return 0;
}
