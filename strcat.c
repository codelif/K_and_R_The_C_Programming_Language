#include <stdio.h>
#define BUFFER 100

void mstrcat(char *s, char *t){
  while(*s++);
  *--s;
  while(*s++ = *t++);
}


int main(){
  char s[BUFFER] = "This is harsh sharma. ";
  char t[BUFFER] = "I am learning C.";
  
  mstrcat(s, t);
  printf("%s\n", s);

}
