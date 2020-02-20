#include <iostream>
class delim_fields_records_fixed_buffer{
 private:static char record_delimiter='#';
  static char field_delimiter='|';
  static char padding='*';
  char* buffer;
  int record_size;
  int pos;
 public:
  delim_fields_records_fixed_buffer(int record_size);
  void pack(char* str);
  void unpack(char* str);
  void clear();
  void pad();
  void write_stream(ostream& stream);
  void read_stream(istream& stream);
};
