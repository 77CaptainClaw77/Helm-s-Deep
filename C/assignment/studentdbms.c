#include <stdio.h>
#include <stdlib.h>
#define FILERR if(myfile==NULL){\
        printf("Error in opening or creating a new file");\
        exit(5);\
    }
#define MEMERR if(st==NULL){\
        printf("Error in memory allocation");\
        exit(6);\
    }
struct date{
    int day;
    int month;
    int year;
};
struct student{
    char name[20];
    char usn[10];
    float cgpa;
    struct date dob;
};
int main(){
    int n,i;
    char endcode;
    printf("Enter the number of students");
    scanf("%d",&n);
    i=0;
    FILE *myfile=NULL;
    struct student *st=NULL;
    st=malloc(n*sizeof(struct student));
    MEMERR;
    myfile=fopen("Student_Database.txt","w");
    FILERR;
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("\nEnter the details of student %d",(i+1));
        printf("\nName:");
        scanf("%s",(st+i)->name);
        printf("\nUSN:");
        scanf("%s",(st+i)->usn);
        printf("\nDate Of Birth(In dd mm yy format)");
        scanf("%d %d %d",&(st+i)->dob.day,&(st+i)->dob.month,&(st+i)->dob.year);
        printf("\nCGPA:");
        scanf("%f",&(st+i)->cgpa);
        fprintf(myfile,"%s %s %d %d %d %f ",(st+i)->name,(st+i)->usn,(st+i)->dob.day,(st+i)->dob.month,(st+i)->dob.year,(st+i)->cgpa);
    }
    fclose(myfile);
    fflush(stdin);
    printf("To view the database press v, press any other button to end the program");
    scanf("%c",&endcode);
    if(endcode!='v'){
        exit(0);
    }
  myfile=fopen("Student_Database.txt","r");
    FILERR;
    i=0;
    while(fscanf(myfile,"%s %s %d %d %d %f",(st+i)->name,(st+i)->usn,&(st+i)->dob.day,&(st+i)->dob.month,&(st+i)->dob.year,&(st+i)->cgpa)!=EOF){
        fflush(stdin);
        printf("\nStudent %d",(i+1));
        printf("\nName:%s",(st+i)->name);
        printf("\nUSN:%s",(st+i)->usn);
        printf("\nDate Of Birth(In dd mm yy format):%d-%d-%d",(st+i)->dob.day,(st+i)->dob.month,(st+i)->dob.year);
        printf("\nCGPA:%.2f",(st+i)->cgpa);
        i++;
        printf("\n");
    }
    fflush(stdin);
    fclose(myfile);
    printf("\nIf you wish to view the database in a tabular format press t.Press any other button to exit");
    scanf("%c",&endcode);
    if(endcode=='t'){
        printf("\nName        USN           DOB           CGPA");//12
        i=0;
        myfile=fopen("Student_Database.txt","r");
        printf("\n");
    while(fscanf(myfile,"%s %s %d %d %d %f",(st+i)->name,(st+i)->usn,&(st+i)->dob.day,&(st+i)->dob.month,&(st+i)->dob.year,&(st+i)->cgpa)!=EOF){
        fflush(stdin);
        printf("%-11s ",(st+i)->name);
        printf("%-11s  ",(st+i)->usn);
        printf("%2d/%2d/%4d    ",(st+i)->dob.day,(st+i)->dob.month,(st+i)->dob.year);
        printf("%-.2f",(st+i)->cgpa);
        i++;
        printf("\n");
    }
        fclose(myfile);
    }

    return 0;
}
