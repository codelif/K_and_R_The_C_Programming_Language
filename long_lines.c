#include <stdio.h>
#define BUFFERLEN 15

int main(){
  int len;
  char line[BUFFERLEN];
  
  while ((len = getline(line, BUFFERLEN)) != 0){
    if (len > 30){ 
      printf("%d:%s", len,line);
    } 
  }

}

int getline(char line[], int max){
  int bi, li, ch;

  for (bi=0, li=0; ((ch = getchar())!= EOF) && ch != '\n'; ++li){
    if (bi < max-1){
      line[bi] = ch;
      ++bi;
    }
  }

  if (ch == '\n'){
    line[bi] = '\n';
    ++bi;
    ++li;
  }

  line[bi] = '\0';
  return li;
}
