#include <stdio.h>


void strncpy(char *s, char *t, int n){
  while ((*s++ = *t++) && --n);
  if (!n)
    *s = '\0';
}

void strncat(char *s, char *t, int n){
  while (*s){
    s++;
  }
  strncpy(s, t, n);
}

int strncmp(char *s, char *t, int n){
  for (; (*s == *t && --n); s++, t++){
    if (!*s){
      return 0;
    }
  }
  return *s - *t;
}

int main(){
  char t[] = "This is harsh sharma.";
  char s[100] = "This is harsh sharma. ";

  printf("%d\n", strncmp(s, t, 50));
}
