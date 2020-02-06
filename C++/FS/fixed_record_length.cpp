#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class student{
private:char* name;
  char* usn;
  char* phone;
  float cgpa;
public:char* get_name();
  char* get_usn();
  char* get_phone();
  char* get_cgpa();
  student(char* name,char* usn,char* phone,float cgpa);
  void get_fieldset(char** fields);
};
student::student(char* name,char* usn,char* phone,float cgpa){
  strcpy(this->name,name);
  strcpy(this->usn,usn);
  strcpy(this->phone,phone);
  this->cgpa=cgpa;
}
char* student::get_name(){return name;}
char* student::get_usn(){return usn;}
char* student::get_phone(){return phone;}
char* student::get_cgpa(){
  stringstream ss;
  ss<<fixed<<setprecision(2)<<cgpa;
  string str=ss.str();
  return str;
}
void student::get_fieldset(char** fields){
  fields=malloc(sizeof(char)*4);
  int i;
  for(i=0;i<4;i++)
    fields[i]=malloc(sizeof(char)*20);
  strcpy(fields[0],get_name());
  strcpy(fields[1],get_usn());
  strcpy(fields[2],get_phone());
  strcpy(fields[3],get_cgpa());
}
class file_reader{
private:char delimiter;
  int* field_sizes;
  int no_of_fields;
  char padding;
public:file_reader(char delimiter,char padding='#'); //for delimited fields
  file_reader(int* field_sizes,int no_of_fields,char padding='#'); //for fixed no of fields
  void read_fixed_fields_record(char** fields);
  void read_delimited_fields_record(char** fields);
};
file_reader::file_reader(char delimiter,char padding='#'){
  this->delimiter=delimiter;
  this->padding=padding;
}
file_reader::file_reader(int* field_sizes,int no_of_fields,char padding='#'){
  this->no_of_fields=no_of_fields;
  this->field_sizes=malloc(sizeof(int)*no_of_fields);
  int i;
  for(i=0;i<no_of_fields;i++)
    this->field_sizes[i]=field_sizes[i];
  this->padding=padding;
}
void file_reader::read_fixed_fields_record(char** fields){
  char* buffer="";
  fields=malloc(sizeof(char)*no_of_fields);
  int i;
  for(i=0;i<no_of_fields;i++)
    field_sizes=malloc(sizeof(char)*field_sizes[i]);
  for(i=0;i<no_of_fields;i++){
    getline(fp,buffer,field_sizes[i],padding);
    strcpy(fields[i],buffer);
  }
}
void file_reader::read_delimited_fields_record(char** fields){
  fields=malloc(sizeof(char)*no_of_fields);
  int i;
  for(i=0;i<no_of_fields;i++)
    field_sizes=malloc(sizeof(char)*field_sizes[i]);
  for(i=0;i<no_of_fields;i++){
    getline(fp,buffer,delimiter);
    strcpy(fields[i],buffer);
  }
}
class file_writer{
private:char delimiter;
  int* field_sizes;
  int no_of_fields;
  char padding;
  char* filename;
  fstream fp;
  static const int default_record_length=100; 
  int record_length=default_record_length;
  void set_file_pointer(char* filename){fp=fstream(filename,ios::app); }
  public:file_writer(char delimiter,char padding='#'); //for delimited fields
  file_writer(int* field_sizes,int no_of_fields,char padding='#'); //for fixed no of fields
  void write_fixed_fields_record(char** fields);
  void write_delimited_fields_record(char** fields);
  void set_filename(char* fname){set_file_pointer(fname);}
  void set_record_length(int l){record_length=l;}
  void pad_buffer(char* buffer,int n);
};
file_writer::file_writer(char delimiter,char padding='#'){
  this->delimiter=delimiter;
  this->padding=padding;
}
file_writer::file_writer(int* field_sizes,int no_of_fields,char padding='#'){
  this->no_of_fields=no_of_fields;
  this->field_sizes=malloc(sizeof(int)*no_of_fields);
  int i;
  for(i=0;i<no_of_fields;i++)
    this->field_sizes[i]=field_sizes[i];
  this->padding=padding;
}
void file_writer::pad_buffer(char* buffer,int n){
  int i;
  for(i=0;i<n;i++)
    strcat(buffer,padding);
}
void file_writer::write_fixed_fields_record(char** fields){
  char* buffer="";
  int i;
  for(i=0;i<no_of_fields;i++){
    strcat(buffer,fields[i]);
    int pad_len=field_sizes[i]-strlen(fields[i]);
    pad_buffer(buffer,pad_len);
  }
  fp<<buffer;
}
void file_writer::write_delimited_fields_record(char** fields){
  char* buffer="";
  int i;
  for(i=0;i<no_of_fields;i++){
    strcat(buffer,fields[i]);
    strcat(buffer,delimiter);
  }
  int pad_len=record_length-strlen(buffer);
  pad_buffer(buffer,pad_len);
  fp<<buffer;
}
int main(){
  char* delimited_fields_filename="delim_field_file.txt";
  int n;
  cout<<"Enter number of students";
  cin>>n;
  student s[n];
  int i;
  char* name;
  char* ph;
  char* usn;
  float cgpa;
  cin.getline(name,100);
  for(i=0;i<n;i++){
    float cgpa;
    cout<<"Enter student name: ";
    cin.getline(name,100);
    cout<<"Enter student phone: ";
    cin.getline(ph,100);
    cout<<"Enter student usn: ";
    cin.getline(usn,100);
    cout<<"Enter student cgpa: ";
    cin>>cgpa;
    s[i]=student(name,usn,ph,cgpa);
  }
  file_writer fw=file_writer('|');
  fw.set_filename(delimited_fields_filename);
  fw.set_record_length(30);
  for(i=0;i<4;i++){
    char** field_set;
    s[i].get_fieldset(field_set);
    fw.write_delimited_fields_record(field_set);
  }
  return 0;
}
