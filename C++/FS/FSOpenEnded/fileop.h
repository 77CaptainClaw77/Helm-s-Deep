#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED
//Create variable length records with delimited fields
//add indexing in terms a of an index file
//index file stores position on actual file along with search key
//index can be user id
#include <fstream>
#include <vector>
#include <map>
class FileOperations{
private:string index_file;
    string user_data_file;
    public: FileOperations();
    void write_record(map<string,string> record);
    void read_record(map<string,string>& record,int pos=0);

};
FileOperations::FileOperations(){
    index_file="user_index_file.txt";
    user_data_file="user_data_file.txt";
}
void write_record(map<string,string> record){
    string rec="";
    for(pair<string,string> p:record)
        rec=rec+p.second+'|';

}
void read_record(map<string,string>& record){

}
#endif // FILEOP_H_INCLUDED
