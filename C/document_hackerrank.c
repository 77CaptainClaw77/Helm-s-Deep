#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}
int count_occurence(char* str,char ch,int start,int end){
  int occur=0,i=0;
  for(i=start;i<end;i++){
    if(str[i]==ch)
      occur++;
  }
  return occur;
}
char**** get_document(char* text) {
  strcat(text,"\n");
  int para_count=count_occurence(text,'\n',0,strlen(text));
  char**** document=malloc(sizeof(char***)*(para_count+1));
  int start_pos=0;
  int i;
  int p=0;
  for(i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
      int sent_count=count_occurence(text,'.',start_pos,i);
      document[p]=malloc(sizeof(char**)*(sent_count+1));
      int j,s;
      s=0;
      int sent_start=start_pos;
      for(j=start_pos;j<i;j++){
	if(text[j]=='.'){
	  int word_count=count_occurence(text,' ',sent_start,j);
	  document[p][s]=malloc(sizeof(char*)*(word_count+1));
	  int w=0;
	  int k;
	  int word_start=sent_start;
	  for(k=sent_start;k<j;k++){
	    if(text[k]==' '){
	      document[p][s][w]=malloc(sizeof(char)*(k-word_start+2));
	      int l=0;
	      for(l=word_start;l<k;l++){
		document[p][s][w][l-word_start]=text[l];
	      }
	      w++;
	      word_start=k+1;
	    }
	  }
	  document[p][s][w]=malloc(sizeof(char)*(k-word_start+2));
	  int m;
	  for(m=word_start;m<k;m++)
		document[p][s][w][m-word_start]=text[m];
	  word_start=m+1;
	  s++;
	  sent_start=j+1;
	  //also add word at end that is the word followed by .
	}
      }
      p++;
      start_pos=i+1;
    }
  }
  return document;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
