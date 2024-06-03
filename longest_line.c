#include <stdio.h>
#define MAXCHARS 10

int getline(char l[], int max);
void copy(char f[], char t[]);

int main(){
  int len, max;
  char line[MAXCHARS], longest[MAXCHARS];
  
  max = 0;
  while ((len = getline(line, MAXCHARS)) != 0){
    if (len > max){
      copy(line, longest);
      max = len;
    }
  } 
  
  if (max > 0){
    printf("%d:%s", max, longest);
  }
  return 0;

}


int getline(char line[], int max){

  int c, i;
  
  for (i = 0; ((c = getchar()) != EOF) && (c != '\n'); ++i){
    if (i < max-1)
      line[i] = c;
  }

  if (c == '\n' && i < max){
    line[i] = c;
    ++i;
  }
  if (i < max-1){
    line[i] = '\0';
  }else {
    line[max-1] = '\0';
  }

  return i;
}


void copy(char from[], char to[]){
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;

}
