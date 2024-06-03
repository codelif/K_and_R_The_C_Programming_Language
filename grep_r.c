#include <stdio.h>
#include <string.h>
#define MAXBUFFER 1000

int get_line(char line[], int max){
  int i, c;
  for (i = 0; --max > 0 && (c = getchar()) != EOF && c != '\n'; ++i)
       line[i] = c;

  if (c == '\n')
    line[i++] = '\n';

  line[i] = '\0';
  return i;
}

int strrindex(char s[], char t[]){
  int i, j;
  for (i = strlen(s)-1; i >= 0; --i){
    for (j = 0; t[j] != '\0' && t[j] == s[i+j]; ++j);
    if (j > 0 && t[j] == '\0')
      return i;
  }
  return -1;
}

int main(){
  char t[] = "ould";
  char s[MAXBUFFER];
  int i;
  while (get_line(s, MAXBUFFER) > 0){
    i = strrindex(s, t);
    // if ((i = strrindex(s, t)) >= 0){
    printf("%d\n", i);
    // }
  }
}
