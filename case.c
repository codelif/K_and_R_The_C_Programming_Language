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

char lowered(char c){
  if (c >= 'A' && c <= 'Z')
    c = c + 'a' - 'A';
  return c;
}

char upped(char c){
  if (c >= 'a' && c <= 'z')
    c = c + 'A' - 'a';
  return c;
}

int main(int argc, char **argv){
  char *mcase = basename(*argv);
  char (*case_func)(char) = &lowered;

  if (strcmp(mcase, "lower") == 0){
    case_func = lowered;
  }else if (strcmp(mcase, "upper") == 0){
    case_func = upped;
  }else {
    printf("invalid calling name: '%s'\nrename/symlink to 'lower' or 'upper'\n", mcase);
    return 1;
  }
  
  char c;
  while ((c = getchar()) != EOF){
    putchar((*case_func)(c));
  }


  return 0;
}
