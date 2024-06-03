#include <stdio.h>
#define IN 1
#define OUT 0

int main(){
  int ch, state, count;
  int nlength[45];
  
  for (int i = 0; i < 45; i++){
    nlength[i] =0;
  }
  
  state = OUT;
  count = 0;
  while ((ch = getchar()) != EOF) {
    if (ch == ' ' || ch == '\n' || ch == '\t'){
      state = OUT;
    }else if (state == OUT){
      ++nlength[count-1];
      state = IN;
      count = 1;
    }else if (state == IN){
      ++count;
    }
  }

  for (int i = 0; i < 45; i++) {
    if (nlength[i] != 0){
      printf("%2d:", i+1);
      for (int j = 0; j < nlength[i]; j++){
        printf("-");
        ;
      }

      printf("\n");
    }
  }
}
