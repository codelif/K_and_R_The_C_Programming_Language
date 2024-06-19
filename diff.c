#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_line(FILE* iop, char *s){
  char c;
  while ((c = getc(iop)) != EOF && c != '\n'){
    *s++ = c;
  }
  
  if (c == '\n'){
    *s++ = c;
  }
  *s = '\0';
  return c;
}

FILE *openf(const char *filename, const char *mode){
  FILE *fd = fopen(filename, mode);
  if (fd == NULL){
    printf("error: unable to open file \"%s\"\n", filename);
  }

  return fd;
}


int main(int argc, char **argv){
  char s1[1001];
  char s2[1001];
  int c1, c2;
  if (argc != 3){
      printf("usage: %s FILE1 FILE2\n", *argv);
      exit(1);
  }

  FILE *fd1 = openf(argv[1], "r");
  FILE *fd2 = openf(argv[2], "r");


  if (fd1 == NULL || fd2 == NULL){
    exit(1);
  }

  int line = 0;
  do {
    c1 = get_line(fd1, s1);
    c2 = get_line(fd2, s2);
    line++;
  }while (strcmp(s1, s2) == 0 && (c1 != EOF || c2 != EOF));

  if (c1 == EOF && c2 == EOF){
    printf("Both files are identical.\n");
  }else{
    printf("Files differ at line %d\n", line);
    if (c1 != EOF){
      printf("%s:\n%s\n", argv[1], s1);
    }else{
      printf("%s:\n", argv[1]);
      puts("// End of File");
    }

    if (c2 != EOF){
      printf("%s:\n%s\n", argv[2], s2);
    }else{
      printf("%s:\n", argv[2]);
      puts("// End of File");
    }
  }


  fclose(fd1);
  fclose(fd2);


}
