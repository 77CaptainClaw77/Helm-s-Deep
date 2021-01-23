#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define BUF_SIZE 1000
int main(int argc, char *argv[])
{
  int req_fd=open("Requests.fifo",O_WRONLY);
  int res_fd=open("Responses.fifo",O_RDONLY);
  char buffer[1000];
  printf("Enter the filename: ");
  char fname[50];
  scanf("%s",fname);
  write(req_fd,fname,sizeof(fname));
  int byte_cnt;
  while((byte_cnt=read(res_fd,buffer,sizeof(buffer)))>0)
    puts(buffer);
  close(req_fd);
  close(res_fd);
  return 0;
}
