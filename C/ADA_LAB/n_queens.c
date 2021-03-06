#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define boolean unsigned char;
boolean board_is_valid(int** board,int n,int new_xpos,int new_ypos)
{
  int rc=0,cc=0,diag_count=0,counter_diag_count=0,i=0,j=0;
  for(i=0;i<n;i++)
    {    
      if(board[new_xpos][i]==1)
	rc++;
      if(board[i][new_ypos]==1)
	cc++;
    }
  if(rc>0 || cc>0)
    return false;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(abs(new_xpos-i)==abs(new_ypos-j) && board[i][j]==1)
	return false;
  return true;
}
void get_nqueens_positions(int** board,int n,int at_row)
{
  int i=0,j=0,k=0;
  if(at_row>=n)
    return;
  if(at_row==n)
    {
      for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
	    printf("%d\t",board[i][j]);
	  printf("\n");
	 }
       }
  for(j=0;j<n;j++)
    {
      if(board_is_valid(board,n,at_row,j))
	{
	  printf("here with %d %d\n",at_row,j);
	  int** temp=(int**)malloc(n*sizeof(int*));
	  for(k=0;k<n;k++)
	    {
	      temp[k]=(int*)malloc(sizeof(int)*n);
	      memcpy(temp[k],board[k],n);
	    }
	  temp[at_row][j]=1;
	  get_nqueens_positions(temp,n,at_row+1);
	}
    }
}
int main()
{
  int n,i,j;                                    
  printf("Enter the value of n: ");
  scanf("%d",&n);
  int** arr=(int**)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)
    *(arr+i)=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      arr[i][j]=0;
  get_nqueens_positions(arr,n,0);
}
