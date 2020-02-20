#include "delimited_fields_records.h"
#include "student.h"
#include <vector>
#include <cstring>
#include <cstdlib>
#include BUFFER_OVERFLOW 1
//Buffer implementation
delim_fields_records_fixed_buffer::delim_fields_records_fixed_buffer(int record_size){
  this->record_size=record_size;
  this->buffer=malloc(sizeof(char)*record_size);
  this->pos=0;
}
void delim_fields_records_fixed_buffer::clear(){
  pos=0;
  buffer[0]='\0';
}
void delim_fields_records_fixed_buffer::pad(){
  while(pos<record_size-1)
    buffer[pos++]=padding;
  buffer[pos]=record_delimiter;
}
void delim_fields_records_fixed_buffer::pack(char* str){
  strcat(buffer,str);
  strcat(buffer,field_delimiter);
  pos=strlen(buffer);
  if(pos>=record_size){
    std::cout << "\nBuffer Overflow: "<<pos;
    exit(BUFFER_OVERFLOW);
  }
}
void delim_fields_records_fixed_buffer::unpack(char* str){
  
}
//Student implementation
student::student(){}
student::student(char* name,char* usn){
  strcpy(this->name,name);
  strcpy(this->usn,usn);
}
student::pack(delim_fields_records_fixed_buffer buff){
  buff.pack(name);
  buff.pack(usn);
  buff.pad();
}
student::unpack(delim_fields_records_fixed_buffer buff){
  buff.unpack(name);
  buff.unpack(usn);
}
//Main function
int main(int argc, char *argv[])
{
  char ch;
  std::vector<student> st;
  //User input
  std::cout << "Enter the student details";
  do{
    char name[25];
    char usn[11];
    std::cout << "\nStudent name: ";
    std::cin.getline(name,25,'\n');
    std::cout << "\nStudent usn: ";
    std::cin.getline(usn,11,'\n');
    st.push_back(student(name,usn));
    std::cout << "Press \'y\' to continue";
    std::cin >> ch;
  }while(ch=='y');
  //User operations
  do{
    std::cout << "\nSelect the desired option:-" << "\n1.Modify\n2.Display\n3.Search\n4.Exit";
    std::cin >> ch;
    if (ch=='1') {
      
    }
    if (ch=='2') {
      
    }
    if (ch=='3') {
      
    }
  }while(ch!='4');
  return 0;
}
