#include <stdio.h>

int main(){
  int ch, i;
  int nchar[256];

  for (i = 0; i < 256; ++i){
    nchar[i] = 0;
  }

  while ((ch = getchar()) != EOF) {
    ++nchar[ch];
  }

  for (i = 32; i < 127; ++i){
    if (nchar[i] != 0){
      putchar(i);
      printf(":");
      for (int j = 0; j < nchar[i]; ++j){
        printf("-");
      }
      printf("\n");
    }
  }
}
