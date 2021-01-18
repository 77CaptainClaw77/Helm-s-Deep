#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
size_t perform_tasks(char* buffer,size_t item_size,size_t item_cnt,void* req_pointer){
  size_t byte_cnt=item_cnt*item_size;
  static int byte_num=1,line_number=1;
  printf("Data Chunk %d Size: %ld\n",byte_num++,byte_cnt);
  printf("%d: ",line_number++);
  int i;
  for(i=0;i<item_cnt;i++){
    printf("%c",buffer[i]);
    if(buffer[i]=='\n')
      printf("%d: ",line_number++);
  }
  printf("\n\n");
  return byte_cnt;//return number of bytes read, if less than size of buffer, then implies error has occured and stops
}
int main(int argc, char *argv[])
{
  CURL* curl_handle=curl_easy_init(); //create handle
  if(curl_handle==NULL){
    fprintf(stderr, "Init Failed!");
    return 1; 
  }
  curl_easy_setopt(curl_handle,CURLOPT_URL,"https://scrap.tf/"); //set url, ftp is also supported
  curl_easy_setopt(curl_handle,CURLOPT_WRITEFUNCTION,perform_tasks);//set callback function on every succesful read
  CURLcode res=curl_easy_perform(curl_handle); //perform action according to set option
  if(res!=CURLE_OK){
    fprintf(stderr,"Action error! : %s",curl_easy_strerror(res));
    return 1;
  }
  curl_easy_cleanup(curl_handle); //free memory
  return 0;
}
