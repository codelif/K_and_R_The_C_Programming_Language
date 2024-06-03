#include <stdio.h>
#define GET_BIT(x, i) (((x) >> (i)) & 1)
#define CHAR_BIT 8

void put_binary (unsigned int x)
{
    unsigned int max = sizeof x * CHAR_BIT;
    unsigned int i;

    for (i = 0u; i < max; i++)  
    {
        putchar ('0' + GET_BIT (x, max - i - 1u));
    }
}

unsigned invert(unsigned x, int p, int n){
  int mask = ~(~0 << n) << (p + 1 - n);
  return mask;
  return x ^ mask;
}

int btoi(char s[]){
  int i, v;


  for (v = i = 0; s[i] != '\0'; i++){
    v = v * 2 + (s[i] - '0');
  }
  return v;
}

int main(){
  int n = btoi("0110011");
  put_binary(invert(n, 4, 3));
}



