#include <stdio.h>

int atoi(char s[]){
  int n = 0;
  for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
    n = 10*n+(s[i]-'0');
  }
  return n;
}


int main(){
  char s[3];
  s[0] = '1';
  s[1] = '0';
  s[2] = '2';
   
  printf("%d\n", atoi("1023543423"));
}
