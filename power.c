#include <stdio.h>

int power(int base, int n){
  int p;

  for (p=1; n > 0; --n){
    p = p * base;
  }
  return p;
}

int main(){
  for (int i = 1; i < 11; ++i){
    printf("%2d %4d %5d\n", i, power(2, i), power(3,i));
  }
  return 0;
}
