#include <stdio.h>
#include <string.h>
#include "challoc.h"
#include "readlines.h"
#define MAXLINES 5000

char *lineptr[MAXLINES];

void swap(char *v[], int i, int j){
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  // *v[i] ^= *v[j];
  // *v[j] ^= *v[i];
  // *v[i] ^= *v[j];
}

void qsort(char *v[], int left, int right){
  int i, last;
  void swap (char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}


int main(){
  int len;

  if ((len = readlines(lineptr, MAXLINES)) >= 0){
    qsort(lineptr, 0, len-1);
    writelines(lineptr, len);
  }else{
    printf("error: input is too big to sort\n");
    return 1;
  }
  
  while (len--){
    chfree(*(lineptr+len));
  }
  return 0;
}







