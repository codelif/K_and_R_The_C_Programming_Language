#include <stdio.h>
#define IN 1
#define OUT 0

int main(){
  int state, ch;

  state = OUT;

  while ((ch = getchar()) != EOF){
    if (ch == ' ' || ch == '\n' || ch == '\t'){
      if (state == IN){
        printf("\n");
      }
      state = OUT;
    }
    else {
      state = IN;
      putchar(ch);
    }
  }
}
