#include <stdio.h>
#define MAXBUFFER 1000

int main(){
  int len;
  char line[MAXBUFFER];

  while ((len = getline(line, MAXBUFFER))!= 0){
    reverseline(line, len);
    printf("%s", line);
  }

}

int reverseline(char line[], int len){
  char revline[len+1];
  int i;
  --len;
  for (i = len-1; i > -1; --i){
    revline[len - i -1] = line[i];
  }
  revline[len] = '\n';
  revline[len+1] = '\0';

  for (i = 0; i < len; ++i){
    line[i] = revline[i];
  }
   
  
}

int getline(char line[], int max){
  int i,ch;

  for (i = 0; (i<max-1) && (ch = getchar())!= EOF && ch != '\n'; ++i){
    line[i] = ch;
  }
  if (ch == '\n'){
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';
  return i;
}
