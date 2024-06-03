#include <stdio.h>

int lower(int c){
  return c + ('a' - 'A')*(c >= 'A' && c <= 'Z');
}

int main(){
  int c;
  while ((c = getchar()) != EOF)
    putchar(lower(c));
}


