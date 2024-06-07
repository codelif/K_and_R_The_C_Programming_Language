#include <stdio.h>
#include <string.h>


int mstrend(char *s, char *t){
  s += strlen(s) - strlen(t);

  while (*s && (*s++ == *t++));
  
  return !*s;
}


int main(){
  char s[] = "This is harsh sharma";
  char t[] = "sharma";
  char f[] = "harsh";

  printf("%d %d\n", mstrend(s, t), mstrend(s, f));
}
