#include <stdio.h>

int upper(int c){
  if (c >= 'a' && c <= 'z'){
    c = c + 'A' - 'a';
  }
  return c;
}

int main(){
  int c;
  while ((c = getchar()) != EOF)
    putchar(upper(c));
}


