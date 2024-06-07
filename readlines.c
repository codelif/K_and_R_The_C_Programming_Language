#include <stdio.h>
#include <string.h>
#include "challoc.h"
#define MAXLEN 1000

int get_line(char *s, int nchars){
  int i, c;
  for (i = 0; ((c=getchar()) != EOF) && c != '\n' && i < nchars-1; ++i){
    s[i] = c;
  }

  if (c == '\n')
    s[i++] = '\n';

  s[i] = '\0';
  return i;
}

// void strcpy(char *s, char *t){
//   while (*s++ = *t++);
// }

int readlines(char* lineptr[], int maxlines){
  int nlines, len;
  char *p, line[MAXLEN];
  

  for (nlines=0; (len = get_line(line, MAXLEN)) > 0;){
    if (nlines >= maxlines || (p = challoc(len)) == NULL)
      return -1;
    
    line[len-1] = '\0';
    strcpy(p, line);
    lineptr[nlines++] = p;
  }
  
  return nlines;
}


void writelines(char *lineptr[], int nlines){
  while (nlines-- && printf("%s\n", *lineptr++));
}
