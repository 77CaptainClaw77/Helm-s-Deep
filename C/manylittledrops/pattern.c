#include <stdio.h>
int main()
{
  int n,i,j,temp,num;
  printf("Enter a number:");
  scanf("%d",&n);
  num=n;
  for(i=0;i<n;i++)
    {
      temp=n;
      for(j=0;j<n;j++)
	{
	  printf("%d\t",temp);
	  if(temp>num)
	    temp--;
	}
      printf("\n");
      num--;
    }
  return 0;  
}
