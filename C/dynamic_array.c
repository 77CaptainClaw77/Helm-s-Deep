#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int* arr_ptr;
  int size;
  int pointer;
}dynamic_array;
dynamic_array* get_new_dyna_arr(){
  dynamic_array* da=(dynamic_array*)malloc(sizeof(dynamic_array));;
  da->size=5;
  da->arr_ptr=(int*)malloc(sizeof(int)*da->size);
  da->pointer=0;
  return da;
}
void resize_dyna_arr(dynamic_array* dyna_arr){
  dyna_arr->size=(dyna_arr->size*2)+1;
  dyna_arr->arr_ptr=(int*)malloc(sizeof(int)*dyna_arr->size);
}
void insert_at_end(int ele,dynamic_array* dyna_arr){
  if(dyna_arr->pointer==dyna_arr->size)
    resize_dyna_arr(dyna_arr);
  dyna_arr->arr_ptr[dyna_arr->pointer++]=ele;
}
int main(int argc,char* argv[]){
  int ele;
  dynamic_array* dr=get_new_dyna_arr();
  while(1){
    scanf("%d",&ele);
    if(ele!=-1)
      insert_at_end(ele,dr);
    else
      break;
  }
  for(ele=0;ele<dr->pointer;ele++){
    printf("%d\t",dr->arr_ptr[ele]);
  }
  return 0;
}
