#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    unsigned int age,empid,sal;
    char dep[20];
    char name[20];
}employee;
char filename[20];
void getdata(FILE *fp,employee emp[],int n);
void fetchdata(FILE *fp,employee emp[],int n);
int searchbyname(FILE *fp,employee emp[],int n,int searchset[]);
int searchbydep(FILE *fp,employee emp[],int n,int searchset[]);
int searchbyage(FILE *fp,employee emp[],int n,int searchset[]);
int searchbyempid(FILE *fp,employee emp[],int n,int searchset[]);
int searchbysal(FILE *fp,employee emp[],int n,int searchset[]);
void displaydata(employee emp[],int n,int searchset[],int select);
int main(){
    int success;
    int n;
    int reqset[100];
    int k;
    for(k=0;k<100;k++)
        reqset[k]=-1;
    FILE *myfile=fopen("hello.txt","w");
    printf("\nEnter the number of records");
    scanf("%d",&n);
    employee emp[n];
    printf("\nProceed to enter the data");
    getdata(myfile,emp,n);
    fflush(stdin);
    printf("\nYour data has been successfully entered.If you have any queries press 1 else press any other key to end.");
    fclose(myfile);
    char nofurtherq=getchar();
    if(nofurtherq=='1')
        exit(0);
    int ch;
    printf("Enter the basis on which you want to search for a record");
    printf("1.Name\n2.Department\n3.Employee ID\n4.Age\n5.Salary\n");
    scanf("%d",&ch);
    myfile=fopen(filename,"r");
    fetchdata(myfile,emp,n);
    switch(ch){
    case 1:success=searchbyname(myfile,emp,n,reqset);
        break;
    case 2:success=searchbydep(myfile,emp,n,reqset);
        break;
    case 3:success=searchbyempid(myfile,emp,n,reqset);
        break;
    case 4:success=searchbyage(myfile,emp,n,reqset);
        break;
    case 5:success=searchbysal(myfile,emp,n,reqset);
        break;
    }
    if(success==0)
    {
        printf("No such records were found.");
    }
    else{
        displaydata(emp,n,reqset,ch);
    }
    fclose(myfile);
    return 0;
}
void getdata(FILE *fp,employee emp[],int n){
    int i;
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("\nRECORD %d:-",(i+1));
        printf("\nName:");
        gets(emp[i].name);
        printf("\nDepartment:");
        gets(emp[i].dep);
        printf("\nEmployee ID:");
        scanf("%d",&emp[i].empid);
        printf("\nAge:");
        scanf("%d",&emp[i].age);
        printf("\nSalary:");
        scanf("%d",&emp[i].sal);
    }
    for(i=0;i<n;i++){
        fprintf(fp,"%s %s %d %d %d ",emp[i].name,emp[i].dep,emp[i].empid,emp[i].age,emp[i].sal);
    }
}
int searchbyname(FILE *fp,employee emp[],int n,int searchset[]){
    printf("\nEnter the search name");
    char key[100];
    scanf("%s",key);
    int i;
    int k=0;
    for(i=0;i<n;i++){
        if(strcmp(emp[i].name,key)==0){
            searchset[k]=i;
            k++;
        }
    }
    if(k>0)
        return 1;
    else
        return 0;
}
int searchbydep(FILE *fp,employee emp[],int n,int searchset[]){
    printf("\nEnter the search department");
    char key[100];
    scanf("%s",key);
    int i;
    int k=0;
    for(i=0;i<n;i++){
        if(strcmp(emp[i].dep,key)==0){
            searchset[k]=i;
            k++;
        }
    }
    if(k>0)
        return 1;
    else
        return 0;
}
int searchbyempid(FILE *fp,employee emp[],int n,int searchset[]){
    printf("\nEnter the search id");
    int key;
    scanf("%d",&key);
    int i;
    int k=0;
    for(i=0;i<n;i++){
        if(emp[i].empid==key){
            searchset[k]=i;
            k++;
        }
    }
    if(k>0)
        return 1;
    else
        return 0;
}
int searchbyage(FILE *fp,employee emp[],int n,int searchset[]){
    printf("\nEnter the lower age margin");
    int lowkey,highkey;
    scanf("%d",&lowkey);
    printf("\nEnter the higher age margin");
    scanf("%d",&highkey);
    int i;
    int k=0;
    for(i=0;i<n;i++){
        if(emp[i].age>=lowkey && emp[i].age<=highkey){
            searchset[k]=i;
            k++;
        }
    }
    if(k>0)
        return 1;
    else
        return 0;
}
int searchbysal(FILE *fp,employee emp[],int n,int searchset[]){
    printf("\nEnter the lower salary margin");
    int lowkey,highkey;
    scanf("%d",&lowkey);
    printf("\nEnter the higher salary margin");
    scanf("%d",&highkey);
    int i;
    int k=0;
    for(i=0;i<n;i++){
        if(emp[i].sal>lowkey && emp[i].sal<highkey){
            searchset[k]=i;
            k++;
        }
    }
    if(k>0)
        return 1;
    else
        return 0;
}
void fetchdata(FILE *fp,employee emp[],int n){
    fread(&emp[0],sizeof(employee),n,fp);
}
void displaydata(employee emp[],int n,int searchset[],int select){
    int i,j;
    for(i=0;searchset[i]!=-1;i++){
        for(j=0;j<n;j++){
            if(searchset[i]==j){
                printf("\nName:%s\t Department:%s\t Age:%d\t Salary:%d\t Employee Id%d",emp[i].name,emp[i].dep,emp[i].age,emp[i].sal,emp[i].empid);
            }
        }
    }
}
