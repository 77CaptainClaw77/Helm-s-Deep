#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INVALID_USE 1
#define FILE_OPERATION_ERROR 2
#define START_QUEUE_SIZE 5
typedef struct
{
  char* process_name;
  long burst_time;
  int arrival_time;
  int entry_time;
  int burst_completed;
}process_control_block;

int main(int argc,char* argv[])
{
  int time_quantum=0;
  int process_count=0;//Counts the total number of processes
  int process_queue_size=START_QUEUE_SIZE;//Keeps track of the size of the queue in which 
  process_control_block* process_queue=malloc(sizeof(process_control_block)*process_queue_size);
  int mode=argc==1?0:(argc==2?1:2); //File read is 1  user input is 0   2 is invalid mode
  if(mode==2)
    {
      printf("Invalid use!!\n");
      exit(INVALID_USE);
    }
  if(mode)
    {
      FILE* process_reader=fopen(argv[1],"r");
      char* temp=malloc(100*sizeof(char));
      int temp_val_a;
      long temp_val_b;
      if(process_reader==NULL)
	{
	  printf("%s",argv[1]);
	  fprintf(stderr,"Error Opening File!\n");
	  exit(FILE_OPERATION_ERROR);
	}
      while(fscanf(process_reader,"%s %d %ld",temp,&temp_val_a,&temp_val_b)!=EOF)
	{
	  printf("%s %d %ld",temp,temp_val_a,temp_val_b);
	  if(process_count==process_queue_size-1)
	    {
	      process_queue=realloc(process_queue,process_queue_size*2*(sizeof(process_control_block)));
	      process_queue_size*=2;
	    }
		process_queue[process_count].process_name=malloc((strlen(temp)+1)*sizeof(char));
		process_queue[process_count].arrival_time=temp_val_a;
		process_queue[process_count].burst_time=temp_val_b;
		process_queue[process_count].burst_completed=0;
		process_queue[process_count].entry_time=0;
		strcpy(process_queue[process_count].process_name,temp);
		process_count++;
	}
      int i=0;
      fclose(process_reader);
    }
 else
    {
		printf("Enter the number of processes: ");
		scanf("%d",&process_queue_size);
		int i=0;
		for(i=0;i<process_queue_size;i++)
		{
		  printf("Process %d\n",(i+1));
		  //fflush(stdin);
		  process_queue[process_count].process_name=malloc(100*sizeof(char));
			printf("Enter the name of the process: ");
			scanf("%s",process_queue[i].process_name);
			//fflush(stdin);
			printf("Enter the arrival time of the process: ");
			char junk=getchar();
			//junk=getchar();
			scanf("%d",&(process_queue[i].arrival_time));
			printf("Enter the burst time of the process: ");
			scanf("%ld",&(process_queue[i].burst_time));
			process_count++;
			process_queue[i].burst_completed=0;
			process_queue[i].entry_time=0;
			printf("\n\n");
		}
	}

printf("Enter the time quantum:");
scanf("%d",&time_quantum);
long waiting_time=0,turnaround_time=0,cur_time=0;
int i,j;
//Building FIFO Queue same as sorted array.
for(i=1;i<process_count;i++)
  {
    for(j=0;j<process_count-i;j++)
      {
	if(process_queue[j].arrival_time>process_queue[j+1].arrival_time)
	  {
	    process_control_block temp_block;
	    temp_block=process_queue[j];
	    process_queue[j]=process_queue[j+1];
	    process_queue[j+1]=temp_block;
	  }
      }
  }
	printf("\nOrder Of Execution Of Processes:-");
while(1)
  {
    int proc_exec_count=0;
	int proc_complete_count=0;
    for(i=0;i<process_count;i++)
      {
	if(cur_time<process_queue[i].arrival_time)
	{
	  continue;
	}
	if(process_queue[i].burst_completed==process_queue[i].burst_time)
	 {
		 proc_complete_count++; 
		 continue;
	 }
	if(process_queue[i].burst_time-process_queue[i].burst_completed<=time_quantum)
	  {
	    waiting_time+=cur_time-process_queue[i].entry_time-process_queue[i].burst_completed-process_queue[i].arrival_time;
	    cur_time+=process_queue[i].burst_time-process_queue[i].burst_completed;
	    process_queue[i].burst_completed=process_queue[i].burst_time;
	    proc_exec_count++;
		printf("Process %s at time %ld",process_queue[i].process_name,cur_time);
	  }
	else
	  {
	    if(process_queue[i].burst_completed==0)
	      process_queue[i].entry_time=cur_time;
	    process_queue[i].burst_completed+=time_quantum;
	    cur_time+=time_quantum;
	    proc_exec_count++;
	  }
      }
	printf("%d",proc_exec_count);
    if(proc_exec_count==0)
      cur_time++;
    if(proc_complete_count==process_count)
      break;
  }
turnaround_time=waiting_time;
for(i=0;i<process_count;i++)
	  turnaround_time+=process_queue[i].burst_time;
printf("\nTotal Waiting Time: %ld",waiting_time);
	printf("\nTotal Turnaround Time: %ld",turnaround_time);
	printf("\nAverage Waiting Time: %lf",(waiting_time/(process_count+0.0)));
	printf("\nTotal Turnaround Time: %lf",(turnaround_time/(process_count+0.0)));
}
