#include <stdio.h>


int main(){
  char c;
  while ((c = getchar()) != EOF) {
    if (c >= 33 && c <= 126){
      putchar(c);
    }else{
      printf("0x%x", c);
    }
  }
}
