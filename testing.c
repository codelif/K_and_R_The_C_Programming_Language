#include <stdio.h>

int main(){
  int a = 10;
  int b = 31;
  printf("%d %d\n", a, b);
  a ^= b;
  b ^= a;
  a ^= b;


  printf("%d %d\n", a, b);
}

