#include <stdio.h>
#include <limits.h>

int reverse(int x){
  long result = 0;

  do {
      result = result * 10 + (x % 10);
  }while ((x /= 10) != 0);
  if (result > INT_MAX || result < INT_MIN){
    return 0;
  }

  return (int) result;
}
int main(){
  int x = -2147483648;
  printf("%d\n", reverse(x));
}

