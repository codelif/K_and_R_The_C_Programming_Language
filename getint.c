#include <stdio.h>
#include <ctype.h>
#include "getch.h"


int getint(int *pn){
  char c;
  int sign;
  while ((c = getch()) == ' ' || c == '\t');
  
  sign = (c == '-')? -1: 1;
  if (c == '-' || c == '+')
    c = getch();
  
  if (!isdigit(c) && c != EOF){
    ungetch(c);
    return 0;
  }

  for (*pn = 0; isdigit(c); c = getch()){
    *pn = 10 * (*pn) + (c - '0'); 
  }

  *pn *= sign;
  return c;
}

int main(){
  int n;

  while (getint(&n) > 0){
    printf("%d\n", n*n);
  }
}
