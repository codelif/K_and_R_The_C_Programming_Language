#include <stdio.h>
int get_line(char *s, int max){
  int i, c;
  for (i = 0; i < max-1 && (c=getchar()) != '\0' && c != '\n'; i++){
    s[i] = c;
  }
  if (c == '\n')
    s[i++] = '\n';

  s[i] = '\0';
  return i;
}

int main(){
  char s[1000];
  int len;

  len = get_line(s, 1000);
  printf("%d", len);
}
