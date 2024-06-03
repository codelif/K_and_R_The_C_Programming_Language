#include <stdio.h>
#define MAXBUFFER 1000

int main(){
  int len;
  char line[MAXBUFFER];

  while ((len = getline(line)) != 0){
    len = stripline(line, len);
    if (len > 0){
      printf("%s\n", line);
    }
  }
}

int stripline(char line[], int len){
  int i;

  for (i=len-1; is_strippable(line[i]); --i);
  ++i;

  line[i] = '\0';
  return i;
}

int is_strippable(int ch){
  switch (ch){
    case '\n':
    case ' ':
    case '\t':
      return 1;
  }
  return 0;
}

int getline(char line[]){
  int i, ch;
  for (i = 0; ((ch = getchar()) != EOF) && ch != '\n'; ++i){
    line[i] = ch;
  }
  if (ch == '\n'){
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}
