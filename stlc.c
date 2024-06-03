#include <stdio.h>


int main(){
  int ch, ntabs, nblanks, nlines;

  ntabs = nblanks = nlines = 0;

  while ((ch = getchar()) != EOF){
    if (ch == ' ') {
      ++nblanks;
    }else if (ch == '\t') {
      ++ntabs;
    }else if (ch == '\n') {
      ++nlines;
    }else;
  }

  printf("Spaces: %d\n", nblanks);
  printf("Tabs: %d\n", ntabs);
  printf("Lines: %d\n", nlines);
}
