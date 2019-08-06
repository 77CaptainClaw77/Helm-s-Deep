#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_ERR if(myfile==NULL){\
printf("Error in opening the file");\
}
typedef struct{
    int emp_id;
    int salary;
    char name[25];
    char department[25];
    int age;
}Employee;
void filewriter(Employee e[],int n);
void filereader(Employee e[],int n);
void searchbyname(Employee e[],int n);
void searchbydep(Employee e[],int n);
void searchbyempid(Employee e[],int n);
void searchbyage(Employee e[],int n);
void searchbysal(Employee e[],int n);
void display(Employee e[],int n);
void displayrecord(int n,int i);
int main()
{
    int n,i;
    printf("Enter th number of records");
    while(1){
        scanf("%d",&n);
        if(n>=5)
            break;
        else
            printf("\nPlease enter atleast 5 records");
    }
    Employee e[n];
    for(i=0;i<n;i++){
        printf("\nEmployee %d",(i+1));
        fflush(stdin);
        printf("\nEnter the employee name");
        gets(e[i].name);
        printf("\nEnter the employee department");
        gets(e[i].department);
        printf("\nEnter the age");
        scanf("%d",&e[i].age);
        printf("\nEnter the salary");
        scanf("%d",&e[i].salary);
        printf("\nEnter the employee id");
        scanf("%d",&e[i].emp_id);

    }
    filewriter(e,n);
    printf("Enter the search criteria.By default, all records aare displayed");
    printf("\n1.Name");
    printf("\n2.Department");
    printf("\n3.Employee ID");
    printf("\n4.Age");
    printf("\n5.Salary");
    int ch;
    scanf("%d",&ch);
    switch(ch){
    case 1:searchbyname(e,n);
    break;
    case 2:searchbydep(e,n);
    break;
    case 3:searchbyempid(e,n);
    break;
    case 4:searchbyage(e,n);
    break;
    case 5:searchbysal(e,n);
    break;
    default:printf("Option selected does not exist. Displaying all records:-\n");
    exit(0);
     }
    return 0;
}
void filewriter(Employee e[],int n){
    FILE *myfile=NULL;
    myfile=fopen("Database.txt","w");
    FILE_ERR;
    fwrite(&e[0],sizeof(Employee),n,myfile);
    fclose(myfile);
}
void filereader(Employee e[],int n){
    FILE *myfile=NULL;
    myfile=fopen("Database.txt","r");
    FILE_ERR;
    fread(&e[0],sizeof(Employee),n,myfile);
    fclose(myfile);
}
void display(Employee e[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nEmployee %d",(i+1));
        printf("\nEmployee name:%s",e[i].name);
        printf("\nEmployee department:%s",e[i].department);
        printf("\nEnter the age:%d",e[i].age);
        printf("\nEnter the salary:%d",e[i].salary);
        printf("\nEnter the employee id:%d",e[i].emp_id);
    }
}
void searchbyname(Employee e[],int n){
    fflush(stdin);
    printf("\nEnter the search string");
    char key[25];
    gets(key);
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(strcmp(key,e[i].name)==0){
            displayrecord(n,i);
            ++flag;;
            break;
        }
    }
    if(!flag)
        printf("Record not found");
}
void searchbydep(Employee e[],int n){
    printf("\nEnter the search string");
    char key[25];
    fflush(stdin);
    gets(key);
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(strcmp(key,e[i].department)==0){
            displayrecord(n,i);
            ++flag;;
            break;
        }
    }
    if(!flag)
        printf("Record not found");
}
void searchbysal(Employee e[],int n){
    printf("\nEnter the search salary");
    int key;
    scanf("%d",&key);
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(key==e[i].salary){
            displayrecord(n,i);
            ++flag;;
            break;
        }
    }
    if(!flag)
        printf("Record not found");
}
void searchbyempid(Employee e[],int n){
    printf("\nEnter the search id");
    int key;
    scanf("%d",&key);
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(key==e[i].emp_id){
            displayrecord(n,i);
            ++flag;
            break;
        }
}
    if(!flag)
        printf("Record not found");
}

void searchbyage(Employee e[],int n){
    printf("\nEnter the lower and upper age limit");
    int lowkey,highkey;
    scanf("%d %d",&lowkey,&highkey);
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(lowkey<=e[i].age && highkey>=e[i].age){
            displayrecord(n,i);
            ++flag;
        }
    }
    if(!flag)
        printf("Record not found");
}
void displayrecord(int n,int i){
        Employee e[n];
        filereader(e,n);
        printf("\nEmployee %d",(i+1));
        printf("\nEmployee name:%s",e[i].name);
        printf("\nEmployee department:%s",e[i].department);
        printf("\nEnter the age:%d",e[i].age);
        printf("\nEnter the salary:%d",e[i].salary);
        printf("\nEnter the employee id:%d",e[i].emp_id);
}
