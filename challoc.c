#include <stdio.h>
#define BUFSIZE 5000000

static char buf[BUFSIZE];
static char *bufp = buf;

char *challoc(int n){
  if (buf + BUFSIZE - bufp >= n){
    bufp += n;
    return bufp-n;
  }
  return 0;
}

void chfree(char *p){
  if (p <= bufp && p >= buf){
    bufp = p;
  }else{
    printf("error: reference to unmanaged memory\n");
  }
}
