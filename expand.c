#include <stdio.h>
#define MAXBUFFER 10000

int is_expandable(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int iterate_fill(char s[], int i, char from, char to){
  for (; from <= to; ++i)
    s[i] = from++;
  return i;
}

void expand(char s1[], char s2[]){
  int i, j;

  for (i = 0, j = 0; s1[i] != '\0'; ++i){
    if (s1[i] == '-' && is_expandable(s1[i-1]) && is_expandable(s1[i+1])){
      j = iterate_fill(s2, --j, s1[i-1], s1[i+1]);
      ++i;
    }else{
      s2[j++] = s1[i];
    }
  }
}


int getline(char s[], unsigned max){
  int i, c;
  for (i = 0; i < max-1 && (c = getchar())!= EOF && c != '\n'; ++i){
    s[i] = c;
  }
  if (c == '\n')
    s[i++] = '\n';

  s[i] = '\0';
  return i;
}

int main(){
  char line[MAXBUFFER];
  char expanded[MAXBUFFER];
  unsigned len;

  while ((len = getline(line, MAXBUFFER)) > 0)
    expand(line, expanded), printf("%s\n", expanded);
}
