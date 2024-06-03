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

unsigned setbits(unsigned x, int p, int n, unsigned y){
  return (x & ~(~(~0 << n) << (p+1-n))) | (y & ~(~0 << n)) << (p+1-n);
}

int main(){
  put_binary(setbits(92, 4, 3, 59));
}

