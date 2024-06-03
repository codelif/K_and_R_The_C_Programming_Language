#include <stdio.h>


int btoi(char s[]){
  int i, v;

  for (v = i = 0; s[i] != '\0'; i++){
    v = v * 2 + (s[i] - '0');
  }
  return v;
}
int bitcount(unsigned x){
  int i;
  for (i = 0; x > 0; i++)
    x &= (x-1);
  return i;
}

int main(){
  int n = btoi("0110111");
  printf("%d\n", bitcount(n)); 
}
