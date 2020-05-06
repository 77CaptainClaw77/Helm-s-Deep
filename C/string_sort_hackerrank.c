#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a,b)>0?0:1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(a,b)>0?1:0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_count_a=0,distinct_count_b=0;
    int dist_a[126]={0};
    int dist_b[126]={0};
    int i;
    for(i=0;i<strlen(a);i++){
        if(dist_a[a[i]]==0){
            dist_a[a[i]]=1;
            distinct_count_a++;
        }
    }
    for(i=0;i<strlen(b);i++){
        if(dist_b[b[i]]==0){
            dist_b[b[i]]=1;
            distinct_count_b++;
        }
    }
    //printf("\n%s %s %d",a,b,distinct_count_a-distinct_count_b);
    if(distinct_count_a==distinct_count_b)
      return lexicographic_sort(a,b);
    return distinct_count_a>distinct_count_b?0:1;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a)!=strlen(b))
      return  strlen(a)>strlen(b)?0:1;
    return lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i,j;
    for(i=0;i<len-1;i++){
        int min_ind=i;
        for(j=i+1;j<len;j++){
            if(cmp_func(arr[j],arr[min_ind])){
                min_ind=j;
            }
        }
        if(min_ind!=i){
            int max_size=strlen(arr[min_ind])>strlen(arr[i])?strlen(arr[min_ind]):strlen(arr[i]);
            char* temp=arr[i];
            arr[i]=arr[min_ind];
            arr[min_ind]=temp;
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    printf("\nLexicographic Sort\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    printf("\nReverse Lexicographic Sort\n");
    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    printf("\nLengthwise Sort\n");
    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    printf("\nDistinct Character Sort\n");
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
