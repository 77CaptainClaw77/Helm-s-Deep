#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1000
int main(int argc, char *argv[])
{
  mkfifo("Requests.fifo",0777);
  mkfifo("Responses.fifo",0777);
  int req_fd=open("Requests.fifo",O_RDONLY);
  int res_fd=open("Responses.fifo",O_WRONLY);
  char buffer[BUF_SIZE];
  char fname[50];
  read(req_fd,fname,sizeof(fname));
  int op_file=open(fname,O_RDONLY);
  int byte_cnt;
  while((byte_cnt=read(op_file,buffer,sizeof(buffer)))>0)
    write(res_fd,buffer,byte_cnt);
  close(req_fd);
  close(res_fd);
  unlink("Requests.fifo");
  unlink("Responses.fifo");
  return 0;
}
