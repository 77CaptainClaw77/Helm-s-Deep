#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED
//Create variable length records with delimited fields
//add indexing in terms a of an index file
//index file stores position on actual file along with search key
//index can be user id
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class FileOperations{
private:
    string index_file; //file used for indexing
    string user_data_file; //file used for storing data
    static const char tombstone='~'; //Mark acccount with ~ to delete
    public: FileOperations();
    void write_record(map<string,string> record,string index_field);
    void read_record(map<string,string>& record,int pos=0);
    int get_position(string search_key);
    vector<string> split_string_by_token(string str,char token);
    void del_account(int pos,string user_field);
};
FileOperations::FileOperations(){
    index_file="user_index_file.txt";
    user_data_file="user_data_file.txt";
}
//function to append a record at the ened of the index file and user data file
void FileOperations::write_record(map<string,string> record,string index_field){
    fstream wrt=fstream(user_data_file,ios::app);
    fstream indx=fstream(index_file,ios::app);
    string rec="";
    int pos=wrt.tellp(); //stores position of new record
    for(pair<string,string> p:record){
        rec=rec+p.second+'|';
    }
    rec=rec.substr(0,rec.size()-1); //remove last field separator
    indx<<record[index_field]<<":"<<pos<<endl;
    wrt<<rec<<"#";
    indx.close();
    wrt.close();
}
//function to read a record from the user data file stating at positon pos
void FileOperations::read_record(map<string,string>& record,int pos){
    fstream rd=fstream(user_data_file,ios::in); //open user data file and read
    rd.seekg(pos); //move to read position
    string rec;
    getline(rd,rec,'#'); //read only upto end of record
    vector<string> fields=split_string_by_token(rec,'|'); //split fields based on delimiter
    map<string,string>::iterator it=record.begin(); //vector holds the field values
    int i=0;
    while(it!=record.end()){ //iterate over map and set field values
        it->second=fields[i++];
        it++;
    }
}
//function to read position of a search key in user data file
int FileOperations::get_position(string search_key){
    fstream rd=fstream(index_file,ios::in); //open index file and read position of the record
    string index_entry;
    while(!rd.eof()){
        getline(rd,index_entry);
        if(index_entry[0]==tombstone) //If account is deleted skip
            continue;
        vector<string> ind_fields=split_string_by_token(index_entry,':'); //split into username and position in file
        if(ind_fields[0]==search_key) //here the username is found and the positon can be returned as an integer
            return stoi(ind_fields[1]);
    }
    rd.close();
    return -1;
}
//splits a string based on delimiter and returns a vector containing all the string obtained on splitting
vector<string> FileOperations::split_string_by_token(string str,char token){
    size_t prev_pos=0,pos=0;
    vector<string> fields;
    while((pos=str.find(token,pos))!=string::npos){
        fields.push_back(str.substr(prev_pos,pos-prev_pos)); //push back until token is found, do not include token
        prev_pos=pos+1;//skip token
        pos=pos+1; //to start after token
    }
    fields.push_back(str.substr(prev_pos,pos-prev_pos)); //last word after token
    return fields;
}
//function to delete an account by tombstone method
void FileOperations::del_account(int pos,string user_field){
    fstream del_wrt=fstream(user_data_file,ios::in|ios::out);
    del_wrt.seekp(pos); //move put pointer to position for placing tombstone
    del_wrt.put(tombstone);
    fstream del_index=fstream(index_file,ios::in|ios::out);
    del_index.seekg(0);//start from the beginning of the file
    string index_entry="";
    int start_pos=0;
    while(!del_index.eof()){
        getline(del_index,index_entry);
        vector<string> ind_fields=split_string_by_token(index_entry,':'); //split into username and position in file
        if(ind_fields[0]==user_field){
            del_index.seekp(start_pos);
            del_index.put(tombstone); //place tombstone on index
            break;
        }
        start_pos=del_index.tellg();
    }
    del_wrt.close();
    del_index.close();
}
#endif // FILEOP_H_INCLUDED
