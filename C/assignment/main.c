#include <stdio.h>
#include <stdlib.h>
typedef struct{
 int day;
 int month;
 int year;
}date;
struct item{
    char name[20];
    int id;
    date d;
    float amount;
    float discount;
};
void display(struct item* it,int i,float sum,float total){
    FILE *records=fopen("Record.txt","r");
        fread(it,sizeof(struct item),i,records);
        int counter;
        for(counter=0;counter<i;counter++){
            printf("\nItem %d",(counter+1));
            printf("\nItem Name: %s",(it+counter)->name);
            printf("\nItem ID: %d",(it+counter)->id);
            printf("\nDate: %d/%d/%d",(it+counter)->d.day,(it+counter)->d.month,(it+counter)->d.year);
            printf("\nAmount: %f",(it+counter)->amount);
            printf("\nDiscount: %f",(it+counter)->discount);
        }
        printf("\nTotal sales:%.4f",sum);
        printf("\nTotal sales(after discount):%.4f",total);
        fclose(records);
}
float discount(struct item* it,int i,float sum){
    int counter;
    for(counter=0;counter<i;counter++){
        (it+counter)->discount=0.1*(it+counter)->amount;
        sum=sum-((it+counter)->discount);
    }
    return sum;
}
int main()
{
    int i=0,ch=0;
    float sum=0.0;
    int size=1;
    float total;
    struct item *it=(struct item*)malloc(sizeof(struct item)*size);
    do{
          printf("\nEnter the item name");
          scanf("%s",(it+i)->name);
          printf("Enter item id");
          scanf("%d",&(it+i)->id);
          printf("Enter the date in dd mm yy format");
          scanf("%d %d %d",&(it+i)->d.day,&(it+i)->d.month,&(it+i)->d.year);
          printf("Enter the amount");
          scanf("%f",&(it+i)->amount);
          //(it+i)->discount=0.1*((it+i)->amount);
          sum=sum+(it+i)->amount;
          i++;
          size++;
          printf("\nEnter 1 to exit. Enter anything else to continue");
          it=(struct item*)realloc(it,sizeof(struct item)*size);
          //printf("\nType 1 to add another item");
          scanf("%d",&ch);
          if(ch==1)
            break;
    }while(1);
    FILE *records=fopen("Record.txt","w");
    total=discount(it,i,sum);
    fwrite(it,sizeof(struct item),i,records);
    printf("Type y to view the records");
    char choice;
    fflush(stdin);
    scanf("%c",&choice);
    fclose(records);
    if(choice=='y')
        display(it,i,sum,total);
    free(it);
    return 0;
}
