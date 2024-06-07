#include <stdio.h>
#include <ctype.h>
#include "getch.h"


int getfloat(double *pf){
  char c;
  int sign;
  double power;

  while ((c = getch()) == ' ' || c == '\t');
  
  sign = (c == '-')? -1: 1;
  if (c == '-' || c == '+')
    c = getch();
  
  if (!isdigit(c) && c != EOF && c != '.'){
    ungetch(c);
    return 0;
  }

  for (*pf = 0.0; isdigit(c); c = getch()){
    *pf = 10 * (*pf) + (c - '0'); 
  }

  if (c == '.'){
    c = getch();
  }
  for (power = 1.0; isdigit(c); c = getch()){
    *pf = 10 * (*pf) + (c - '0');
    power *= 10;
  }
  
  *pf *= sign;
  *pf /= power;

  return c;
}

int main(){
  double n;

  while (getfloat(&n) > 0){
    printf("%f %f\n", n*n, n*n*n);
  }
}
