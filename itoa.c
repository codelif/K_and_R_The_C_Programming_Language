#include <stdio.h>

unsigned long strlen(const char s[]){
  unsigned long i;
  for (i = 0; s[i] != '\0'; ++i);
  return i;
}

void reverse(char s[]){
  char c;
  int i, j;
  for (i = 0, j = strlen(s)-1; i < j; ++i, --j)
    c = s[i], s[i] = s[j], s[j] = c;
}


void itob(int n, char s[], unsigned b){
  int i, sign;

  if ((sign = n) < 0){
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % b + '0';
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  

  s[i] = '\0';
  reverse(s);
}

int itoa(int n, char s[]){
  int i;

  if (n < 0){
    s[0] = '-';
    n = -n;
  }
  if (n / 10){
    i = itoa(n / 10, s);
  }else{
    i = (s[0] == '-')?1:0;
  }
  s[i++] = n % 10 + '0';
  return i;
}

// void itoa(int n, char s[]){
//   itob(n, s, 10);
// }

void itob_padded(int n, char s[], unsigned b, unsigned w){
  int i, sign;

  if ((sign = n) < 0){
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % b + '0';
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  
  for (; i < w; ++i)
    s[i] = ' ';

  s[i] = '\0';
  reverse(s);
}
int main(){
  char s[100];
  int i = 20;
  
  itoa(i, s);
  // itob_padded(i, s, 10, 4);
  printf("%s\n", s);
  itoa(40, s);
  printf("%s\n", s);
}

