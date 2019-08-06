//TRY YOUR LUCK.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void timebar(int time){
    int i;
    int j;
    printf("PROCESSING");
    for(i=0;i<time;i++)
    {
        for(j=0;j<100000000;j++);
        printf(".");
           for(j=0;j<100000000;j++);
        printf(".");
           for(j=0;j<100000000;j++);
        printf(".");
           for(j=0;j<100000000;j++);
        printf(".");
        printf("\b\b\b\b");
    }
    printf("\n");
}
void main(){
    srand(time(NULL));
    int num;
    printf("Luck Finder\n");
    printf("Enter a number\n");
    scanf("%d",&num);
    timebar(5);
    int luck=((rand()*num)%100)+1;
    printf("\nYou are %d percent lucky today.",luck);
}

