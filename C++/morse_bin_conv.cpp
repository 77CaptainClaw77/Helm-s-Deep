//code to convert morse like binary to binary
#include <iostream>
#include <cstring>
int main(int argc,char* argv[]){
  if(argc>1){
    for(int i=1;i<argc;i++){
      for(int j=0;j<strlen(argv[i]);j++){
	if(argv[i][j]=='-')
	  std::cout<<"1";
	else
	  std::cout<<"0";
      }
      std::cout<<std::endl<<std::endl;
      for(int j=0;j<strlen(argv[i]);j++){
	if(argv[i][j]=='.')
	  std::cout<<"1";
	else
	  std::cout<<"0";
      }
    }
  }
}
