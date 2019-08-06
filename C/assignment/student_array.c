#include<stdio.h>
void input(char name[20][20],char usn[20][20],char date[20][10],int marks[20][2],int n);
void display(char name[20][20],char usn[20][20],char date[20][10],int marks[20][2],int n);
int main(){
    char name[20][20];
    char usn[20][20];
    char date[20][10];
    int marks[20][2];
    printf("Enter the number of students");
    int n;
    scanf("%d",&n);
    input(name,usn,date,marks,n);
    display(name,usn,date,marks,n);
    return 0;
}
void input(char name[20][20],char usn[20][20],char date[20][10],int marks[20][2],int n){
    int i;
    for(i=0;i<n;i++){
        char junk=getchar();
        printf("Student %d:-\n",(i+1));
        printf("\nName:");
        gets(&name[i][0]);
        printf("\nUSN:");
        gets(&usn[i][0]);
        printf("\nDOB(in dd mm yy format):");
        gets(&date[i][0]);
        printf("\nMarks in subject 1:");
        scanf("%d",&marks[i][0]);
        printf("\nMarks in subject 2:");
        scanf("%d",&marks[i][1]);
    }

}
void display(char name[20][20],char usn[20][20],char date[20][10],int marks[20][2],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nStudent %d",(i+1));
        printf("\nName:");
        puts(&name[i][0]);
        printf("\nUSN:");
        puts(&usn[i][0]);
        printf("\nDOB:");
        puts(&date[i][0]);
        printf("\nMarks in subject 1:%d",marks[i][0]);
        printf("\nMarks in subject 1:%d\n",marks[i][1]);
    }
}
