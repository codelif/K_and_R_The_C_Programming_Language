#include <stdio.h>


void filecopy(FILE *, FILE *);

int main(int argc, char **argv){
  FILE *fp;


  if (argc == 1)
    filecopy(stdin, stdout);
  else {
    while (--argc > 0){
      fp = fopen(*(++argv), "r");
      if (fp == NULL){
        printf("cat: cannot access file '%s'\n", *argv);
        continue;
      }
      filecopy(fp, stdout);
      fclose(fp);
    }
  }
}



void filecopy(FILE *from, FILE *to){
  int c;
  while ((c = getc(from)) != EOF)
    putc(c, to);
  
}
