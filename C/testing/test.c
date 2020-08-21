#include <stdio.h>
int main(int argc, char *argv[])
{
     FILE* f;
  /* char s[]="To be or not to be"; */
  /* long i; */
     f=fopen("f","w");
  /* fwrite(f,2,1,f); */
  /* fclose(f); */
  /* f=fopen("f","r"); */
     fseek(f);
     
  /* fclose(f); */
  int i;
  i=fprintf(stderr,"hello");
  printf("%d",i==EOF);
  return 0;
   
        FILE *f; 
        f = fopen("file","wb"); 
        printf("%d",f != NULL); 
        fclose(f);
	fscanf("1%d",3);
        return 0; 
}

