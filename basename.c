#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *basename(char *name){
  int len = strlen(name);
  int leading = 0;
  int i;

  for (i = len-1; i >= 0; i--){
    if (name[i] == '/' && i == len-1){
      leading = 1;
      continue;
    }

    if (name[i] == '/'){
      break;
    }
  }
  
  int n = len-i-leading;

  char *base = (char *) malloc(n*sizeof(char));

  strncpy(base, name+i+1, n-1);
  base[n] = '\0';
  return base;
}


int main(int argc, char **argv){
  if (argc >= 2)
    printf("%s\n", basename(*(argv+1)));
  else {
    printf("%s: missing operand\n", basename(*argv));
    return 1;
  }

  return 0;
}
