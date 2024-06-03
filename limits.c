#include <stdio.h>

int main(){
  int a = 1;
  int prev = 0;
  while (prev < a){
    prev = a++;
  }
  printf("%u\n", prev);

}
