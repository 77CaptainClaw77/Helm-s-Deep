#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t pid;
  pid=fork();
  if(pid==0)
    {
      printf("\nNow im in the child process which is executed successfully!");
      execlp("/bin/mkdir","mkdir","PROCESS_CREATED_DIR",NULL);
    }
  else if(pid<0)
    {
      fprintf(stderr,"\nChild Process Creation Failed :(");
      exit(-1);
    }
  else
    {
      printf("\nIn the parent, the child process id is %d",pid);
      wait(NULL); //waits for the child process
      exit(0);
    }
  return 0;
}
