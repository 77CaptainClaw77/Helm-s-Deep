#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char name[10];
    char usn[10];
    int m1;
    int m2;
}student;
int main(){
    int n;
    student *ps=NULL;
    printf("Enter the number of students");
    scanf("%d",&n);
    ps= (student*)malloc(n*sizeof(student));
    if(ps==NULL){
        printf("No memory....");
        exit(0);
    }
    printf("Enter the student details");
    int i;
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("\nStudent %d",(i+1));
        printf("\nName:");
        gets((ps+i)->name);
        printf("\nUSN:");
        gets((ps+i)->usn);
        printf("\nMarks 1:");
        scanf("%d",&(ps+i)->m1);
        printf("\nMarks 2:");
        scanf("%d",&(ps+i)->m2);
    }
    printf("\nThe entered student details are:-\n");
    for(i=0;i<n;i++){
        printf("Student %d:-",(i+1));
        printf("\nName:%s",(ps+i)->name);
        printf("\nUSN: %s",(ps+i)->usn);
        printf("\nMarks 1: %d",(ps+i)->m1);
        printf("\nMarks 2:%d",(ps+i)->m2);
    }
    for(i=0;i<n;i++)
        free(ps+i);
    return 0;
    }
