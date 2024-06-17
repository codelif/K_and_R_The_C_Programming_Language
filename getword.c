#include <stdio.h>
#include <ctype.h>
#include "getch.h"


void lower(char *c){
  if (*c >= 'A' && *c <= 'Z'){
    *c = *c + 'a' - 'A';
  }
}


char getword(char *word, int lim){
  int c;
  char *w = word;

  while (isspace(c = getch()));
    
  if (c != EOF){
    *w++ = c;
  }

  if (!isalpha(c)){
    *w = '\0';
    return c;
  }

  for (lower(w-1); --lim > 0; w++){
    if (!isalnum(*w = getch())){
      ungetch(*w);
      break;
    }
    lower(w);
  }

  *w = '\0';
  return *word;
}

