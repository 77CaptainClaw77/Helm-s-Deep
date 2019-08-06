#include <stdio.h>
#include <stdlib.h>
void TOH(int disk,char from,char to,char aux){
	if(disk==1){
		printf("Move disk 1 from %c to %c peg\n",from,to);
		return;
	}
	TOH(disk-1,from,aux,to);
	printf("Move disk %d from %c to %c peg",disk,from,to);
	TOH(disk-1,aux,to,from);
}
void main(){
	int n;
	char from,to,aux;
	printf("Enter the number of disks");
	scanf("%d",&n);
	printf("Enter the from to and auxillary pegs");
	fflush(stdin);
	scanf("%c %c %c",&from,&to,&aux);
	TOH(n,from,to,aux);


}
