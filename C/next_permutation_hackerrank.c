#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    int i;
	int k=-1;
    for(i=0;i<n-1;i++){
        if(strcmp(s[i], s[i+1])<0)
            k=i;
    }
    if(k==-1)
        return 0; //no more permutations!
    int l=k+1;
    for(i=k+1;i<n;i++){
        if(strcmp(s[k],s[i])<0)
            l=i;
    }
    char* temp=malloc(sizeof(char)*11);
    strcpy(temp, s[k]);
    strcpy(s[k], s[l]);
    strcpy(s[l], temp);
    int rev_start=k+1;
    for(i=rev_start;i<(rev_start+(n-rev_start)/2);i++){
      char* temp_str=malloc(sizeof(char)*11);
      int swap_ind=n-1-(i-rev_start);
        strcpy(temp_str, s[swap_ind]);
        strcpy(s[swap_ind], s[i]);
        strcpy(s[i], temp_str);
    }
    return 1;
}   

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
