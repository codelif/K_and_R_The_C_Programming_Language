#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define PAGE_HEIGHT 20



void repeatchar(char c, int n){
  for (int i = 0; i < n; i++, putchar(c)); 
}

void page(char *filename){
  FILE *fp;
  int linecount = 1;
  unsigned charcount = 0;
  char c;

  static char s[1000];

  if ((fp = fopen(filename, "r")) == NULL){
    printf("error: unable to open file \"%s\"\n", filename);
    return;
  }
  
  repeatchar(' ', (WIDTH - strlen(filename))/2);
  printf("%s\n", filename);
  
  repeatchar('-', WIDTH);
  putchar('\n');
  while((c = getc(fp)) != EOF){
    if ((charcount++) % WIDTH == 0 || c == '\n'){
      charcount = 1;
      putchar('\n');
      if (linecount % PAGE_HEIGHT == 0){
        putchar('\n');
        sprintf(s, "%d", (linecount)/PAGE_HEIGHT);
        repeatchar(' ', (WIDTH - strlen(s))/2 );
        printf("%s\n", s);
        repeatchar('-', WIDTH);
        putchar('\n');
      }
      linecount++;
    }
    
    if (c != '\n')
    putchar(c);

  }

  sprintf(s, "%d", (linecount)/PAGE_HEIGHT+1);
  repeatchar(' ', (WIDTH - strlen(s))/2 );
  printf("%s\n\n", s);
  repeatchar('=', WIDTH);
  putchar('\n');
  fclose(fp);
}



int main(int argc, char **argv){
  if (argc == 1){
    printf("usage: %s file1 [file2 ...]\n", *argv);
    exit(1);
  }

  while (--argc > 0){
    page(*(++argv));
  }
}
