#include <stdio.h>
#define BUFFERSIZE 10

static char buf[BUFFERSIZE];
static int bufp = 0; // pointer to next empty buffer index

int buffer_discard(void){
  for (int i = 0; i < BUFFERSIZE; ++i){
    buf[i] = buf[i+1];
  }
  bufp--;
  return 0;
}


char getch(void){
  return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(char c){
  while (bufp >= BUFFERSIZE){
    buffer_discard();
  }
  buf[bufp++] = c;
}

