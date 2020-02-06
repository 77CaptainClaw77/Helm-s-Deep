#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comparision_count=0;
int* shift_generator(char* pattern)
{
  int i;
  int* shft=(int*)malloc(sizeof(int)*128);
  for(i=0;i<128;i++)
    *(shft+i)=strlen(pattern);
  for(i=0;i<strlen(pattern)-1;i++)
    shft[pattern[i]]=strlen(pattern)-i-1;
   for(i=0;i<128;i++)
     {if(shft[i]!=strlen(pattern))
	 printf("%c\t",i);
     }
   printf("\n");
  for(i=0;i<128;i++)
     {if(shft[i]!=strlen(pattern))
	 printf("%d\t",shft[i]);
     }
   return shft;
}
int horspool_matching(char* text,char* pattern,int* shft)
{
  int i=strlen(pattern)-1,count=0;
  while(i<strlen(text))
    {
      count=0;
      while(count<strlen(pattern) &&  text[i-count]==pattern[strlen(pattern)-1-count])
	count++;
      comparision_count+=count+1;
      if(count==strlen(pattern))
	return i-strlen(pattern)+1;
      i=i+shft[text[i]];
    }
  return -1;
}
int main()
{
  char pattern[1000],text[1000],ch;
  int i=0;
  printf("Enter the text: ");
  while(1)
    {
    scanf("%c",&ch);
    if(ch!='\n')
      text[i++]=ch;
    else
      break;
    }text[i]='\0';
  i=0;
  printf("Enter the pattern: ");
  while(1)
    {
    scanf("%c",&ch);
    if(ch!='\n')
      pattern[i++]=ch;
    else
      break;
    }pattern[i]='\0';
  int* shft=shift_generator(pattern);
  int res=horspool_matching(text,pattern,shft);
  if(res==-1)
    printf("The pattern was not found");
  else
    printf("The pattern was found at position %d",res);
  printf("\nNumber of comparisons performed : %d\n",comparision_count);
  free(shft);
  return 0; 
}
