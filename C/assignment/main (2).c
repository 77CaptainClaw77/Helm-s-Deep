#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int day;
    int month;
    int year;
}date;
typedef struct{
    char name[20];
    char usn[10];
    int m[2];
    date dob;
}student;
void input(student s[],int n);
void grace(student s[],int n);
void display(student s[],int n);
int main()
{
  student s[10];
  int n;
  printf("Enter the number of students");
  scanf("%d",&n);
  input(s,n);
  printf("Student information before rewarding grace marks:-\n");
  display(s,n);
  grace(s,n);
    printf("Student information after rewarding grace marks:-\n");
    display(s,n);
return 0;

}
void input(student s[],int n){
    int i;
    printf("Enter the student details\n");
    for(i=0;i<n;i++){
        char junk=getchar();
        printf("Student %d:-\n",(i+1));
        printf("\nName:");
        gets(s[i].name);
        printf("\nUSN:");
        gets(s[i].usn);
        printf("\nDOB(in dd mm yy format):");
        scanf("%d %d %d",&s[i].dob.day,&s[i].dob.month,&s[i].dob.year);
        printf("\nMarks in subject 1:");
        scanf("%d",&s[i].m[0]);
        printf("\nMarks in subject 2:");
        scanf("%d",&s[i].m[1]);
    }
}
void grace(student s[],int n){
    int i;
    for(i=0;i<n;i++){
        s[i].m[1]+=10;
        if(s[i].m[1]>100){
            s[i].m[1]=100;
        }
    }
}
void display(student s[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nStudent %d",(i+1));
        printf("\nName:");
        puts(s[i].name);
        printf("\nUSN:");
        puts(s[i].usn);
        printf("\nDOB:%d-%d-%d",s[i].dob.day,s[i].dob.month,s[i].dob.year);
        printf("\nMarks in subject 1:%d",s[i].m[0]);
        printf("\nMarks in subject 1:%d\n",s[i].m[1]);
    }
}
