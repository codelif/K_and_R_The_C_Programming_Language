#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <stdlib.h>
#include "readlines.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int mstrcmp(char *s, char *t){
  for (; *s == *t; s++, t++){
    if (!*s){
      return 0;
    }
  }
  return *s - *t;
}

void lower(char *s){
  while (*s){
    if (*s >= 'A' && *s <= 'Z'){
        *s = *s + 'a' - 'A';
  
    }
    s++;
  }
}

int numeric, reverse, fold;

int main(int argc, char *argv[]){
  int nlines;
  numeric = 0, reverse = 0;
  int c;
  
  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c){
        case 'r':
          reverse = 1;
          break;
        case 'n':
          numeric = 1;
          break;
        case 'f':
          fold = 1;
          break;
        default:
          printf("sort: illegal option '-%c'\n", c);
          argc = -1;
          break;
      }
  
  if (argc != 0){
    printf("Usage: sort [-rn]\n");
    return 1;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
    if (fold)
      for (int i = 0; i < nlines; i++)
        lower(lineptr[i]);
    qsort((void **) lineptr, 0, nlines-1,
          (int (*) (void*, void*)) (numeric ? numcmp : mstrcmp));
    writelines(lineptr, nlines);
    return 0;
  }else {
    printf("input too big to sort\n");
    return 1;
  }
}

double atof(char s[]){
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); ++i);
  
  sign = (s[i] == '-') ? -1: 1;
  
  if (s[i] == '+' || s[i] == '-')
    ++i;

  for (val = 0.0; isdigit(s[i]); ++i)
    val = val * 10.0 + (s[i] - '0');
  
  if (s[i] == '.')
    i++;

  for(power = 1.0; isdigit(s[i]); ++i){
    val = val*10.0 + (s[i]-'0');
    power *= 10.0;
  }

  return sign*val/power;
}

int numcmp(char *s1, char *s2){
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
      return -1;
  else if (v1 > v2)
      return 1;
  else
      return 0;
}


void swap(void *v[], int i, int j){
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  // *v[i] ^= *v[j];
  // *v[j] ^= *v[i];
  // *v[i] ^= *v[j];
}

void qsort(void *v[], int left, int right, 
           int (*comp)(void *, void *) ){
  int i, last, comparison;
  void swap (void *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++){
    comparison = (*comp)(v[i], v[left]) < 0;
    if (reverse)
      comparison = !comparison;

    if (comparison)
      swap(v, ++last, i);
  }

  swap(v, left, last);
  qsort(v, left, last-1, comp);
  qsort(v, last+1, right, comp);
}

