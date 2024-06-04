#include <stdio.h>
#define swap(t, x, y) { t tmp = x; x = y; y = tmp; }

int main(){
  int x = 20;
  int y = 40;
  printf("%d %d\n", x, y);
  swap(int, x, y)
  printf("%d %d\n", x, y);
  return 0;
}
