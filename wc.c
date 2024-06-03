#include <stdio.h>
#define IN 1
#define OUT 0

int main(){
  int c, state, wc;
  state = OUT;
  wc = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n'){
      state = OUT;
    }else if (state == OUT){
      wc++;
      state = IN;
    }
  }

  printf("%d\n", wc);
}
